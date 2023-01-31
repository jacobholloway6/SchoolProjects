public class testcase {

    public static void main(String[] args) {
        System.out.println("this is a test, brenna is gay");
        company oCompany1 = new company();
        company oCompany2 = new company();

        oCompany1.name = "Microsoft";
        oCompany2.name = "Apple";

        PublicCompany pubCompany = new PublicCompany();

        pubCompany.name = "Google";
        pubCompany.stockSymbol = "goog";

        PublicCompany[] aPubCo = new PublicCompany[3];
        aPubCo[0] = pubCompany;
        
    }
}
