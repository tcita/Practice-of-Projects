package Crawler;

import java.io.IOException;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

public class Scrap_Some_Contant {
	
	public static void main(String[] a) {
		
		String url = "https://www.surreyschools.ca/Pages/default.aspx";
		
		try{
			Document doc = Jsoup.connect(url).get();
			//System.out.println(doc.title());
			//System.out.println(doc);
			
			/*
			 	Content we can 'get'
			 	The more 'general' ones:
			 	-> Tag (the things just inside the <>, such as <p> or <li>
			 	-> Attribute (special words that customize tag, such as "height","color","center"
			 	The more specific ones:
			 	-> Classes (organize content into major sections... looks like <tag class="className">
			 	-> ID's (unique labels for section of the HTML document... looks like <tag id="IDName">
			 */
		
		/*	
			// Get element by tag
			//Elements paragraphs = doc.getElementsByTag("li");
			
			//Get element by ID
			Element content = doc.getElementById("ctl00_SPWebPartManager1_g_c9e7e421_3d78_4415_9004_f0ff4c6f180a");
			//System.out.println(content);
			Elements contents = content.getElementsByTag("a");
			for(Element e: contents) {
				System.out.println(e.text());
			}
		*/
			
			
			// Get element by class
			Elements content = doc.getElementsByClass("hcf-rollup hcf-newsRollup");
			for(Element e: content) {
				System.out.println(e.text());
			}
			/*Elements subcontent = content.first().getElementsByTag("li");
			for(Element e: subcontent) {
				//System.out.println(e.text());
				System.out.println(e.getElementsByTag("a").text());
			}*/
			
			//for(Element e: paragraphs) {
				//System.out.println(e.text());
			//}
			
		}catch(IOException e) {
			System.out.println(e);
		}
		
	}
}
