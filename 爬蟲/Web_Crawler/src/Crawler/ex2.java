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

public class ex2 {
	public static void main(String[] a) {
		String url = "https://edition.cnn.com/2021/11/06/australia/australia-koala-chlamydia-intl-dst-hnk/index.html";
		
		try {
			Document doc = Jsoup.connect(url).get();
			
//			System.out.println(doc.outerHtml());
			
			Elements paragraphs = doc.getElementsByClass("l-container");
			
			Element sub_paragraph = paragraphs.get(1);
			
//			System.out.println(sub_paragraph/*.getElementsByTag("p")*/);
			
//			Elements div = sub_paragraph.select("div");
			
			/*for(Element e: div) {
				System.out.println(e);
			}*/
								
			Elements contents =  sub_paragraph.select("div.zn-body__paragraph, "
					+ "p");
			
//			System.out.println(contents);
			
			String crawed_content = "";
			
			for(Element p:contents) {
				
				System.out.println(p.text());
				
				crawed_content+=p.text();
			}
			
			File f = new File("c:/javaio/.txt");
			
			f.createNewFile();
			
			BufferedWriter bfw = new BufferedWriter(
					new OutputStreamWriter(new FileOutputStream(f)));
			
			bfw.write(crawed_content);
			
			bfw.close();
		}
		catch(IOException e) {
			
		}
	}
}
