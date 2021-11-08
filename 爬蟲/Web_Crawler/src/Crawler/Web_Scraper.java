package Crawler;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

public class Web_Scraper {
	private String url;
	
	Web_Scraper(String url){
		this.url = url;
	}
	
	public String geturl() {
		return url;
	}
	
	public String scrape() throws IOException{
		
		Document doc = Jsoup.connect(url).get();
		
		Elements paragraphs = doc.getElementsByClass("l-container");
		
		Element sub_paragraph = paragraphs.get(1);
		
		Elements contents =  sub_paragraph.select("div.zn-body__paragraph, p");
		
		String crawed_content = "";
		
		String headTitile = doc.select("h1.pg-headline").text();
		
		crawed_content += headTitile;
		
		for(Element p:contents) {
						
			crawed_content+=p.text();
		}
		
		File f = new File("c:/javaio/c.txt");
		
		f.createNewFile();
		
		BufferedWriter bfw = new BufferedWriter(
				new OutputStreamWriter(new FileOutputStream(f)));
		
		bfw.write(crawed_content);
		
		bfw.close();
		
		return crawed_content;
	}
}
