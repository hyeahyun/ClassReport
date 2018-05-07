#include <TFile.h>
#include <iostream>
#include <fstream>
#include <TLine.h>
#include <TCanvas.h>
#include <iostream>
#include <TCanvas.h>
#include <TStyle.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TF1.h>
#include <TMath.h>
#include <map>
#include "TKey.h"
#include "TMacro.h"
#include <string>
#include <TGraphErrors.h>
#include <TPaveStats.h>
#include <stdio.h>
using namespace std;

double desired_error = 0.00005; 
//double sigma = 0.999968; // 4 sigma
//double sigma = 0.999767; // 3.5 sigma
double sigma = 0.99865; // 3 sigma
//double sigma = 0.99379; //2.5 sigma
//double sigma = 0.97725; //2 sigma

void fitting_DEta_two_gaus( int which_sw)
{
  
  TH1F* one_hist;
  double min = -0.01, max = 0.01;

  char file_name[] = "../DeltaEta.root"; 
  char dir_kind[] = "DEta/"; 
  char hist_name_common[] = "Standalone_DEta_";
  TFile * f = new TFile (file_name);
   // 012, 013, 014, 023, 024, 034, 123, 124, 134, 234
   //   0    1    2    3    4    5    6    7    8    9 
   // 012, 013, 014, 023, 024, 034, 123, 124, 134, 234
   //   0    1    2    3    4    5    6    7    8    9
  
  int index = 0;

  char directory[20]; 
 
  if( which_sw  == 0){ 
    sprintf( directory, "D3D4_D4D5" );    
    f->cd("34_45");
  }
  if( which_sw == 1){ 
    sprintf( directory, "D3D4_D4D6" );    
    f->cd("34_46");
  }
  if( which_sw == 2){ 
    sprintf( directory, "D3D5_D5D6" );    
    f->cd("35_56");
  }
  if( which_sw == 3 ){
    sprintf( directory, "D4D5_D5D6" );    
    f->cd("45_56");
  }

 

  cout << directory << endl;
 
        cout << "******************************" <<directory << endl;
           //f->cd(input_directory);
           
           // For signal window points. 
           // x1 and y1 for upper points
           // x2 and y2 for lower points
           double x2[150] = {}, y2[150] = {}; 
           double x1[150] = {}, y1[150] = {};
           index = 0;  // index for the number of histograms in the directory
           for( int energy = 10; energy < 75; energy++ ){ //147
                 double h_mean=0.;
                 double h_rms=0.;
                 int entry=0.;
                 double max_2=0.;
                 double max_1=0.;
                 char hist_name[100];

                 cout << directory << endl; 
                 sprintf(hist_name, "%s%s_%d", hist_name_common, directory, energy); // make histogram name to read
                 cout << hist_name << endl;
                 one_hist = (TH1F*)gDirectory->Get(hist_name);

                 int binmax = one_hist->GetMaximumBin();
                 double x = one_hist->GetXaxis()->GetBinCenter(binmax);

                 min = -0.01;
                 max = 0.01;  

                 one_hist->GetXaxis()->SetRangeUser(min,max);
                 
                 TH1F* cloned_hist;
                 cloned_hist = (TH1F*)one_hist->Clone();
                 max_1 = cloned_hist->GetMaximum();
                 entry = cloned_hist->GetEntries();
                 h_mean = cloned_hist->GetMean();
                 h_rms = cloned_hist->GetRMS();
                 float bin=(max-min)/one_hist->GetBinWidth(0);
                 bin=bin/50;
                 one_hist->Rebin(bin);
                 max_2 = one_hist->GetMaximum();
                 one_hist->SetMaximum(max_2*1.2);

                 TF1 *func = new TF1("func","[0]*TMath::Gaus(x,[1],[2],1)+[3]*TMath::Gaus(x,[4],[5],1)",min,max);
                 func->SetParNames("1.Scale factor","1.Gaussian mean","1.Gaussian sigma","2.Scale factor","2.Gaussian mean","2.Gaussian sigma");

                 func->SetParameters(0.15*max_2*(max-min), h_mean-h_rms/1.2, h_rms/1.5, 0.05*max_2*(max-min), h_mean+h_rms/1.2, h_rms);
                 func->SetParLimits(0,0.01, 100);
                 func->SetParLimits(1,h_mean-0.0002,h_mean+0.0002);
                 func->SetParLimits(2,h_rms*0.3,h_rms*0.5);

                 func->SetParLimits(3,0.01, 100);
                 func->SetParLimits(4,h_mean-0.0005,h_mean+0.0005);
                 func->SetParLimits(5,h_rms*0.3,h_rms*1.2);

                 one_hist->Fit(func,"0R");

                 TF1 *gaus1 = new TF1("gaus","[0]*TMath::Gaus(x,[1],[2],1)",min,max);
                 TF1 *gaus2 = new TF1("gaus","[0]*TMath::Gaus(x,[1],[2],1)",min,max);
                 TF1 *func_set = new TF1("func","[0]*TMath::Gaus(x,[1],[2],1)+[3]*TMath::Gaus(x,[4],[5],1)",min,max);

                 TCanvas* canvas_1 = new TCanvas("test","test",800,600);
//                 gStyle->SetOptStat(1111);
//                 gStyle->SetOptFit(1111);
                gStyle->SetOptStat(0);
               //  gStyle->SetOptFit(1111);
                 gPad->SetGrid();
                 canvas_1->cd();
                 one_hist->SetMarkerStyle(8);
                 one_hist->Draw("pe");
                 char temp_histo_title[100];
                 sprintf(temp_histo_title, "#DeltaEta (%c%c%c%c, EM): e/#gamma E_{T} %d~%d GeV", directory[0], directory[1], directory[3], directory[4], energy, energy+1 );
                 one_hist->SetTitle(temp_histo_title);
                 one_hist->GetYaxis()->SetLabelSize(0.05);
                 one_hist->GetXaxis()->SetLabelSize(0.05);
                 one_hist->GetXaxis()->SetTitle("#Delta#eta");
                 one_hist->GetXaxis()->SetTitleFont(43);
                 one_hist->GetXaxis()->SetTitleSize(23);
                 one_hist->GetXaxis()->SetRangeUser(min,max);

    		 gaus1->SetParameters(func->GetParameter(0),func->GetParameter(1),func->GetParameter(2));
    		 gaus1->SetLineColor(3);  gaus1->SetLineWidth(2); gaus1->SetLineStyle(2); 
            
   		 gaus2->SetParameters(func->GetParameter(3),func->GetParameter(4),func->GetParameter(5));
    		 gaus2->SetLineColor(4);  gaus2->SetLineWidth(2); gaus2->SetLineStyle(2); 
 
    		 func_set->SetParameters(func->GetParameter(0),func->GetParameter(1),func->GetParameter(2),func->GetParameter(3),func->GetParameter(4),func->GetParameter(5));
    		 func_set->SetLineColor(2);  func_set->SetLineWidth(2); func_set->SetLineStyle(2); 


                 double up = 0., down = 0.;
                 double total_area = 0.;
                 double probe = 0.; 
                 double ratio = 0.; 
                 double area = 0.; 
                 double error = 0.; 
                 double increment = 0.0001; 
                 total_area = func_set->Integral( min, max ); 
  		 /// lower sigma point 0.99865///
                 probe = one_hist->GetMean() - 2.0 * one_hist->GetRMS(); // set starting point 
                 area = func_set->Integral( probe, max);   ratio = area / total_area;
                
                 error = fabs(sigma - ratio);
                 int count = 0;
                 double temp_error[2]; 
                 double temp_probe[2]; 
                 while( error > desired_error ){ 
                     temp_error[count % 2] = error;                      
                     temp_probe[count % 2] = probe;                      
                     if( area > total_area * sigma ) probe = probe + increment;       
                     if( area < total_area * sigma ) probe = probe - increment;       
                     area = func_set->Integral( probe, max);    
                     ratio = area / total_area;
                     error = fabs(sigma - ratio);
                     if( count > 1 && temp_error[0] == error){ cout << "avoid infinite loop..." << endl; 
                       cout << "probe: " << probe << " temp_probe[0]: " << temp_probe[0] << " temp_probe[1]: " << temp_probe[1]<< endl;
                       probe = (temp_probe[0] + temp_probe[1]) / 2;
                       area = func_set->Integral( probe, max);    
                       ratio = area / total_area;
                       error = fabs(sigma - ratio);
                       cout << "new probe: " << probe << " new error: " << error << endl;
                       increment = 0.00001;
                     }
                     cout << "lower: " << error << " probe: " << probe << endl;
                     count++;
		 } 
                 TLine *lower = new TLine(probe,0,probe,max_2*1.2);
                 lower->Draw();
                 lower->SetLineColor(6);
                 lower->SetLineWidth(3);
                 lower->SetLineStyle(2);
                 down = probe;

                 probe = one_hist->GetMean() + 2.0 * one_hist->GetRMS(); // set starting point 
                 area = func_set->Integral( min, probe);   ratio = area / total_area;
    
                 error = fabs(sigma - ratio);
                 increment = 0.0001;
                 while( error > desired_error ){  
                     temp_error[count % 2] = error;                      
                     temp_probe[count % 2] = probe;                      
                     if( area > total_area * sigma ) probe = probe - increment;    
                     if( area < total_area * sigma ) probe = probe + increment;    
                     area = func_set->Integral( min, probe);    
                     ratio = area / total_area;
                     error = fabs(sigma - ratio);
                     if( count > 1 && temp_error[0] == error){ cout << "avoid infinite loop..." << endl;
                       cout << "probe: " << probe << " temp_probe[0]: " << temp_probe[0] << " temp_probe[1]: " << temp_probe[1]<< endl;
                       probe = (temp_probe[0] + temp_probe[1]) / 2;
                       area = func_set->Integral( min, probe);
                       ratio = area / total_area;
                       error = fabs(sigma - ratio);
                       increment = 0.00001;
                     }
                     cout << "upper: " << error << endl;
                     count++;
                 }   
                 TLine *upper = new TLine(probe,0,probe,max_2*1.2);
                 upper->Draw();
                 upper->SetLineColor(6);
                 upper->SetLineWidth(3);
                 upper->SetLineStyle(2);
                 up = probe;

     		 gaus1->Draw("lsame");
     		 gaus2->Draw("lsame");
     		 func_set->Draw("lsame");
                 

                 char temp_file_name[100];
                 sprintf(temp_file_name, "./fitResult/%s.pdf",hist_name );
                 canvas_1->SaveAs(temp_file_name);

                 cout << energy << endl;
                 x1[index] = double(energy + 0.5); x2[index] = double(energy + 0.5);
                 cout << "array" << x1[index] << " " << x2[index] << endl;
                 y1[index] = up;                   y2[index] = down;
                 cout << "up/down" << y1[index] << " " << y2[index] << endl;
                 index++;
        }
        ofstream myfile1;
        char text_file1[50];
        char text_file2[50];
        char signal_window[50];

        sprintf(text_file1, "./points.h" );

        myfile1.open (text_file1);

        myfile1 << "#ifndef points_h" << endl;
        myfile1 << "#define points_h" << endl;
        myfile1 << endl;

        myfile1 << "double x1[150] ={}, y[150] = {}; " << endl;
        myfile1 << "double x2[150] ={}, y2[150] = {}; " << endl;      
        myfile1 << "int points;" << endl;

        myfile1 << "void set_arrary(){" << endl; 
        myfile1 << endl;
        int points = 0;
        for( points=0; points < 150; points++){
            if( x1[points] == 0 &&  y1[points] == 0 ) break;
            myfile1 << "x1[" << points << "] = " << /*x1[points]*/x1[0]+2*points << "; y[" << points << "] = " << y1[points] << ";" << endl;
        }
        myfile1 << endl;
        for(points=0; points < 150; points++){
            if( x2[points] == 0 &&  y2[points] == 0 ) break;
            myfile1 << "x2[" << points << "] = " << x2[0]+2*points << "; y2[" << points << "] = " << y2[points] << ";" << endl;
        }
        myfile1 << "points = " << points << ";" << endl;
        myfile1 << "}" << endl;
        myfile1 << "#endif" << endl;
        myfile1.close();
}
