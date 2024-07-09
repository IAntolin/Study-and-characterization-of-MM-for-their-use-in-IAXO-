
void primakoff_plots() {

  TFile *fin = new TFile("Primakoff_histogram.root");
  TH1D* hSpc = (TH1D*)fin->Get("primakoff");
  
  // Create copies of the original histogram for left and right pads
  TH1D* hSpc_left = (TH1D*)hSpc->Clone("hSpc_left");
  TH1D* hSpc_right = (TH1D*)hSpc->Clone("hSpc_right");

  TFile *fin0 = new TFile("Primakoff_histogram_1.2_l.root");
  TH1D* h0 = (TH1D*)fin0->Get("histo0");
  TFile *fin1 = new TFile("Primakoff_histogram_2.0_l.root");
  TH1D* h1 = (TH1D*)fin1->Get("histo1");
  TFile *fin2 = new TFile("Primakoff_histogram_1.2_2l.root");
  TH1D* h2 = (TH1D*)fin2->Get("histo2");
  TFile *fin3 = new TFile("Primakoff_histogram_2.0_2l.root");
  TH1D* h3 = (TH1D*)fin3->Get("histo3");
  
  TCanvas *c1 = new TCanvas("c1", "c1", 3000, 1500); 
  
  c1->Divide(2,1);
  c1->cd(1)->SetMargin(0.155, 0.02, 0.15, 0.085);
  
  // Style adjustments for left pad
  hSpc_left->SetLineColor(kMagenta+2);
  hSpc_left->SetMarkerColor(kMagenta+2);
  hSpc_left->SetMarkerSize(5);
  hSpc_left->SetStats(0);
  gStyle->SetTitleFont(102, ""); 
  gStyle->SetTitleX(0.57); //title X location
  gStyle->SetTitleY(0.99); //title Y location
  gStyle->SetTitleSize(0.07, "t"); 
  hSpc_left->SetTitle("3 cm Drift Distance");  
  hSpc_left->GetXaxis()->SetTitle("E_{a} [keV]");         
  hSpc_left->GetXaxis()->SetTitleSize(0.04);
  hSpc_left->GetXaxis()->SetTitleFont(82);
  hSpc_left->GetXaxis()->CenterTitle(); 
  hSpc_left->GetXaxis()->SetLabelFont(82);
  hSpc_left->GetXaxis()->SetTitleOffset(1.1);  
  hSpc_left->GetXaxis()->SetLabelSize(0.04);
  hSpc_left->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @ g_{10} [s^{-1}cm^{-2}]");
  hSpc_left->GetYaxis()->SetTitleSize(0.04);
  hSpc_left->GetYaxis()->SetTitleFont(82);
  hSpc_left->GetYaxis()->SetLabelFont(82);
  hSpc_left->GetYaxis()->SetTitleOffset(1.8);
  hSpc_left->GetYaxis()->SetLabelOffset(0.02); 
  hSpc_left->GetYaxis()->CenterTitle(); 
  hSpc_left->GetYaxis()->SetLabelSize(0.04);
  hSpc_left->Draw();
  
  h1->SetLineColor(kGreen);
  h1->Draw("same");
  h0->SetLineColor(kRed);
  h0->Draw("same");
  
  TLegend *legend = new TLegend(0.54, 0.75, 0.97, 0.85);   
  legend->SetTextFont(82);
  legend->SetTextSize(0.035);
  legend->SetLineColor(1);
  legend->SetLineStyle(1);
  legend->SetLineWidth(1);
  legend->SetFillColor(0);
  legend->SetFillColorAlpha(kWhite, 0);  
  legend->SetLineColor(kWhite);
  legend->AddEntry(hSpc_left,"Nominal spectrum","l"); 
  legend->AddEntry(h0,"P = 1.2 bar","l");
  legend->AddEntry(h1, "P = 2.0 bar", "l");
  legend->SetFillColor(kWhite); 
  legend->SetLineColor(kWhite);
  legend->Draw(); 
  
  c1->cd(2)->SetMargin(0.155, 0.02, 0.15, 0.085);
  
  // Style adjustments for right pad
  hSpc_right->SetLineColor(kMagenta+2);
  hSpc_right->SetMarkerColor(kMagenta+2);
  hSpc_right->SetStats(0);
  hSpc_right->SetMarkerSize(5);
  gStyle->SetTitleFont(102, ""); 
  hSpc_right->SetTitle("6 cm Drift Distance");  
  hSpc_right->GetXaxis()->SetTitle("E_{a} [keV]");         
  hSpc_right->GetXaxis()->SetTitleSize(0.04);
  hSpc_right->GetXaxis()->SetTitleFont(82);
  hSpc_right->GetXaxis()->CenterTitle(); 
  hSpc_right->GetXaxis()->SetLabelFont(82);
  hSpc_right->GetXaxis()->SetTitleOffset(1.1);  
  hSpc_right->GetXaxis()->SetLabelSize(0.04);
  hSpc_right->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @ g_{10} [s^{-1}cm^{-2}]");
  hSpc_right->GetYaxis()->SetTitleSize(0.04);
  hSpc_right->GetYaxis()->SetTitleFont(82);
  hSpc_right->GetYaxis()->SetLabelFont(82);
  hSpc_right->GetYaxis()->SetTitleOffset(1.8);
  hSpc_right->GetYaxis()->SetLabelOffset(0.02); 
  hSpc_right->GetYaxis()->CenterTitle(); 
  hSpc_right->GetYaxis()->SetLabelSize(0.04); 
  hSpc_right->Draw();
  
  h3->SetLineColor(kGreen);
  h3->Draw("same");
  h2->SetLineColor(kRed);
  h2->Draw("same");
  
  TLegend *legend2 = new TLegend(0.54, 0.75, 0.97, 0.85);
  legend2->SetTextFont(82);
  legend2->SetTextSize(0.035);
  legend2->SetLineColor(1);
  legend2->SetLineStyle(1);
  legend2->SetLineWidth(1);
  legend2->SetFillColor(0);
  legend2->SetFillColorAlpha(kWhite, 0);  
  legend2->SetLineColor(kWhite);
  legend2->AddEntry(hSpc_right,"Nominal spectrum","l"); 
  legend2->AddEntry(h2,"P = 1.2 bar","l");
  legend2->AddEntry(h3, "P = 2.0 bar", "l");
  legend2->SetFillColor(kWhite); 
  legend2->SetLineColor(kWhite);
  legend2->Draw(); 
  
  c1->SaveAs("primakoff_response.png");  
  c1->SaveAs("primakoff_response.eps"); 
  
}




void ABC_plots() {

  TFile * fin = new TFile("ABC_histogram.root");
  TH1D* hSpc = (TH1D*)fin->Get("ABC");
  // Create copies of the original histogram for left and right pads
  TH1D* hSpc_left = (TH1D*)hSpc->Clone("hSpc_left");
  TH1D* hSpc_right = (TH1D*)hSpc->Clone("hSpc_right");
  
  TFile * fin0 = new TFile("ABC_histogram_1.2_l.root");
  TH1D* h0 = (TH1D*)fin0->Get("histo0");
  TFile * fin1 = new TFile("ABC_histogram_2.0_l.root");
  TH1D* h1 = (TH1D*)fin1->Get("histo1");
  TFile * fin2 = new TFile("ABC_histogram_1.2_2l.root");
  TH1D* h2 = (TH1D*)fin2->Get("histo2");
  TFile * fin3 = new TFile("ABC_histogram_2.0_2l.root");
  TH1D* h3 = (TH1D*)fin3->Get("histo3");
  
  TCanvas * c1 = new TCanvas("c1", "c1", 3000, 1500); 
  
  c1 ->Divide(2,1);
  c1-> cd(1)->SetMargin(0.155, 0.02, 0.15, 0.085);
 
  // Style adjustments for left pad
  hSpc_left->SetLineColor(kMagenta+2);
  hSpc_left->SetMarkerColor(kMagenta+2);
  hSpc_left->SetMarkerSize(5);
  hSpc_left->SetStats(0);
  gStyle->SetTitleFont(102, ""); 
  gStyle->SetTitleX(0.57); //title X location
  gStyle->SetTitleY(0.99); //title Y location
  gStyle->SetTitleSize(0.07, "t"); 
  hSpc_left->SetTitle("3 cm Drift Distance");  
  hSpc_left->GetXaxis()->SetTitle("E_{a} [keV]");         
  hSpc_left->GetXaxis()->SetTitleSize(0.04);
  hSpc_left->GetXaxis()->SetTitleFont(82);
  hSpc_left->GetXaxis()->CenterTitle(); 
  hSpc_left->GetXaxis()->SetLabelFont(82);
  hSpc_left->GetXaxis()->SetTitleOffset(1.1);  
  hSpc_left->GetXaxis()->SetLabelSize(0.04);
  hSpc_left->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} [10^{20}keV^{-1}year^{-1}m^{-2}]"); 
  hSpc_left->GetYaxis()->SetTitleSize(0.04);
  hSpc_left->GetYaxis()->SetTitleFont(82);
  hSpc_left->GetYaxis()->SetLabelFont(82);
  hSpc_left->GetYaxis()->SetTitleOffset(1.8);
  hSpc_left->GetYaxis()->SetLabelOffset(0.02); 
  hSpc_left->GetYaxis()->CenterTitle(); 
  hSpc_left->GetYaxis()->SetLabelSize(0.04);
  hSpc_left->Draw();
  
  h1->SetLineColor(kGreen);
  h1->Draw("same");
  h0->SetLineColor(kRed);
  h0->Draw("same");
  
  TLegend *legend = new TLegend(0.54, 0.75, 0.97, 0.85);  
  legend->SetTextFont(82);
  legend->SetTextSize(0.035);
  legend->SetLineColor(1);
  legend->SetLineStyle(1);
  legend->SetLineWidth(1);
  legend->SetFillColor(0);
  legend->SetFillColorAlpha(kWhite, 0);  
  legend->SetLineColor(kWhite);
  legend->AddEntry(hSpc_left,"Nominal spectrum","l"); 
  legend->AddEntry(h0,"P = 1.2 bar","l");
  legend->AddEntry(h1, "P = 2.0 bar", "l");
  legend->SetFillColor(kWhite); 
  legend->SetLineColor(kWhite);
  legend->Draw(); 
  
  c1->cd(2)->SetMargin(0.155, 0.02, 0.15, 0.085);
  
  // Style adjustments for right pad
  hSpc_right->SetLineColor(kMagenta+2);
  hSpc_right->SetMarkerColor(kMagenta+2);
  hSpc_right->SetStats(0);
  hSpc_right->SetMarkerSize(5);
  gStyle->SetTitleFont(102, ""); 
  hSpc_right->SetTitle("6 cm Drift Distance");  
  hSpc_right->GetXaxis()->SetTitle("E_{a} [keV]");         
  hSpc_right->GetXaxis()->SetTitleSize(0.04);
  hSpc_right->GetXaxis()->SetTitleFont(82);
  hSpc_right->GetXaxis()->CenterTitle(); 
  hSpc_right->GetXaxis()->SetLabelFont(82);
  hSpc_right->GetXaxis()->SetTitleOffset(1.1);  
  hSpc_right->GetXaxis()->SetLabelSize(0.04);
  hSpc_right->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} [10^{20}keV^{-1}year^{-1}m^{-2}]"); 
  hSpc_right->GetYaxis()->SetTitleSize(0.04);
  hSpc_right->GetYaxis()->SetTitleFont(82);
  hSpc_right->GetYaxis()->SetLabelFont(82);
  hSpc_right->GetYaxis()->SetTitleOffset(1.8);
  hSpc_right->GetYaxis()->SetLabelOffset(0.02); 
  hSpc_right->GetYaxis()->CenterTitle(); 
  hSpc_right->GetYaxis()->SetLabelSize(0.04); 
  hSpc_right->Draw();
  
  h3->SetLineColor(kGreen);
  h3->Draw("same");
  h2->SetLineColor(kRed);
  h2->Draw("same");
  
  TLegend *legend2 = new TLegend(0.54, 0.75, 0.97, 0.85);    
  legend2->SetTextFont(82);
  legend2->SetTextSize(0.035);
  legend2->SetLineColor(1);
  legend2->SetLineStyle(1);
  legend2->SetLineWidth(1);
  legend2->SetFillColor(0);
  legend2->SetFillColorAlpha(kWhite, 0);  
  legend2->SetLineColor(kWhite);
  legend2->AddEntry(hSpc_right,"Nominal spectrum","l"); 
  legend2->AddEntry(h2,"P = 1.2 bar","l");
  legend2->AddEntry(h3, "P = 2.0 bar", "l");
  legend2->SetFillColor(kWhite); 
  legend2->SetLineColor(kWhite);
  legend2->Draw(); 
  
  c1->SaveAs("ABC_response.png");  
  c1->SaveAs("ABC_response.eps"); 
  
}


void aN_plots() {

  TFile * fin = new TFile("aN_histogram.root");
  TH1D* hSpc = (TH1D*)fin->Get("aN");
  // Create copies of the original histogram for left and right pads
  TH1D* hSpc_left = (TH1D*)hSpc->Clone("hSpc_left");
  TH1D* hSpc_right = (TH1D*)hSpc->Clone("hSpc_right");

  TFile * fin0 = new TFile("aN_histogram_1.2_l.root");
  TH1D* h0 = (TH1D*)fin0->Get("histo0");
  TFile * fin1 = new TFile("aN_histogram_2.0_l.root");
  TH1D* h1 = (TH1D*)fin1->Get("histo1");
  TFile * fin2 = new TFile("aN_histogram_1.2_2l.root");
  TH1D* h2 = (TH1D*)fin2->Get("histo2");
  TFile * fin3 = new TFile("aN_histogram_2.0_2l.root");
  TH1D* h3 = (TH1D*)fin3->Get("histo3");
  
  TCanvas * c1 = new TCanvas("c1", "c1", 3000, 1500); 
  
  c1 ->Divide(2,1);
  c1-> cd(1)->SetMargin(0.155, 0.05, 0.15, 0.085);
  
  
  // Style adjustments for left pad
  hSpc_left->SetLineColor(kMagenta+2);
  hSpc_left->SetMarkerColor(kMagenta+2);
  hSpc_left->SetMarkerSize(5);
  hSpc_left->SetStats(0);
  gStyle->SetTitleFont(102, ""); 
  gStyle->SetTitleX(0.57); //title X location
  gStyle->SetTitleY(0.99); //title Y location
  gStyle->SetTitleSize(0.07, "t"); 
  hSpc_left->SetTitle("3 cm Drift Distance");  
  hSpc_left->GetXaxis()->SetTitle("E_{a} [keV]");         
  hSpc_left->GetXaxis()->SetTitleSize(0.04);
  hSpc_left->GetXaxis()->SetTitleFont(82);
  hSpc_left->GetXaxis()->CenterTitle(); 
  hSpc_left->GetXaxis()->SetLabelFont(82);
  hSpc_left->GetXaxis()->SetTitleOffset(1.1);  
  hSpc_left->GetXaxis()->SetLabelSize(0.038);
  hSpc_left->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @g_{aN}^{eff} [s^{-1}cm^{-2}]");
  hSpc_left->GetYaxis()->SetTitleSize(0.04);
  hSpc_left->GetYaxis()->SetTitleFont(82);
  hSpc_left->GetYaxis()->SetLabelFont(82);
  hSpc_left->GetYaxis()->SetTitleOffset(1.8);
  hSpc_left->GetYaxis()->SetLabelOffset(0.02); 
  hSpc_left->GetYaxis()->CenterTitle(); 
  hSpc_left->GetYaxis()->SetLabelSize(0.04);
  hSpc_left->GetXaxis()->SetRangeUser(14.38, 14.44);
  hSpc_left->Draw();
  
  h1->SetLineColor(kGreen);
  h1->Draw("same");
  h0->SetLineColor(kRed);
  h0->Draw("same");
  
  TLegend *legend = new TLegend(0.54, 0.75, 0.82, 0.85);    
  legend->SetTextFont(82);
  legend->SetTextSize(0.035);
  legend->SetLineColor(1);
  legend->SetLineStyle(1);
  legend->SetLineWidth(1);
  legend->SetFillColor(0);
  legend->SetFillColorAlpha(kWhite, 0);  
  legend->SetLineColor(kWhite);
  legend->AddEntry(hSpc_left,"Nominal spectrum","l"); 
  legend->AddEntry(h0,"P = 1.2 bar","l");
  legend->AddEntry(h1, "P = 2.0 bar", "l");
  legend->SetFillColor(kWhite); 
  legend->SetLineColor(kWhite);
  legend->Draw(); 
  
  c1->cd(2)->SetMargin(0.155, 0.05, 0.15, 0.085);
  
  // Style adjustments for right pad
  hSpc_right->SetLineColor(kMagenta+2);
  hSpc_right->SetMarkerColor(kMagenta+2);
  hSpc_right->SetStats(0);
  hSpc_right->SetMarkerSize(5);
  gStyle->SetTitleFont(102, ""); 
  hSpc_right->SetTitle("6 cm Drift Distance");  
  hSpc_right->GetXaxis()->SetTitle("E_{a} [keV]");         
  hSpc_right->GetXaxis()->SetTitleSize(0.04);
  hSpc_right->GetXaxis()->SetTitleFont(82);
  hSpc_right->GetXaxis()->CenterTitle(); 
  hSpc_right->GetXaxis()->SetLabelFont(82);
  hSpc_right->GetXaxis()->SetTitleOffset(1.1);  
  hSpc_right->GetXaxis()->SetLabelSize(0.038);
  hSpc_right->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @g_{aN}^{eff} [s^{-1}cm^{-2}]");
  hSpc_right->GetYaxis()->SetTitleSize(0.04);
  hSpc_right->GetYaxis()->SetTitleFont(82);
  hSpc_right->GetYaxis()->SetLabelFont(82);
  hSpc_right->GetYaxis()->SetTitleOffset(1.8);
  hSpc_right->GetYaxis()->SetLabelOffset(0.02); 
  hSpc_right->GetYaxis()->CenterTitle(); 
  hSpc_right->GetYaxis()->SetLabelSize(0.04); 
  hSpc_right->GetXaxis()->SetRangeUser(14.38, 14.44);
  hSpc_right->Draw();
  
  h3->SetLineColor(kGreen);
  h3->Draw("same");
  h2->SetLineColor(kRed);
  h2->Draw("same");
  
  TLegend *legend2 = new TLegend(0.54, 0.75, 0.82, 0.85);      
  legend2->SetTextFont(82);
  legend2->SetTextSize(0.035);
  legend2->SetLineColor(1);
  legend2->SetLineStyle(1);
  legend2->SetLineWidth(1);
  legend2->SetFillColor(0);
  legend2->SetFillColorAlpha(kWhite, 0);  
  legend2->SetLineColor(kWhite);
  legend2->AddEntry(hSpc_right,"Nominal spectrum","l"); 
  legend2->AddEntry(h2,"P = 1.2 bar","l");
  legend2->AddEntry(h3, "P = 2.0 bar", "l");
  legend2->SetFillColor(kWhite); 
  legend2->SetLineColor(kWhite);
  legend2->Draw(); 
  
  c1->SaveAs("aN_response.png");  
  c1->SaveAs("aN_response.eps"); 
  
}


//for the analysis of l and 2l:
void primakoff_analysis(){

  double factor_primakoff12=5.21959e13/675772.;
  double factor_primakoff2=5.21959e13/611872.;
  double factor_primakoff12_2=5.21959e13/598789.;
  double factor_primakoff2_2=5.21959e13/579520.;

  TFile *fin = new TFile("Primakoff_histogram.root");
  TH1D* hSpc = (TH1D*)fin->Get("primakoff");
  TH1D* hSpc_left = (TH1D*)hSpc->Clone("hSpc_left");
  TH1D* hSpc_right = (TH1D*)hSpc->Clone("hSpc_right");
  TFile *fin2 = new TFile("Primakoff_histogram_ana_1.2_l.root");
  TH1F* h_ana = (TH1F*)fin2->Get("h_primakoff_ana");
  TFile *fin3 = new TFile("Primakoff_histogram_ana_1.2_2l.root");
  TH1F* h_ana2 = (TH1F*)fin3->Get("h_primakoff_ana2");
  
  TFile *fin4 = new TFile("Primakoff_histogram_ana_2.0_l.root");
  TH1F* h_ana4 = (TH1F*)fin4->Get("h_primakoff_ana");
  TFile *fin5 = new TFile("Primakoff_histogram_ana_2.0_2l.root");
  TH1F* h_ana5 = (TH1F*)fin5->Get("h_primakoff_ana2");
  
  TCanvas * c1 = new TCanvas("c1", "c1", 3000, 1500); 
  
  c1 ->Divide(2,1);
  c1-> cd(1)->SetMargin(0.155, 0.05, 0.15, 0.085);
  
  // Style adjustments for left pad
  hSpc_left->SetLineColor(kMagenta+2);
  hSpc_left->SetMarkerColor(kMagenta+2);
  hSpc_left->SetMarkerSize(5);
  hSpc_left->SetStats(0);
  gStyle->SetTitleFont(102, ""); 
  gStyle->SetTitleX(0.57); //title X location
  gStyle->SetTitleY(0.99); //title Y location
  gStyle->SetTitleSize(0.07, "t"); 
  hSpc_left->SetTitle("3 cm Drift Distance");  
  hSpc_left->GetXaxis()->SetTitle("E_{a} [keV]");         
  hSpc_left->GetXaxis()->SetTitleSize(0.04);
  hSpc_left->GetXaxis()->SetTitleFont(82);
  hSpc_left->GetXaxis()->CenterTitle(); 
  hSpc_left->GetXaxis()->SetLabelFont(82);
  hSpc_left->GetXaxis()->SetTitleOffset(1.1);  
  hSpc_left->GetXaxis()->SetLabelSize(0.04);
  hSpc_left->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @ g_{10} [s^{-1}cm^{-2}]");
  hSpc_left->GetYaxis()->SetTitleSize(0.04);
  hSpc_left->GetYaxis()->SetTitleFont(82);
  hSpc_left->GetYaxis()->SetLabelFont(82);
  hSpc_left->GetYaxis()->SetTitleOffset(1.7);
  hSpc_left->GetYaxis()->SetLabelOffset(0.02); 
  hSpc_left->GetYaxis()->CenterTitle(); 
  hSpc_left->GetYaxis()->SetLabelSize(0.04);
  hSpc_left->Draw();
  
  h_ana->SetLineColor(kAzure+7);
  h_ana->SetLineColor(kAzure+7);
  h_ana->SetMarkerColor(kAzure+7);
  h_ana->SetMarkerStyle(21);
  h_ana->SetMarkerSize(0.75);
  h_ana->Rebin(5);
  h_ana->Scale(1./5.);
  
  h_ana4->SetLineColor(kRed-4);
  h_ana4->SetLineColor(kRed-4);
  h_ana4->SetMarkerColor(kRed-4);
  h_ana4->SetMarkerStyle(21);
  h_ana4->SetMarkerSize(0.75);
  h_ana4->Rebin(5);
  h_ana4->Scale(1./5.);
  
  printf("Entries %d\n",int(h_ana->GetEntries()));
  printf("Normalization %1.5e\n",sqrt(factor_primakoff12));
  for(int i=0; i<int(h_ana->GetEntries());i++)
    {
     h_ana->GetBinContent(i);
     h_ana->SetBinError(i,sqrt(h_ana->GetBinContent(i))*sqrt(factor_primakoff12));  
     //h_ana->SetBinError(i,10000*sqrt(h_ana->GetBinContent(i)));  /// falta multiplicar por sqrt(1/factorRenormalizacion)
     h_ana4->SetBinError(i,sqrt(h_ana4->GetBinContent(i))*sqrt(factor_primakoff2)); 
    }
  h_ana->Draw("same L");
  h_ana->Draw("same");
  h_ana4->Draw("same L");
  h_ana4->Draw("same");
  
  TLegend *legend = new TLegend(0.55, 0.7, 0.78, 0.8);   
  legend->SetTextFont(82);
  legend->SetTextSize(0.035);
  legend->SetLineColor(1);
  legend->SetLineStyle(1);
  legend->SetLineWidth(1);
  legend->SetFillColor(0);
  legend->SetFillColorAlpha(kWhite, 0);  
  legend->SetLineColor(kWhite);
  legend->AddEntry(hSpc,"Nominal spectrum","l"); 
  legend->AddEntry(h_ana,"P = 1.2 bar","l");
  legend->AddEntry(h_ana4,"P = 2.0 bar","l");
  legend->SetFillColor(kWhite); 
  legend->SetLineColor(kWhite);
  legend->Draw(); 
  
  c1->cd(2)->SetMargin(0.155, 0.05, 0.15, 0.085);
  
  // Style adjustments for left pad
  hSpc_right->SetLineColor(kMagenta+2);
  hSpc_right->SetMarkerColor(kMagenta+2);
  hSpc_right->SetMarkerSize(5);
  hSpc_right->SetStats(0);
  gStyle->SetTitleFont(102, ""); 
  gStyle->SetTitleX(0.57); //title X location
  gStyle->SetTitleY(0.99); //title Y location
  gStyle->SetTitleSize(0.07, "t"); 
  hSpc_right->SetTitle("6 cm Drift Distance");  
  hSpc_right->GetXaxis()->SetTitle("E_{a} [keV]");         
  hSpc_right->GetXaxis()->SetTitleSize(0.04);
  hSpc_right->GetXaxis()->SetTitleFont(82);
  hSpc_right->GetXaxis()->CenterTitle(); 
  hSpc_right->GetXaxis()->SetLabelFont(82);
  hSpc_right->GetXaxis()->SetTitleOffset(1.1);  
  hSpc_right->GetXaxis()->SetLabelSize(0.04);
  hSpc_right->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @ g_{10} [s^{-1}cm^{-2}]");
  hSpc_right->GetYaxis()->SetTitleSize(0.04);
  hSpc_right->GetYaxis()->SetTitleFont(82);
  hSpc_right->GetYaxis()->SetLabelFont(82);
  hSpc_right->GetYaxis()->SetTitleOffset(1.7);
  hSpc_right->GetYaxis()->SetLabelOffset(0.02); 
  hSpc_right->GetYaxis()->CenterTitle(); 
  hSpc_right->GetYaxis()->SetLabelSize(0.04);
  hSpc_right->Draw();
  
  h_ana2->SetLineColor(kAzure+7);
  h_ana2->SetLineColor(kAzure+7);
  h_ana2->SetMarkerColor(kAzure+7);
  h_ana2->SetMarkerStyle(21);
  h_ana2->SetMarkerSize(0.75);
  h_ana2->Rebin(5);
  h_ana2->Scale(1./5.);
  
  h_ana5->SetLineColor(kRed-4);
  h_ana5->SetLineColor(kRed-4);
  h_ana5->SetMarkerColor(kRed-4);
  h_ana5->SetMarkerStyle(21);
  h_ana5->SetMarkerSize(0.75);
  h_ana5->Rebin(5);
  h_ana5->Scale(1./5.);
  printf("Entries %d\n",int(h_ana->GetEntries()));
  printf("Normalization %1.5e\n",sqrt(factor_primakoff12_2));
  for(int i=0; i<int(h_ana2->GetEntries());i++)
    {
     h_ana2->GetBinContent(i);
     h_ana2->SetBinError(i,sqrt(h_ana2->GetBinContent(i))*sqrt(factor_primakoff12_2));  
     //h_ana->SetBinError(i,10000*sqrt(h_ana->GetBinContent(i)));  /// falta multiplicar por sqrt(1/factorRenormalizacion)
     h_ana5->SetBinError(i,sqrt(h_ana5->GetBinContent(i))*sqrt(factor_primakoff2_2)); 
    }
  
  h_ana2->Draw("same L");
  h_ana2->Draw("same");
  h_ana5->Draw("same L");
  h_ana5->Draw("same");
  
  TLegend *legend2 = new TLegend(0.55, 0.7, 0.78, 0.8);   
  legend2->SetTextFont(82);
  legend2->SetTextSize(0.035);
  legend2->SetLineColor(1);
  legend2->SetLineStyle(1);
  legend2->SetLineWidth(1);
  legend2->SetFillColor(0);
  legend2->SetFillColorAlpha(kWhite, 0);  
  legend2->SetLineColor(kWhite);
  legend2->AddEntry(hSpc,"Nominal spectrum","l"); 
  legend2->AddEntry(h_ana2,"P = 1.2 bar","l");
  legend2->AddEntry(h_ana5,"P = 2.0 bar","l");
  legend2->SetFillColor(kWhite); 
  legend2->SetLineColor(kWhite);
  legend2->Draw();  
  
  
  c1->SaveAs("primakoff_analysis.png");  
  c1->SaveAs("primakoff_analysis.eps"); 
  

}


void ABC_analysis(){

  double factor_ABC12=1251.62/987476.;
  double factor_ABC2=1251.62/918010.;
  double factor_ABC12_2=1251.62/895216.;
  double factor_ABC2_2=1251.62/872190.;
  
  TFile *fin = new TFile("ABC_histogram.root");
  TH1D* hSpc = (TH1D*)fin->Get("ABC");
  TH1D* hSpc_left = (TH1D*)hSpc->Clone("hSpc_left");
  TH1D* hSpc_right = (TH1D*)hSpc->Clone("hSpc_right");
  TFile *fin2 = new TFile("ABC_histogram_ana_1.2_l.root");
  TH1F* h_ana = (TH1F*)fin2->Get("h_ABC_ana");
  TFile *fin3 = new TFile("ABC_histogram_ana_1.2_2l.root");
  TH1F* h_ana2 = (TH1F*)fin3->Get("h_ABC_ana2");
  
  TFile *fin4 = new TFile("ABC_histogram_ana_2.0_l.root");
  TH1F* h_ana4 = (TH1F*)fin4->Get("h_ABC_ana");
  TFile *fin5 = new TFile("ABC_histogram_ana_2.0_2l.root");
  TH1F* h_ana5 = (TH1F*)fin5->Get("h_ABC_ana2");
  
  TCanvas * c1 = new TCanvas("c1", "c1", 3000, 1500); 
  
  c1 ->Divide(2,1);
  c1-> cd(1)->SetMargin(0.155, 0.05, 0.15, 0.085);
  
  // Style adjustments for left pad
  hSpc_left->SetLineColor(kMagenta+2);
  hSpc_left->SetMarkerColor(kMagenta+2);
  hSpc_left->SetMarkerSize(5);
  hSpc_left->SetStats(0);
  gStyle->SetTitleFont(102, ""); 
  gStyle->SetTitleX(0.57); //title X location
  gStyle->SetTitleY(0.99); //title Y location
  gStyle->SetTitleSize(0.07, "t"); 
  hSpc_left->SetTitle("3 cm Drift Distance");  
  hSpc_left->GetXaxis()->SetTitle("E_{a} [keV]");         
  hSpc_left->GetXaxis()->SetTitleSize(0.04);
  hSpc_left->GetXaxis()->SetTitleFont(82);
  hSpc_left->GetXaxis()->CenterTitle(); 
  hSpc_left->GetXaxis()->SetLabelFont(82);
  hSpc_left->GetXaxis()->SetTitleOffset(1.1);  
  hSpc_left->GetXaxis()->SetLabelSize(0.04);
  hSpc_left->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} [10^{20}keV^{-1}year^{-1}m^{-2}]");
  hSpc_left->GetYaxis()->SetTitleSize(0.04);
  hSpc_left->GetYaxis()->SetTitleFont(82);
  hSpc_left->GetYaxis()->SetLabelFont(82);
  hSpc_left->GetYaxis()->SetTitleOffset(1.7);
  hSpc_left->GetYaxis()->SetLabelOffset(0.02); 
  hSpc_left->GetYaxis()->CenterTitle(); 
  hSpc_left->GetYaxis()->SetLabelSize(0.04);
  hSpc_left->GetYaxis()->SetRangeUser(0, 3.75);
  hSpc_left->Draw();
  
  h_ana->SetLineColor(kAzure+7);
  h_ana->SetLineColor(kAzure+7);
  h_ana->SetMarkerColor(kAzure+7);
  h_ana->SetMarkerStyle(21);
  h_ana->SetMarkerSize(0.75);
  h_ana->Rebin(5);
  h_ana->Scale(1./5.);
  
  h_ana4->SetLineColor(kRed-4);
  h_ana4->SetLineColor(kRed-4);
  h_ana4->SetMarkerColor(kRed-4);
  h_ana4->SetMarkerStyle(21);
  h_ana4->SetMarkerSize(0.75);
  h_ana4->Rebin(5);
  h_ana4->Scale(1./5.);
  
  printf("Entries %d\n",int(h_ana->GetEntries()));
  printf("Normalization %1.5e\n",sqrt(factor_ABC12));
  for(int i=0; i<int(h_ana->GetEntries());i++)
    {
     h_ana->GetBinContent(i);
     h_ana->SetBinError(i,sqrt(h_ana->GetBinContent(i))*sqrt(factor_ABC12));  
     //h_ana->SetBinError(i,10000*sqrt(h_ana->GetBinContent(i)));  /// falta multiplicar por sqrt(1/factorRenormalizacion)
     h_ana4->SetBinError(i,sqrt(h_ana->GetBinContent(i))*sqrt(factor_ABC2)); 
    }
  
  h_ana->Draw("same L");
  h_ana->Draw("same");
  h_ana4->Draw("same L");
  h_ana4->Draw("same");
  
  TLegend *legend = new TLegend(0.55, 0.7, 0.78, 0.8);   
  legend->SetTextFont(82);
  legend->SetTextSize(0.035);
  legend->SetLineColor(1);
  legend->SetLineStyle(1);
  legend->SetLineWidth(1);
  legend->SetFillColor(0);
  legend->SetFillColorAlpha(kWhite, 0);  
  legend->SetLineColor(kWhite);
  legend->AddEntry(hSpc,"Nominal spectrum","l"); 
  legend->AddEntry(h_ana,"P = 1.2 bar","l");
  legend->AddEntry(h_ana4,"P = 2.0 bar","l");
  legend->SetFillColor(kWhite); 
  legend->SetLineColor(kWhite);
  legend->Draw(); 
  
  c1->cd(2)->SetMargin(0.155, 0.05, 0.15, 0.085);
  
  // Style adjustments for left pad
  hSpc_right->SetLineColor(kMagenta+2);
  hSpc_right->SetMarkerColor(kMagenta+2);
  hSpc_right->SetMarkerSize(5);
  hSpc_right->SetStats(0);
  gStyle->SetTitleFont(102, ""); 
  gStyle->SetTitleX(0.57); //title X location
  gStyle->SetTitleY(0.99); //title Y location
  gStyle->SetTitleSize(0.07, "t"); 
  hSpc_right->SetTitle("6 cm Drift Distance");  
  hSpc_right->GetXaxis()->SetTitle("E_{a} [keV]");         
  hSpc_right->GetXaxis()->SetTitleSize(0.04);
  hSpc_right->GetXaxis()->SetTitleFont(82);
  hSpc_right->GetXaxis()->CenterTitle(); 
  hSpc_right->GetXaxis()->SetLabelFont(82);
  hSpc_right->GetXaxis()->SetTitleOffset(1.1);  
  hSpc_right->GetXaxis()->SetLabelSize(0.04);
  hSpc_right->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @ g_{10} [s^{-1}cm^{-2}]");
  hSpc_right->GetYaxis()->SetTitleSize(0.04);
  hSpc_right->GetYaxis()->SetTitleFont(82);
  hSpc_right->GetYaxis()->SetLabelFont(82);
  hSpc_right->GetYaxis()->SetTitleOffset(1.7);
  hSpc_right->GetYaxis()->SetLabelOffset(0.02); 
  hSpc_right->GetYaxis()->CenterTitle(); 
  hSpc_right->GetYaxis()->SetLabelSize(0.04);
  hSpc_right->Draw();
  
  h_ana2->SetLineColor(kAzure+7);
  h_ana2->SetLineColor(kAzure+7);
  h_ana2->SetMarkerColor(kAzure+7);
  h_ana2->SetMarkerStyle(21);
  h_ana2->SetMarkerSize(0.75);
  h_ana2->Rebin(5);
  h_ana2->Scale(1./5.);
  
  h_ana5->SetLineColor(kRed-4);
  h_ana5->SetLineColor(kRed-4);
  h_ana5->SetMarkerColor(kRed-4);
  h_ana5->SetMarkerStyle(21);
  h_ana5->SetMarkerSize(0.75);
  h_ana5->Rebin(5);
  h_ana5->Scale(1./5.);
  
  printf("Entries %d\n",int(h_ana2->GetEntries()));
  printf("Normalization %1.5e\n",sqrt(factor_ABC12_2));
  for(int i=0; i<int(h_ana2->GetEntries());i++)
    {
     h_ana2->GetBinContent(i);
     h_ana2->SetBinError(i,sqrt(h_ana2->GetBinContent(i))*sqrt(factor_ABC12_2));  
     //h_ana->SetBinError(i,10000*sqrt(h_ana->GetBinContent(i)));  /// falta multiplicar por sqrt(1/factorRenormalizacion)
     h_ana5->SetBinError(i,sqrt(h_ana5->GetBinContent(i))*sqrt(factor_ABC2_2)); 
    }
  
  h_ana2->Draw("same L");
  h_ana2->Draw("same");
  h_ana5->Draw("same L");
  h_ana5->Draw("same");
  
  TLegend *legend2 = new TLegend(0.55, 0.7, 0.78, 0.8);   
  legend2->SetTextFont(82);
  legend2->SetTextSize(0.035);
  legend2->SetLineColor(1);
  legend2->SetLineStyle(1);
  legend2->SetLineWidth(1);
  legend2->SetFillColor(0);
  legend2->SetFillColorAlpha(kWhite, 0);  
  legend2->SetLineColor(kWhite);
  legend2->AddEntry(hSpc,"Nominal spectrum","l"); 
  legend2->AddEntry(h_ana2,"P = 1.2 bar","l");
  legend2->AddEntry(h_ana5,"P = 2.0 bar","l");
  legend2->SetFillColor(kWhite); 
  legend2->SetLineColor(kWhite);
  legend2->Draw();
  
  c1->SaveAs("ABC_analysis.png");  
  c1->SaveAs("ABC_analysis.eps"); 
  

}


void aN_analysis() {

   double factor_aN12=4.56e27/1479879.;
   double factor_aN2=4.56e27/951123.;
   double factor_aN12_2=4.56e27/823255.;
   double factor_aN2_2=4.56e27/548062.;

    TFile *fin = new TFile("aN_histogram.root");
    TH1D* hSpc = (TH1D*)fin->Get("aN");
    TFile *fin2 = new TFile("aN_histogram_ana_1.2_l.root");
    TH1F* h_ana = (TH1F*)fin2->Get("h_aN_ana");
    TFile *fin3 = new TFile("aN_histogram_ana_1.2_2l.root");
    TH1F* h_ana2 = (TH1F*)fin3->Get("h_aN_ana2");
    
    TFile *fin4 = new TFile("aN_histogram_ana_2.0_l.root");
    TH1F* h_ana4 = (TH1F*)fin4->Get("h_aN_ana");
    TFile *fin5 = new TFile("aN_histogram_ana_2.0_2l.root");
    TH1F* h_ana5 = (TH1F*)fin5->Get("h_aN_ana2");
    
    TCanvas * c1 = new TCanvas("c1", "c1", 3000, 1500); 
  
    c1 ->Divide(2,1);
    c1-> cd(1)->SetMargin(0.155, 0.05, 0.15, 0.085);
  
    // Style adjustments for left pad
    h_ana->SetLineColor(kMagenta+2);
    h_ana->SetMarkerColor(kMagenta+2);
    h_ana->SetMarkerSize(5);
    h_ana->SetStats(0);
    gStyle->SetTitleFont(102, ""); 
    gStyle->SetTitleX(0.57); //title X location
    gStyle->SetTitleY(0.99); //title Y location
    gStyle->SetTitleSize(0.06, "t"); 
    h_ana->SetTitle("3 cm Drift Distance");  
    h_ana->GetXaxis()->SetTitle("E_{a} [keV]");         
    h_ana->GetXaxis()->SetTitleSize(0.04);
    h_ana->GetXaxis()->SetTitleFont(82);
    h_ana->GetXaxis()->CenterTitle(); 
    h_ana->GetXaxis()->SetLabelFont(82);
    h_ana->GetXaxis()->SetTitleOffset(1.1);  
    h_ana->GetXaxis()->SetLabelSize(0.04);
    h_ana->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @g_{aN}^{eff} [s^{-1}cm^{-2}]");
    h_ana->GetYaxis()->SetTitleSize(0.039);
    h_ana->GetYaxis()->SetTitleFont(82);
    h_ana->GetYaxis()->SetLabelFont(82);
    h_ana->GetYaxis()->SetTitleOffset(1.5);
    h_ana->GetYaxis()->SetLabelOffset(0.01); 
    h_ana->GetYaxis()->CenterTitle(); 
    h_ana->GetYaxis()->SetLabelSize(0.04);
    //h_ana->Draw();
  
    h_ana->SetLineColor(kAzure-7);
    h_ana->SetLineColor(kAzure-7);
    h_ana->SetMarkerColor(kAzure-7);
    h_ana->SetMarkerStyle(21);
    h_ana->SetMarkerSize(0.675);
    h_ana->Rebin(5);
    h_ana->Scale(1./5.);//*(factor_aN12));
    
    h_ana4->SetLineColor(kRed-4);
    h_ana4->SetLineColor(kRed-4);
    h_ana4->SetMarkerColor(kRed-4);
    h_ana4->SetMarkerStyle(21);
    h_ana4->SetMarkerSize(0.675);
    h_ana4->Rebin(5);
    //h_ana4->Scale((1./5.)*(1479879./951123.));
    h_ana4->Scale(1./5.);//*(factor_aN2));
    
    printf("Entries %d\n",int(h_ana->GetEntries()));
    printf("Normalization %1.5e\n",sqrt(factor_aN12));
    for(int i=0; i<int(h_ana->GetEntries());i++)
    {
     h_ana->GetBinContent(i);
     h_ana->SetBinError(i,sqrt(h_ana->GetBinContent(i))*sqrt(factor_aN12)); 
     h_ana4->SetBinError(i,sqrt(h_ana->GetBinContent(i))*sqrt(factor_aN2));//*sqrt(1479879./951123.));  
    }
    h_ana->GetYaxis()->SetRangeUser(0, 19.0E24);
    h_ana->Draw("same L");
    h_ana->Draw("same");
    //h_ana4->GetYaxis()->SetRangeUser(0, 12.5E24);
    h_ana4->Draw("same L");
    h_ana4->Draw("same");
    
    TF1 * fgaus_11_14 = new TF1("fgaus_11_14.4", "[6]*TMath::Exp(-((x-[7])*(x-[7]))/(2*[8]*[8])) + [0]*TMath::Exp(-((x-[1])*(x-[1]))/(2*[2]*[2])) + [3]*TMath::Exp(-((x-[4])*(x-[4]))/(2*[5]*[5]))", 6.75, 17.);
    
     TF1 * fgaus_11_14_2 = new TF1("fgaus_11_14.4_2", "[6]*TMath::Exp(-((x-[7])*(x-[7]))/(2*[8]*[8])) + [0]*TMath::Exp(-((x-[1])*(x-[1]))/(2*[2]*[2])) + [3]*TMath::Exp(-((x-[4])*(x-[4]))/(2*[5]*[5]))", 6.75, 17.);
    
    //11+14.4 keV fit:
    fgaus_11_14->SetParameter(0, 3.25880e+23 );
    fgaus_11_14->SetParameter(1,1.14543e+01); 
    fgaus_11_14->SetParameter(2, 5.74599e-01);
    fgaus_11_14->SetParameter(3, 5.80382e+24);
    fgaus_11_14->SetParameter(4, 1.43939e+01);
    fgaus_11_14->SetParameter(5, 5.93913e-01);
    fgaus_11_14->SetParameter(6,  7.46774e+23);
    fgaus_11_14->SetParameter(7, 8.05079e+00);
    fgaus_11_14->SetParameter(8,  5.11193e-01);
    h_ana->Fit(fgaus_11_14,"R");
    fgaus_11_14->SetLineColor(kCyan+1); 
    fgaus_11_14->SetLineWidth(2);
    //fgaus_11_14->SetLineStyle(7);
    fgaus_11_14->Draw("same");
    
    fgaus_11_14_2->SetParameter(0, 3.25880e+23 );
    fgaus_11_14_2->SetParameter(1,1.14543e+01); 
    fgaus_11_14_2->SetParameter(2, 5.74599e-01);
    fgaus_11_14_2->SetParameter(3, 5.80382e+24);
    fgaus_11_14_2->SetParameter(4, 1.43939e+01);
    fgaus_11_14_2->SetParameter(5, 5.93913e-01);
    fgaus_11_14_2->SetParameter(6,  7.46774e+23);
    fgaus_11_14_2->SetParameter(7, 8.05079e+00);
    fgaus_11_14_2->SetParameter(8,  5.11193e-01);
    h_ana4->Fit(fgaus_11_14_2,"R");
    fgaus_11_14_2->SetLineColor(kTeal+1); 
    fgaus_11_14_2->SetLineWidth(2);
    //fgaus_11_14_2->SetLineStyle(7);
    fgaus_11_14_2->Draw("same");
  
  
//    // Retrieve fit parameters
//    double mean = fgaus_11_14_2->GetParameter(7); // Mean
//    double meanError = fgaus_11_14_2->GetParError(7); // Error on mean
//    double sigma = fgaus_11_14_2->GetParameter(8); // Sigma
//    double sigmaError = fgaus_11_14_2->GetParError(8); // Error on sigma
//
//    // Calculate FWHM and energy resolution
//    double fwhm = 2.35482 * sigma;
//    double energyResolution = (fwhm * 100) / mean;
//
//    // Calculate errors
//    double fwhmError = 2.35482 * sigmaError;
//    double energyResolutionError = energyResolution * sqrt((fwhmError / fwhm) * (fwhmError / fwhm) + (meanError / mean) * (meanError / mean));
//
//    // Retrieve chi-square and degrees of freedom
//    double chi2 = fgaus_11_14_2->GetChisquare();
//    int ndf = fgaus_11_14_2->GetNDF();
//  
//    // Print values using printf
//    printf("Mean: %f - %f\n", mean, meanError);
//    printf("Sigma: %f - %f\n", sigma, sigmaError);
//    printf("FWHM: %f - %f\n", fwhm, fwhmError);
//    printf("Energy Resolution: %f %% - %f %%\n", energyResolution, energyResolutionError);
//    printf("Chi-square: %f\n", chi2);
//    printf("Degrees of Freedom: %d\n", ndf);

//    // Create TPaveText to display the results
//    TPaveText *pt = new TPaveText(0.2, 0.5, 0.8, 0.8, "NDC");
//    pt->SetTextFont(82);
//    pt->SetTextSize(0.025);
//    pt->SetTextColor(kRed+2);
//    pt->SetFillColor(0);
//    pt->SetBorderSize(1);
//    pt->AddText(Form("Mean: %.2f #pm %.2f keV", mean, meanError));
//    pt->AddText(Form("Resolution: %.2f #pm %.2f %%", energyResolution, energyResolutionError));
//    pt->AddText(Form("Chi-square1: %.2f", chi2));
//    pt->AddText(Form("Chi-square2: %.2f", fgaus_11_14->GetChisquare()));
//    pt->AddText(Form("NDF1: %d", ndf));
//    pt->AddText(Form("NDF2: %d", fgaus_11_14->GetNDF()));
//    pt->Draw();
  
    TLegend *legend = new TLegend(0.25, 0.73, 0.48, 0.87);   
    legend->SetTextFont(82);
    legend->SetTextSize(0.035);
    legend->SetLineColor(1);
    legend->SetLineStyle(1);
    legend->SetLineWidth(1);
    legend->SetFillColor(0);
    legend->SetFillColorAlpha(kWhite, 0);  
    legend->SetLineColor(kWhite);
    legend->AddEntry(h_ana,"P = 1.2 bar","l");
    legend->AddEntry(h_ana4,"P = 2.0 bar","l");
    legend->AddEntry(fgaus_11_14,"Best fit at 1.2 bar","l");
    legend->AddEntry(fgaus_11_14_2,"Best fit at 2.0 bar","l");
    legend->SetFillColor(kWhite); 
    legend->SetLineColor(kWhite);
    legend->Draw(); 
    
    c1->cd(2)->SetMargin(0.155, 0.05, 0.15, 0.085);
    
    // Style adjustments for left pad
    h_ana2->SetLineColor(kMagenta+2);
    h_ana2->SetMarkerColor(kMagenta+2);
    h_ana2->SetMarkerSize(5);
    h_ana2->SetStats(0);
    gStyle->SetTitleFont(102, ""); 
    gStyle->SetTitleX(0.57); //title X location
    gStyle->SetTitleY(0.99); //title Y location
    gStyle->SetTitleSize(0.06, "t"); 
    h_ana2->SetTitle("6 cm Drift Distance");  
    h_ana2->GetXaxis()->SetTitle("E_{a} [keV]");         
    h_ana2->GetXaxis()->SetTitleSize(0.04);
    h_ana2->GetXaxis()->SetTitleFont(82);
    h_ana2->GetXaxis()->CenterTitle(); 
    h_ana2->GetXaxis()->SetLabelFont(82);
    h_ana2->GetXaxis()->SetTitleOffset(1.1);  
    h_ana2->GetXaxis()->SetLabelSize(0.04);
    h_ana2->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @g_{aN}^{eff} [s^{-1}cm^{-2}]");
    h_ana2->GetYaxis()->SetTitleSize(0.039);
    h_ana2->GetYaxis()->SetTitleFont(82);
    h_ana2->GetYaxis()->SetLabelFont(82);
    h_ana2->GetYaxis()->SetTitleOffset(1.5);
    h_ana2->GetYaxis()->SetLabelOffset(0.01); 
    h_ana2->GetYaxis()->CenterTitle(); 
    h_ana2->GetYaxis()->SetLabelSize(0.04);
    h_ana2->Draw();
    
    h_ana2->SetLineColor(kAzure-7);
    h_ana2->SetMarkerColor(kAzure-7);
    h_ana2->SetMarkerStyle(21);
    h_ana2->SetMarkerSize(0.675);
    h_ana2->Rebin(5);
    h_ana2->Scale(1./5.);
    
    h_ana5->SetLineColor(kRed-4);
    h_ana5->SetLineColor(kRed-4);
    h_ana5->SetMarkerColor(kRed-4);
    h_ana5->SetMarkerStyle(21);
    h_ana5->SetMarkerSize(0.675);
    h_ana5->Rebin(5);
    h_ana5->Scale(1./5.);//*(823255./548062.));
    
    printf("Entries %d\n",int(h_ana2->GetEntries()));
    printf("Normalization %1.5e\n",sqrt(factor_aN12_2));
    for(int i=0; i<int(h_ana2->GetEntries());i++)
    {
     h_ana2->GetBinContent(i);
     h_ana2->SetBinError(i,sqrt(h_ana2->GetBinContent(i))*sqrt(factor_aN12_2));  
     h_ana5->SetBinError(i,sqrt(h_ana2->GetBinContent(i))*sqrt(factor_aN2_2)*sqrt(823255./548062.));
    }
    h_ana2->GetYaxis()->SetRangeUser(0, 19.0E24);
    h_ana2->Draw("same");
    //h_ana2->Draw("same L");
    //h_ana5->GetYaxis()->SetRangeUser(0, 12.5E24);
    h_ana5->Draw("same");
    //h_ana5->Draw("same L");
  

  
    TF1 * fgaus_11_14_r = new TF1("fgaus_11_14.4_r", "[6]*TMath::Exp(-((x-[7])*(x-[7]))/(2*[8]*[8])) + [0]*TMath::Exp(-((x-[1])*(x-[1]))/(2*[2]*[2])) + [3]*TMath::Exp(-((x-[4])*(x-[4]))/(2*[5]*[5]))", 6.75, 17.);
    
    TF1 * fgaus_11_14_r2 = new TF1("fgaus_11_14.4_r2", "[6]*TMath::Exp(-((x-[7])*(x-[7]))/(2*[8]*[8])) + [0]*TMath::Exp(-((x-[1])*(x-[1]))/(2*[2]*[2])) + [3]*TMath::Exp(-((x-[4])*(x-[4]))/(2*[5]*[5]))", 6.75, 17.);
    
    //11+14.4 keV fit:
    fgaus_11_14_r->SetParameter(0, 3.74210e+23 );
    fgaus_11_14_r->SetParameter(1,1.14570e+01); 
    fgaus_11_14_r->SetParameter(2, 5.86294e-01);
    fgaus_11_14_r->SetParameter(3, 1.13211e+25);
    fgaus_11_14_r->SetParameter(4, 1.43950e+01 );
    fgaus_11_14_r->SetParameter(5,  5.91512e-01);
    fgaus_11_14_r->SetParameter(6,  9.41700e+23);
    fgaus_11_14_r->SetParameter(7, 8.06360e+00);
    fgaus_11_14_r->SetParameter(8,  4.95613e-01);
    h_ana2->Fit(fgaus_11_14_r,"R");
    fgaus_11_14_r->SetLineColor(kCyan+1); 
    fgaus_11_14_r->SetLineWidth(2);
    //fgaus_11_14_r->SetLineStyle(2);
    fgaus_11_14_r->Draw("same");
    //h_ana_2->Fit("fgaus_11_14.4");
    
    fgaus_11_14_r2->SetParameter(0, 3.74210e+23 );
    fgaus_11_14_r2->SetParameter(1,1.14570e+01); 
    fgaus_11_14_r2->SetParameter(2, 5.86294e-01);
    fgaus_11_14_r2->SetParameter(3, 1.13211e+25);
    fgaus_11_14_r2->SetParameter(4, 1.43950e+01 );
    fgaus_11_14_r2->SetParameter(5,  5.91512e-01);
    fgaus_11_14_r2->SetParameter(6,  9.41700e+23);
    fgaus_11_14_r2->SetParameter(7, 8.06360e+00);
    fgaus_11_14_r2->SetParameter(8,  4.95613e-01);
    h_ana5->Fit(fgaus_11_14_r2,"R");
    fgaus_11_14_r2->SetLineColor(kTeal+1); 
    fgaus_11_14_r2->SetLineWidth(2);
    //fgaus_11_14_r2->SetLineStyle(2);
    fgaus_11_14_r2->Draw("same");
    //h_ana_2->Fit("fgaus_11_14.4_r2");
  
  
   // Retrieve fit parameters
    double mean = fgaus_11_14_r2->GetParameter(7); // Mean
    double meanError = fgaus_11_14_r2->GetParError(7); // Error on mean
    double sigma = fgaus_11_14_r2->GetParameter(8); // Sigma
    double sigmaError = fgaus_11_14_r2->GetParError(8); // Error on sigma

    // Calculate FWHM and energy resolution
    double fwhm = 2.35482 * sigma;
    double energyResolution = (fwhm * 100) / mean;

    // Calculate errors
    double fwhmError = 2.35482 * sigmaError;
    double energyResolutionError = energyResolution * sqrt((fwhmError / fwhm) * (fwhmError / fwhm) + (meanError / mean) * (meanError / mean));

    // Retrieve chi-square and degrees of freedom
    double chi2 = fgaus_11_14_r2->GetChisquare();
    int ndf = fgaus_11_14_r2->GetNDF();
  
  
    // Print values using printf
    printf("Mean: %f - %f\n", mean, meanError);
    printf("Sigma: %f - %f\n", sigma, sigmaError);
    printf("FWHM: %f - %f\n", fwhm, fwhmError);
    printf("Energy Resolution: %f %% - %f %%\n", energyResolution, energyResolutionError);
    printf("Chi-square: %f\n", chi2);
    printf("Degrees of Freedom: %d\n", ndf);
  
    TLegend *legend2 = new TLegend(0.25, 0.73, 0.48, 0.87);   
    legend2->SetTextFont(82);
    legend2->SetTextSize(0.035);
    legend2->SetLineColor(1);
    legend2->SetLineStyle(1);
    legend2->SetLineWidth(1);
    legend2->SetFillColor(0);
    legend2->SetFillColorAlpha(kWhite, 0);  
    legend2->SetLineColor(kWhite);
    legend2->AddEntry(h_ana2,"P = 1.2 bar","l");
    legend2->AddEntry(h_ana5,"P = 2.0 bar","l");
    legend2->AddEntry(fgaus_11_14_r,"Best fit at 1.2","l");
    legend2->AddEntry(fgaus_11_14_r2,"Best fit at 2.0","l");
    legend2->SetFillColor(kWhite); 
    legend2->SetLineColor(kWhite);
    legend2->Draw(); 
    
  
    c1->SaveAs("aN_analysis.png");  
    c1->SaveAs("aN_analysis.eps"); 
}




