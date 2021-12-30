import java.io.IOException;

public class ex {
	public static void main(String[] a) throws IOException {
		Scraper scr = Scraper.getScr();
		System.out.println("omg");	
		scr.setArticle_list("/africa");//a[0] cannot 
		scr.setArticle_url_list("/africa");//a[0]
		
		scr.setChosed_doc("Madagascar boat accident kills at least 64;"
				+ " minister swims to safety from helicopter crash at site");
		scr.crawl_article();


	}
}