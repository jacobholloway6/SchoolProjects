import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;

public class TestWebService {

    public static void main(String[] args) {
        try {
            URL url = new URL("https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=nflx&apikey=0244");

            BufferedReader br = new BufferedReader(new InputStreamReader(url.openStream()));

            String sTemp = "";
            String sServiceReturnedJson = "";

            while(null != (sTemp = br.readLine())){

                sServiceReturnedJson += sTemp;

            }

            System.out.println("Return json -- " + sServiceReturnedJson);

        }catch(Exception ex){

            System.out.println("Error: " + ex.getMessage());

        }
    }
}
