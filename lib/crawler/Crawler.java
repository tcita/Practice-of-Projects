import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

public class Crawler {
	private final String ARTICLE_LIST_PATH = "tmp/article_list.txt";
    private final String CRAWED_CONTENT_PATH = "tmp/crawed_content.txt";
	
    private String baseUrl = "https://edition.cnn.com";
    // choosable article title
	private List<String> articleList = new ArrayList<>();
	// choosable article url
    private List<String> articleUrlList = new ArrayList<>();
	// chosen article's doc
    private Document chosenDoc;
	
    public void clear() {
        articleList.clear();
        articleUrlList.clear();
    }

    public List<String> getArticleList() {
        return articleList;
    }

    // may be print out list
    public void setArticleList(String category) throws IOException{
        for(Element e : firstView(category)) {
            articleList.add(e.text());
        }

        String currentPath = java.nio.file.Paths.get("").toAbsolutePath().toString();

        File f = new File(currentPath + '/' + ARTICLE_LIST_PATH);

        f.delete();
        f.getParentFile().mkdirs();
        f.createNewFile();

        BufferedWriter bfw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(f)));

        for(String s : articleList) {
            bfw.write(s + "\n");
        }

        bfw.close();
    }

    public List<String> getArticleUrlList() {
        return articleUrlList;
    }

    public void setArticleUrlList(String category) throws IOException {
        for(Element e : firstView(category)) {
            concatenate(e.attr("href"));
        }
    }

    public String getBaseUrl() {
        return baseUrl;
    }

    public void setBaseUrl(String category) {
        baseUrl += category;
    }

    public Document getChosenDoc() {
        return chosenDoc;
    }

    public void setChosenDoc(String title) throws IOException {
        chosenDoc = Jsoup.connect(findArticleUrl(title)).get();
    }

    public void crawlArticle() throws IOException{
        List<ArrayList<String>> crawledContent = new ArrayList<>();

        crawledContent.add(new ArrayList<>());
        crawledContent.get(0).add(getChosenDoc().select("h1.pg-headline").text());

        Elements e1 = chosenDoc.getElementsByClass("el__leafmedia el__leafmedia--sourced-paragraph");

        crawledContent.add(new ArrayList<>());
        crawledContent.get(1).add(e1.select("p").text());

        crawledContent.add(new ArrayList<>());
        for(Element p:getChosenDoc().select("div.zn-body__paragraph")) {
            crawledContent.get(2).add(p.text());
        }

        for(ArrayList<String> s: crawledContent) {
            for(String a : s) {
                System.out.println(a);
            }
        }

        String currentPath = java.nio.file.Paths.get("").toAbsolutePath().toString();

        File f = new File(currentPath + '/' + CRAWED_CONTENT_PATH);

        f.delete();
        f.getParentFile().mkdirs();
        f.createNewFile();

        BufferedWriter bfw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(f)));

        for(ArrayList<String> a : crawledContent) {
            for(String s:a) {
                bfw.write(s+"\n");
            }
        }

        bfw.close();
    }

    // url後建doc then crawl article title
    public String addCategory(String category) {
        return baseUrl + category;
    }

    // first call
    public Elements firstView(String category) throws IOException {
        Document doc = Jsoup.connect(addCategory(category)).get();

        Elements e1 = doc.getElementsByClass("column zn__column--idx-0");
        Elements e2 = e1.first().select("a");

        return e2;
    }

    public void concatenate(String aurl) {
        articleUrlList.add(baseUrl + aurl);
    }

    public int chooseArticle(String title) {
        int index = 0;
        for(String s : articleList) {
            if(s.equals(title)) {
                index = articleList.indexOf(s);
                break;
            }
        }
        return index;
    }

    public String findArticleUrl(String title) {
        return getArticleUrlList().get(chooseArticle(title));
    }
}
