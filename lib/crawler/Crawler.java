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
    final String ARTICLE_LIST_PATH = "tmp/article_list.txt";
    final String CRAWED_CONTENT_PATH = "tmp/crawed_content.txt";

    private List<String> articleList;        //可選文章title
    private List<String> articleUrlList;        //可選文章url
    private String baseUrl = "https://edition.cnn.com";
	
    private Document chosedDoc;        //被選中article's doc

    public Crawler() {
        articleList = new ArrayList<>();
        articleUrlList = new ArrayList<>();
    }

    public void clear(){
        articleList.clear();
        articleUrlList.clear();
    }

    public List<String> getArticleList() {
        return articleList;
    }

    // may be print out list
    public void setArticleList(String category) throws IOException{

        for(Element e:first_view(category)) {
            articleList.add(e.text());
        }

        String currentPath = java.nio.file.Paths.get("").toAbsolutePath().toString();

        File f = new File(currentPath + '/' + ARTICLE_LIST_PATH);

        f.delete();
        f.getParentFile().mkdirs();
        f.createNewFile();

        BufferedWriter bfw = new BufferedWriter(
                new OutputStreamWriter(new FileOutputStream(f)));

        for(String s:articleList) {
            bfw.write(s+"\n");
        }

        bfw.close();
    }

    public List<String> getArticleUrlList() {
        return articleUrlList;
    }

    public void setArticle_url_list(String category) throws IOException {
        for(Element e:first_view(category)) {
            concatenate(e.attr("href"));
        }
    }

    public String getBaseUrl() {
        return baseUrl;
    }

    public void setBaseUrl(String category) {
        baseUrl += category;
    }

    public Document getChosedDoc() {
        return chosedDoc;
    }

    public void setChosed_doc(String title) throws IOException {
        chosedDoc = Jsoup.connect(find_article_url(title)).get();
    }

    public void crawl_article() throws IOException{

        List<ArrayList<String>> crawled_content = new ArrayList<>();

        crawled_content.add(new ArrayList<>());
        crawled_content.get(0).add(getChosedDoc().select("h1.pg-headline").text());

        Elements e1 = chosedDoc.getElementsByClass("el__leafmedia el__leafmedia--sourced-paragraph");

        crawled_content.add(new ArrayList<>());
        crawled_content.get(1).add(e1.select("p").text());

        crawled_content.add(new ArrayList<>());
        for(Element p:getChosedDoc().select("div.zn-body__paragraph")) {
            crawled_content.get(2).add(p.text());
        }

        for(ArrayList<String> s: crawled_content) {
            for(String a:s) {
                System.out.println(a);
            }
        }

        String currentPath = java.nio.file.Paths.get("").toAbsolutePath().toString();

        File f = new File(currentPath + '/' + CRAWED_CONTENT_PATH);

        f.delete();
        f.getParentFile().mkdirs();
        f.createNewFile();

        BufferedWriter bfw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(f)));

        for(ArrayList<String> a:crawled_content) {
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
    public Elements first_view(String category) throws IOException{
        Document doc = Jsoup.connect(addCategory(category)).get();

        Elements e1 = doc.getElementsByClass("column zn__column--idx-0");
        Elements e2 = e1.first().select("a");

        return e2;
    }

    public void concatenate(String aurl) {
        articleUrlList.add(baseUrl+aurl);
    }

    public int choose_article(String title) {
        int index = 0;
        for(String s : articleList) {
            if(s.equals(title)) {
                index = articleList.indexOf(s);
                break;
            }
        }
        return index;
    }

    public String find_article_url(String title) {
        return getArticleUrlList().get(choose_article(title));
    }
}
