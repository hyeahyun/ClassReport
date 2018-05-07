// test of ROOT forum 
// http://root.cern.ch/phpBB3//viewtopic.php?f=3&t=11923


struct Vavilov_Func { 
   Vavilov_Func() {}

   double operator() (const double *x, const double *p) { 
      double kappa = p[0]; 
      double beta2 = p[1];
      return p[4]*( pdf.Pdf( (x[0]-p[2])/p[3], kappa,beta2) );
   }

   ROOT::Math::VavilovAccurate pdf; 
};

void fit_Vavilov() { 

   TH1 * h1 = new TH1D("h1","h1",40,0,40);
   ifstream infile("Vavilov.txt");
   double x = -9999;
   std::string line; 
   while (std::getline(infile,line,'\n')) { 
      if (1 != sscanf(line.c_str(),"%lg",&x) )
         continue; 
      h1->Fill(x);
   }
   h1->Draw();
   Vavilov_Func * func = new Vavilov_Func();
   TF1 * f1 = new TF1("f1",func, 0,40,5,"Vavilov_Func");
   f1->SetParNames("kappa","beta2","mean","sigma","Amp"); 
   f1->SetParameters(0.3,0.05,h1->GetMean(),h1->GetRMS(),h1->GetEntries());
   f1->SetParLimits(0.01,0,10);
   f1->SetParLimits(1,0,1);
   		
   h1->Fit(f1);
   //f1->Draw();
   // print parameter values and errors
	std::cout << " Vavilov mean = " << f1->GetParameter(2) << " +/- " << f1->GetParError(2) << std::endl;	
	std::cout << " Vavilov sigma = " << f1->GetParameter(3) << " +/- " << f1->GetParError(3) << std::endl;		

   

}
