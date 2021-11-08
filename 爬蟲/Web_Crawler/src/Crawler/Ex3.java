package Crawler;

import java.io.IOException;

public class Ex3 {

	public static void main(String[] args) throws IOException{
		Web_Scraper wb = new Web_Scraper(
				"https://edition.cnn.com/2021/11/06/australia/australia-koala-chlamydia-intl-dst-hnk/index.html");
		wb.scrape();
	}

}
