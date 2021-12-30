package Crawler;

import java.io.IOException;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

public class test_1 {

	public static void main(String[] args) {
		
		String url = "https://edition.cnn.com/2021/10/26/world/exoplanet-intl-scli-scn/index.html";
		
		try{
			Document doc = Jsoup.connect(url).get();
			
			Elements con = doc.getElementsByClass("l-container");
			
			for(Element e: con) {
				System.out.println(e.text());
			}
			
		}catch(IOException e) {
			System.out.println(e);
		}

	}

}
