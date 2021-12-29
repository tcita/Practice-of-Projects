import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

public class Scraper {
	private List<String> article_list;		//可選文章title
	private List<String> article_url_list;		//可選文章url
	private String base_url = "https://edition.cnn.com";
	private Document chosed_doc;		//被選中article's doc
	private static Scraper scr = new Scraper();
		
	private Scraper(){
		article_list = new ArrayList<>();
		article_url_list = new ArrayList<>();
	}


	public List<String> getArticle_list() {
		return article_list;
	}
	
//	may be print out list
	public void setArticle_list(String category) throws IOException{		
		for(Element e:first_view(category)) {
			article_list.add(e.text());
		}

		// System.out.println("Success");

		for(String s:article_list){
			System.out.println(s);
		}
	}

	public List<String> getArticle_url_list() {
		return article_url_list;
	}
	
	public void setArticle_url_list(String category) throws IOException{
		for(Element e:first_view(category)) {
			concatenate(e.attr("href"));
		}
		// System.out.println("DONE");
	}

	public String getBase_url() {
		return base_url;
	}

	public void setBase_url(String category) {
		base_url += category;
	}

	public Document getChosed_doc() {
		return chosed_doc;
	}

	public void setChosed_doc(String title) throws IOException {
		chosed_doc = Jsoup.connect(find_article_url(title)).get();
	}
	
	public void crawl_article() throws IOException{
//		String crawed_content = "";
		List<ArrayList<String>> crawed_content = new ArrayList<>();
		
//		crawed_content += getChosed_doc().select("h1.pg-headline").text();
		crawed_content.add(new ArrayList<>());
		crawed_content.get(0).add(getChosed_doc().select("h1.pg-headline").text());
		
		Elements e1 = chosed_doc.getElementsByClass(
				"el__leafmedia el__leafmedia--sourced-paragraph");
		
//		crawed_content += e1.select("p").text();
		crawed_content.add(new ArrayList<>());
		crawed_content.get(1).add(e1.select("p").text());
		
		crawed_content.add(new ArrayList<>());
		for(Element p:getChosed_doc().select("div.zn-body__paragraph")) {
//			crawed_content += p.text();
			crawed_content.get(2).add(p.text());
		}
		
		File f = new File("c:/javaio/crawed_content.txt");
		
		f.createNewFile();
			
		BufferedWriter bfw = new BufferedWriter(
				new OutputStreamWriter(new FileOutputStream(f)));
			
		for(ArrayList<String> a:crawed_content) {
			for(String s:a) {
				bfw.write(s);
			}
		}
		
		bfw.close();
	}

	public static Scraper getScr() {
		return scr;
	}
	
//	url後建doc then crawl article title
	public String addCategory(String category) {
		return base_url + category;
	}
	
//	first call
	public Elements first_view(String category) throws IOException{
		Document doc = Jsoup.connect(addCategory(category)).get();
		
		Elements e1 = doc.getElementsByClass("column zn__column--idx-0");
		Elements e2 = e1.first().select("a");
		
		return e2;
	}
	
	public void concatenate(String aurl) {
		article_url_list.add(base_url+aurl);		
	}
	
	public int choose_article(String title) {
		int index = 0;
		for(String s:article_list) {
			if(s.equals(title)) {
				index = article_list.indexOf(s);
				break;
			}
		}
		return index;
	}
	
	public String find_article_url(String title) {
		return getArticle_url_list().get(choose_article(title));
	}
}
