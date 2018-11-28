import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   

   public void testManualTest()
   {
	   System.out.println("***BEGIN MANUAL TEST CASES***");
	   
	   //Instantiate new URL Validator
	   UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //Create Manual Valid Test Cases Using Test Class
	   Test[] ValidManualTestCases = 
		   {
				   new Test("http://www.google.com", true),
				   new Test("https://www.google.com", true),
				   new Test("http://go.com:80/test1?action=view", true),
				   new Test("https://stackoverflow.com/questions/26971315/what-is-reason-for-yellow-exclamation-mark-in-eclipse-java-projectpackage", true),
				   new Test("https://www.cnn.com/2018/11/27/tech/facebook-hearing-damian-collins/index.html", true),
				   new Test("https://twitter.com/", true),
				   new Test("https://www.w3.org/", true),
				   new Test("https://www.google.com/search?q=toutube&rlz=1C1GCEU_enUS819US819&oq=toutube&aqs=chrome..69i57.4603j0j9&sourceid=chrome&ie=UTF-8", true),
				   new Test("https://cloud.google.com/", true),
				   new Test("https://docs.microsoft.com/en-us/dotnet/welcome", true),
				   new Test("http://google.com", true),
				   new Test("http://goo.gl", true),
				   new Test("http://google.com:80", true),
				   new Test("http://google.com:80/", true),
				   new Test("http://google.com:9999", true),
				   new Test("http://info.google.com", true)
		   };

	 //Test valid test cases
	   for(int i = 0; i < ValidManualTestCases.length; i++)
	   {	
		   ValidManualTestCases[i].result = urlVal.isValid(ValidManualTestCases[i].testPart); 		     
	   }
	   
	 //Create Manual Invalid Test Cases Using Test Class
	   Test[] InvalidManualTestCases = 
		   {
				   new Test("This.Is>NotAValidUrl", false),
				   new Test("://:65a/..?action=view", false),
				   new Test("http:256.256.256.256:65535", false),
				   new Test("http:1.2.3.4.5:-1/..?action=edit&mode=up", false),
				   new Test("http:go.1aa:0/..?action=edit&mode=up", false),
				   new Test("http/www.google.com:80", false),
				   new Test("3ht://aaa:80/test1?action=view", false),
				   new Test("h3t://1.2.3.4.5:0/..?action=edit&mode=up", false),
				   new Test("h3t://255.255.255.255/..?action=edit&mode=up", false),
				   new Test("://:65636", false)
		   };
	   
	   //Test invalid test cases
	   for(int i = 0; i < InvalidManualTestCases.length; i++)
	   {
		   InvalidManualTestCases[i].result = urlVal.isValid(InvalidManualTestCases[i].testPart);  
	   }
	   
	   //Output Results
	   OutputResults(ValidManualTestCases);
	   OutputResults(InvalidManualTestCases);
   }

   
   public void testYourFirstPartition()
   {
      String[] schemesTrue = {
         "http://",
		 "https://",
		 "ftp://",
		 "mailto://",
		 "file://",
		 "data://",
		 "irc://"
      };
      
      String[] schemesFalse = {
         "htp://",
         "http",
         "ftp",
         "http//",
         "http:",
         "http:/"
      };
      
      System.out.println("--------- Schemes Partition Tests ---------");
      UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
      for (int i = 0; i < schemesTrue.length; i++) {
         if (urlVal.isValid(schemesTrue[i]) == true) {
            System.out.printf("\"%s\": Expected: PASS; Actual: PASS", schemesTrue[i]);
            System.out.println();
         } else {
            System.out.printf("\"%s\": Expected: PASS; Actual: FAIL", schemesTrue[i]);
            System.out.println();
         }
      }
    
      for (int i = 0; i < schemesFalse.length; i++) {
          if (urlVal.isValid(schemesFalse[i]) == true) {
             System.out.printf("\"%s\": Expected: FAIL; Actual: PASS", schemesFalse[i]);
             System.out.println();
          } else {
             System.out.printf("\"%s\": Expected: FAIL; Actual: FAIL", schemesFalse[i]);
             System.out.println();
          }
       }
      System.out.println();
   }

   public void testYourSecondPartition(){
      String[] authorityTrue = {
         "http://www.google.com",
		 "http://google.com",
		 "http://goo.gl",
		 "http://google.com:80",
		 "http://google.com:80/",
		 "http://google.com:9999",
		 "http://info.google.com",
		 "http://john.doe@www.example.com",
		 "http://google.org",
		 "http://oregonstate.edu",
		 "http://0.0.0.0",
		 "http://255.255.255.255"
	  };
      
      String[] authorityFalse = {
         "http://.com",
         "http://google",
         "http://5",
         "http://google.com//",
         "http://300.300.300.300",
         "http://google.com:a",
         "http://google.com:-1"
      };
      
      System.out.println("--------- Authority Partition Tests ---------");
      UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
      for (int i = 0; i < authorityTrue.length; i++) {
         if (urlVal.isValid(authorityTrue[i]) == true) {
            System.out.printf("\"%s\": Expected: PASS; Actual: PASS", authorityTrue[i]);
            System.out.println();
         } else {
            System.out.printf("\"%s\": Expected: PASS; Actual: FAIL", authorityTrue[i]);
            System.out.println();
         }
      }
    
      for (int i = 0; i < authorityFalse.length; i++) {
          if (urlVal.isValid(authorityFalse[i]) == true) {
             System.out.printf("\"%s\": Expected: FAIL; Actual: PASS", authorityFalse[i]);
             System.out.println();
          } else {
             System.out.printf("\"%s\": Expected: FAIL; Actual: FAIL", authorityFalse[i]);
             System.out.println();
          }
       }
       System.out.println();
   }

   public void testYourThirdPartition() {
      String[] pathTrue = {
        "http://www.google.com/chat",
        "http://www.google.com/chat/drive/duo/gmail",
        "http://www.google.com/WER23FF32",
        "http://www.google.com/WER23FF32/",
        "http://www.google.com/a$b#c%",
      };
      
      String[] pathFalse = {
         "http://www.google.com//",
         "http://www.google.comchat",
         "http://www.google.com/../",
         "http://www.google.comchat",
         "http://www.google.com/.."
      };

      System.out.println("--------- Path Partition Tests ---------");
      UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
      for (int i = 0; i < pathTrue.length; i++) {
         if (urlVal.isValid(pathTrue[i]) == true) {
            System.out.printf("\"%s\": Expected: PASS; Actual: PASS", pathTrue[i]);
            System.out.println();
         } else {
            System.out.printf("\"%s\": Expected: PASS; Actual: FAIL", pathTrue[i]);
            System.out.println();
         }
      }
    
      for (int i = 0; i < pathFalse.length; i++) {
          if (urlVal.isValid(pathFalse[i]) == true) {
             System.out.printf("\"%s\": Expected: FAIL; Actual: PASS", pathFalse[i]);
             System.out.println();
          } else {
             System.out.printf("\"%s\": Expected: FAIL; Actual: FAIL", pathFalse[i]);
             System.out.println();
          }
       }
       System.out.println();
   }

   public void testYourFourthPartition() {
      String[] queryTrue = {
         "http://www.google.com/chat?user=johnsmi7",
         "http://www.google.com/chat?user=johnsmi7&user=einhorn&user=aleshired"
      };
      
      System.out.println("--------- Query Partition Tests ---------");
      UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
      for (int i = 0; i < queryTrue.length; i++) {
         if (urlVal.isValid(queryTrue[i]) == true) {
            System.out.printf("\"%s\": Expected: PASS; Actual: PASS", queryTrue[i]);
            System.out.println();
         } else {
            System.out.printf("\"%s\": Expected: PASS; Actual: FAIL", queryTrue[i]);
            System.out.println();
         }
      }
       System.out.println();
   }

   public void testIsValid()
   {
	   UrlValidator urlVal = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println("-----Programming Based Tests-------");
	   
	   String[] schemePart = {
			   "http://",
			   "http/",
			   "://"
	   };
	   
	   boolean schemeBools[] = {
			   true,
			   false,
			   false
	   };
	   
	   String[] authPart = {
			   "0.0.0.0",
			   "255.255.255.255",
			   "www.google.com",
			   "aaa.",
			   "1.2.3.4."
	   };
	   
	   boolean authBools[] = {
			   true,
			   true,
			   true,
			   false,
			   false
	   };
	   
	   String[] pathPart = {
			   "/test1/file",
			   "/test1",
			   "/..//file",
			   "/test1//file"
	   };
	   
	   boolean pathBools[] = {
			   true,
			   true,
			   false,
			   false
	   };
	   
	   String[] queryPart = {
			   "?action=view",
			   "?action=edit&mode=up",
			   "?=",
			   "?action="
	   };
	   
	   boolean queryBools[] = {
			   true,
			   true,
			   true,
			   true
	   };
	   
	   for (int i = 0; i < schemePart.length; i++) {
		   for (int j = 0; j < authPart.length; j++) {
			   for (int k = 0; k < pathPart.length; k++) {
				   for (int l = 0; l < queryPart.length; l++) {
					   String builtString = schemePart[i] + authPart[j] + pathPart[k] + queryPart[l];
					   boolean builtBool = schemeBools[i] && authBools[j] && pathBools[k] && queryBools[l];
					   System.out.printf("Full current test string is: \"%s\"; ", builtString);
					   
					   if (builtBool) {
						   System.out.print("Expect Result to be True; ");
					   }
					   else {
						   System.out.print("Expect Result to be False; ");
					   }
					   
					   if (urlVal.isValid(builtString)) {
						   System.out.print("Result = True - ");
					   }
					   else {
						   System.out.print("Result = False - ");
					   }
					   
					   if (urlVal.isValid(builtString) == builtBool) {
						   System.out.print("PASS\n");
					   }
					   else {
						   System.out.print("FAIL\n");
					   }
				   }
			   }
		   }
	   }
	   
	   System.out.println();
   }
   
   public void OutputResults(Test[] arr) {
	   for(int i = 0; i < arr.length; i++)
	   {
		   if(arr[i].result == arr[i].isValid)
		   {
			   System.out.println("Test Success: "+arr[i].testPart+"\nExpected -> "+arr[i].isValid+"\n");
		   }
		   else
		   {
			   System.out.println("Test Failure: "+arr[i].testPart+"\nExpected -> "+arr[i].isValid+"\n");
		   }
	   }
   }
   
   public class Test {
		String testPart;
		boolean isValid;
		boolean result;
		
		public Test(String testPart, boolean isValid)
		{
			this.testPart = testPart;
			this.isValid = isValid;
	   }

   }

}
