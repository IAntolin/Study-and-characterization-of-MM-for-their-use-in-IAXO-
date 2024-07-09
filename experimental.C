
void experimental_cal(){

 TFile *fin = new TFile("R02009_Spectra_hits_EnergyCal.root");
 TH1F* h = (TH1F*)fin->Get("spectra_hits;1");
 TFile *fin1 = new TFile("R02009_Hitmap_hits.root");
 TH2F* h1 = (TH2F*)fin1->Get("hitmap_hits;1");
 
 TCanvas *c1 = new TCanvas("c1", "c1", 3000, 1500);
 
 c1->Divide(2,1);
 c1->cd(1)->SetMargin(0.155, 0.02, 0.15, 0.085);
 
  // Style adjustments for left pad
  h->SetStats(0);
  h->SetLineColor(kViolet+7);
  //h->SetMarkerColor(kViolet+7);
  h->SetMarkerSize(5);
  h->SetStats(0);
  gStyle->SetTitleFont(102, ""); 
  gStyle->SetTitleX(0.57); //title X location
  gStyle->SetTitleY(0.99); //title Y location
  gStyle->SetTitleSize(0.07, "t"); 
  h->SetTitle("");  
  h->GetXaxis()->SetTitle("E [keV]");         
  h->GetXaxis()->SetTitleSize(0.04);
  h->GetXaxis()->SetTitleFont(82);
  h->GetXaxis()->CenterTitle(); 
  h->GetXaxis()->SetLabelFont(82);
  h->GetXaxis()->SetTitleOffset(1.1);  
  h->GetXaxis()->SetLabelSize(0.04);
  h->GetYaxis()->SetTitle("Counts per channel");
  h->GetYaxis()->SetTitleSize(0.04);
  h->GetYaxis()->SetTitleFont(82);
  h->GetYaxis()->SetLabelFont(82);
  h->GetYaxis()->SetTitleOffset(2.2);
  h->GetYaxis()->SetLabelOffset(0.02); 
  h->GetYaxis()->CenterTitle(); 
  h->GetYaxis()->SetLabelSize(0.04);
  h->GetXaxis()->SetRangeUser(0,14.6);
  h->SetMarkerColor(kViolet+7);
  h->SetMarkerStyle(21);
  h->SetMarkerSize(0.5);
  h->Draw();
  
    printf("Entries %d\n",int(h->GetEntries()));
    for(int i=0; i<int(h->GetEntries());i++)
      {
       h->GetBinContent(i);
       h->SetBinError(i,sqrt(h->GetBinContent(i)));
      }
    h->Draw("same L");
    
    
  //TF1 * fgaus = new TF1("fgaus","[0]*TMath::Exp(-((x-[1])*(x-[1]))/(2*[2]*[2]))", 5, 6.8);
   TF1 * fgaus = new TF1("fgaus","[0]*TMath::Exp(-((x-[1])*(x-[1]))/(2*[2]*[2]))+[3]*TMath::Exp(-((x-[4])*(x-[4]))/(2*[5]*[5]))+ [6]+[7]*x+[8]*x*x", 1.75, 7.75);
    
    
  fgaus->SetParameter(0, 1.07481e+04);
  fgaus->FixParameter(1, 5.96816e+00);
  fgaus->SetParameter(2, 7.30876e-01);
  fgaus->SetParameter(3, 1.04529e+03);
  fgaus->FixParameter(4, 2.81444e+00);
  fgaus->SetParameter(5, 6.49369e-01);
    fgaus->SetParameter(6, 1.07481e+04);
    fgaus->FixParameter(7, 5.96816e+00);
    fgaus->SetParameter(8, 7.30876e-01);
    
    h->Fit(fgaus,"R");
  fgaus->SetLineColor(kRed+1);
  fgaus->SetLineStyle(7);
  fgaus->Draw("same");
  
    TF1 * fbckg = new TF1("fbckg"," [0]+[1]*x+[2]*x*x", 10, 14);

    fbckg->SetParameter(0, 7.52575e+02);
    fbckg->FixParameter(1, 5.96816e+00);
    fbckg->SetParameter(2, 7.30876e-01);
    fbckg->SetLineColor(kGreen+1);
    fbckg->SetLineStyle(7);
    h->Fit(fbckg,"R");

    fbckg->Draw("same");

    
  TLegend *legend = new TLegend(0.68, 0.65, 0.85, 0.7);
  legend->SetTextFont(82);
  legend->SetTextSize(0.035);
  legend->SetLineColor(1);
  legend->SetLineStyle(1);
  legend->SetLineWidth(1);
  legend->SetFillColor(0);
  legend->SetFillColorAlpha(kWhite, 0);  
  legend->SetLineColor(kWhite);
  legend->AddEntry(h,"Data","lp");
  legend->AddEntry(fgaus,"Best fit","l");
  legend->SetFillColor(kWhite);
  legend->SetLineColor(kWhite);
  legend->Draw(); 

  c1->cd(1)->SetTopMargin(0.2);
  c1->cd(1)->SetLeftMargin(0.2);
  c1->cd(1)->SetRightMargin(0.10);
    
  double mean = fgaus->GetParameter(1);
  double sigma = fgaus->GetParameter(2);
  double fwhm = 2.35482 * sigma;
  double energyResolution = (fwhm * 100) / mean;
  printf("Energy resolution: %f\n", energyResolution);
  
  c1->cd(2)->SetMargin(0.155, 0.02, 0.16, 0.085);
  
  // Style adjustments for right pad
  //h1->SetLineColor(kMagenta+2);
  h1->SetStats(0);
  h1->SetMarkerStyle(21);
  h1->SetMarkerColor(kBlue-2);
  h1->SetMarkerSize(1);
  gStyle->SetTitleFont(102, ""); 
  h1->SetTitle("");  
  h1->GetXaxis()->SetTitle("X hits");         
  h1->GetXaxis()->SetTitleSize(0.04);
  h1->GetXaxis()->SetTitleFont(82);
  h1->GetXaxis()->CenterTitle(); 
  h1->GetXaxis()->SetLabelFont(82);
  h1->GetXaxis()->SetTitleOffset(1.1);  
  h1->GetXaxis()->SetLabelSize(0.04);
  h1->GetYaxis()->SetTitle("Y hits");
  h1->GetYaxis()->SetTitleSize(0.04);
  h1->GetYaxis()->SetTitleFont(82);
  h1->GetYaxis()->SetLabelFont(82);
  h1->GetYaxis()->SetTitleOffset(1.8);
  h1->GetYaxis()->SetLabelOffset(0.02); 
  h1->GetYaxis()->CenterTitle(); 
  h1->GetYaxis()->SetLabelSize(0.04); 
  h1->GetZaxis()->SetTitle("Intensity");
  h1->GetZaxis()->SetTitleSize(0.04);
  h1->GetZaxis()->SetTitleFont(82);
  h1->GetZaxis()->SetLabelFont(82);
  h1->GetZaxis()->SetTitleOffset(1.8);
  h1->GetZaxis()->SetLabelOffset(0.02);
  h1->GetZaxis()->CenterTitle();
  h1->GetZaxis()->SetLabelSize(0.04);
    
    h1->Draw("COLZ");
  /*
  TLegend *legend2 = new TLegend(0.65, 0.85, 0.9, 0.9);
  legend2->SetTextFont(82);
  legend2->SetTextSize(0.034);
  legend2->SetLineColor(1);
  legend2->SetLineStyle(1);
  legend2->SetLineWidth(1);
  legend2->SetFillColor(0);
  legend2->SetFillColorAlpha(kWhite, 0);  
  legend2->SetLineColor(kWhite);
  legend2->AddEntry(h1,"Scatter plot","p");
  legend2->SetFillColor(kWhite);
  legend2->SetLineColor(kWhite);
  legend2->Draw();
   */
  c1->cd(2)->SetTopMargin(0.2);
  c1->cd(2)->SetLeftMargin(0.13);
  c1->cd(2)->SetRightMargin(0.18);
    
  c1->SaveAs("calibracion.png");
  c1->SaveAs("calibracion.eps");

}


void simulations_cal() {

    // Open the first ROOT file and retrieve the tree
    TFile *fin = new TFile("../simulaciones/simFiles_Lab/Run_Laboratory_20.root", "read");
    TTree *t = (TTree*)fin->Get("AnalysisTree;2");
    TFile *fin2 = new TFile("../simulaciones/simFiles_Lab/Run_Laboratory_30.root", "read");
    TTree *t2 = (TTree*)fin2->Get("AnalysisTree;2");
    TFile *fin3 = new TFile("R02009_Spectra_hits_EnergyCal.root");
    TH1F* h3 = (TH1F*)fin3->Get("spectra_hits;1");
   
    // Create and draw the first histogram
    TCanvas *canvasc = new TCanvas("canvasc", "canvas", 1200, 1200);
    canvasc->cd()->SetMargin(0.2, 0.03, 0.15, 0.1);
    TH1F *h = new TH1F("h", "h", 200, 0, 15);
    t->Draw("hitsAnaAfterEDiffusion_energy>>h", "", "goff");
    TH1F *h2 = new TH1F("h2", "h2", 200, 0, 15);
    t2->Draw("hitsAnaAfterEDiffusion_energy>>h2", "", "goff");
    
    // Style adjustments for the first histogram (h)
    h->SetLineColor(kRed+2);
    h->SetMarkerColor(kRed+2);
    h->SetMarkerStyle(21);
    h->SetMarkerSize(0.5);
    h->SetStats(0);
    gStyle->SetTitleFont(102, ""); 
    gStyle->SetTitleX(0.57); //title X location
    gStyle->SetTitleY(0.99); //title Y location
    gStyle->SetTitleSize(0.07, "t"); 
    h->SetTitle("");  
    h->GetXaxis()->SetTitle("E [keV]");         
    h->GetXaxis()->SetTitleSize(0.04);
    h->GetXaxis()->SetTitleFont(82);
    h->GetXaxis()->CenterTitle(); 
    h->GetXaxis()->SetLabelFont(82);
    h->GetXaxis()->SetTitleOffset(1.2);  
    h->GetXaxis()->SetLabelSize(0.04);
    h->GetYaxis()->SetTitle("counts per channel");
    h->GetYaxis()->SetTitleSize(0.035);
    h->GetYaxis()->SetTitleFont(82);
    h->GetYaxis()->SetLabelFont(82);
    h->GetYaxis()->SetTitleOffset(2.6);
    h->GetYaxis()->SetLabelOffset(0.02); 
    h->GetYaxis()->CenterTitle(); 
    h->GetYaxis()->SetLabelSize(0.04);
    
    // Set bin errors
    for(int i = 0; i <= h->GetNbinsX(); i++) {
        h->SetBinError(i, sqrt(h->GetBinContent(i)));
        h2->SetBinError(i, sqrt(h2->GetBinContent(i)));
        h3->SetBinError(i, sqrt(h2->GetBinContent(i)));
    }
    
    h->Draw("E1 P");  // Draw first histogram with errors and markers

    // Style adjustments for the second histogram (h2)
    h2->SetLineColor(kOrange+7);
    h2->SetMarkerColor(kOrange+7);
    h2->SetMarkerStyle(21);
    h2->SetMarkerSize(0.5);
    h2->Draw("same E1 P");  // Draw second histogram with errors and markers
    h3->Draw("same");
    
    // Add legend
    TLegend *legend = new TLegend(0.59, 0.75, 0.8, 0.85);
    legend->SetTextFont(82);
    legend->SetTextSize(0.03);
    legend->SetLineColor(1);
    legend->SetLineStyle(1);
    legend->SetLineWidth(1);
    legend->SetFillColor(0);
    legend->SetFillColorAlpha(kWhite, 0);  
    legend->SetLineColor(kWhite);
    legend->AddEntry(h, "ER of 20% at 5.9keV", "lp");
    legend->AddEntry(h2, "ER of 30% at 5.9keV", "lp");
    legend->AddEntry(h3, "Experimental data", "lp");
    legend->SetFillColor(kWhite); 
    legend->SetLineColor(kWhite);
    legend->Draw(); 
    
    // Save canvas
    canvasc->SaveAs("simulations_calibration.png"); 
}

