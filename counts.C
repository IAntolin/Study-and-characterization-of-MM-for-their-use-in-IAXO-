
//para L = l con análisis
void sum1(float pressure, int number){

  //float pressure = 10.0; //keV
  for(float energy=0.25;energy<=16.00;energy+=0.25) {
    TFile * fin = new TFile (Form("simFiles_effP%d/Run_%.1f_%.2f.root", number, pressure, energy), "read");
    TTree * t = (TTree*)fin ->Get("AnalysisTree;2");
    
    //TCanvas * c1 = new TCanvas("c1","areas",1700,1100);
    TH1F * h = new TH1F(Form("histo%.2f", energy ),Form("histograma%.2f", energy), 200, 0, 20);
    
    t->Draw(Form("hitsAnaBefore_energy>>histo%.2f", energy), "", "goff"); 
    
    //std::cout << energy << std::endl;
    std::cout << h->Integral(h->FindFixBin(energy-0.05), h->FindFixBin(energy+0.25)) << std::endl;

  }
}


//Para L = l sin análisis
void sum1_sin(float pressure, int number) {
    for (float energy = 0.25; energy <= 16.00; energy += 0.25) {
        TFile *fin = new TFile(Form("simFiles_effP%d/RestG4_%.1f_%.2f.root", number, pressure, energy), "read");
        TTree *t = (TTree *)fin->Get("EventTree;1");

        // Create histogram
        TH1F *h = new TH1F(Form("histo%.2f", energy), Form("histograma%.2f", energy), 200, 0, 20);

        // Set branch address
        TRestGeant4Event *branch = nullptr;
        t->SetBranchAddress("TRestGeant4EventBranch", &branch);

        // Loop over entries in the tree and fill histogram
        int nEntries = t->GetEntries();
        for (int i = 0; i < nEntries; ++i) {
            //t->GetEvent(i);
            t->GetEntry(i);
            h->Fill(branch->GetSensitiveVolumeEnergy());
        }
        std::cout << h->Integral(h->FindFixBin(energy-0.05), h->FindFixBin(energy+0.25)) << std::endl;

    }
}


//Para L = 2l
void sum2(float pressure, int number) {
    for (float energy = 0.25; energy <= 16.00; energy += 0.25) {
        TFile *fin = new TFile(Form("simFiles_effP%dL2/RestG4_%.1f_%.2f.root", number, pressure, energy), "read");
        TTree *t = (TTree *)fin->Get("EventTree;1");

        // Create histogram
        TH1F *h = new TH1F(Form("histo%.2f", energy), Form("histograma%.2f", energy), 200, 0, 20);

        // Set branch address
        TRestGeant4Event *branch = nullptr;
        t->SetBranchAddress("TRestGeant4EventBranch", &branch);

        // Loop over entries in the tree and fill histogram
        int nEntries = t->GetEntries();
        for (int i = 0; i < nEntries; ++i) {
            //t->GetEvent(i);
            t->GetEntry(i);
            h->Fill(branch->GetSensitiveVolumeEnergy());
        }
        std::cout << h->Integral(h->FindFixBin(energy-0.05), h->FindFixBin(energy+0.25)) << std::endl;

    }
}




double I_primakoff = 5.21959E13; // l -> 1.2 bar: 675772, 2.0 bar:  611872 // 2l -> 1.2 bar:  598789, 2.0 bar: 579520 

void fluxes_primakoff() {

        double total_events[4] = {675772., 611872., 598789., 579520.};
        TString size[4] = {"l", "l", "2l", "2l"};
        double pressure[4] = {1.2, 2.0, 1.2, 2.0};
        
        for(int i = 0; i<4;i++){
        
          TCanvas *canvasc = new TCanvas(Form("canvasc%d", i), Form("fluxxes%d", i), 2300, 1200);
     
          TFile *fin = new TFile(Form("simFiles_primakoff/RestG4_%.1f_%s.root", pressure[i], size[i].Data()), "read");
          TTree *t = (TTree *)fin->Get("EventTree;1");
  
          // Create histogram
          TH1D *h = new TH1D(Form("histo%d", i), Form("histograma%d", i), 1420, 0, 10);
  
          // Set branch address
          TRestGeant4Event *branch = nullptr;
          t->SetBranchAddress("TRestGeant4EventBranch", &branch);
  
          // Loop over entries in the tree and fill histogram
          int nEntries = t->GetEntries();
          for (int j = 0; j < nEntries; ++j) {
              //t->GetEvent(j);
              t->GetEntry(j);
              h->Fill(branch->GetSensitiveVolumeEnergy());
          } 
          
          // Get the number of bins in the histogram
          int nbins = h->GetNbinsX();
  
          // Define the scaling factor
          double scaleFactor = 5.21959E13 / total_events[i];
          
          // Loop over each bin and scale the bin content without affecting the error
          for (int k = 1; k <= nbins; ++k) {
              double binContent = h->GetBinContent(k);
              h->SetBinContent(k, binContent * scaleFactor);
          }
          
          //h->SetStats(0);
          h->GetXaxis()->SetTitle("E_{a} [keV]");
          h->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @g_{10} [keV^{-1}s^{-1}cm^{-2}]");
          h->Draw();
          
          TFile * fout = new TFile(Form("histograms/Primakoff_histogram_%.1f_%s.root", pressure[i], size[i].Data()), "recreate"); 
          h->Write();
          fout->Close();
         // canvasc->SaveAs(Form("simFiles_primakoff/Primakoff_%.1f_2l.png", pressure));
        }
}


double I_ABC = 1251.62 ;  // l -> 1.2 bar: 987476, 2.0 bar:  918010 // 2l -> 1.2 bar: 895216, 2.0 bar:  872190

void fluxes_ABC() {

    double total_events[4] = {987476., 918010., 895216., 872190.};
    TString size[4] = {"l", "l", "2l", "2l"};
    double pressure[4] = {1.2, 2.0, 1.2, 2.0};
    
    for(int i = 0; i<4;i++){
  
      TCanvas *canvasc = new TCanvas(Form("canvasc%d", i), Form("fluxxes%d", i), 2300, 1200);
     
      TFile *fin = new TFile(Form("simFiles_ABC/RestG4_%.1f_%s.root", pressure[i], size[i].Data()), "read");
      TTree *t = (TTree *)fin->Get("EventTree;1");
  
      // Create histogram
      TH1D *h = new TH1D(Form("histo%d", i), Form("histograma%d", i), 1800, 0, 12);
  
      // Set branch address
      TRestGeant4Event *branch = nullptr;
      t->SetBranchAddress("TRestGeant4EventBranch", &branch);
  
      // Loop over entries in the tree and fill histogram
      int nEntries = t->GetEntries();
      for (int j = 0; j < nEntries; ++j) {
          //t->GetEvent(j);
          t->GetEntry(j);
          h->Fill(branch->GetSensitiveVolumeEnergy());
      }
      
      // Get the number of bins in the histogram
      int nbins = h->GetNbinsX();
  
      // Define the scaling factor
      double scaleFactor = 1251.62/total_events[i];
      
      // Loop over each bin and scale the bin content without affecting the error
      for (int k = 1; k <= nbins; ++k) {
          double binContent = h->GetBinContent(k);
          h->SetBinContent(k, binContent * scaleFactor);
      }
      
      h->SetStats(0);
      h->GetXaxis()->SetTitle("E_{a} [keV]");
      h->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @g_{ae} [10^{20}keV^{-1}year^{-1}m^{-2}]");
      h->Draw();
      TFile * fout = new TFile(Form("histograms/ABC_histogram_%.1f_%s.root", pressure[i], size[i].Data()), "recreate"); 
      h->Write();
      fout->Close();
      
      }

}



//200000 eventos, en vez de 500000!!
double I_aN = 4.56E27;  // l -> 1.2 bar: 1479879, 2.0bar:  951123 // 2l -> 1.2 bar: 823255  , 2.0bar: 548062 

void fluxes_aN() {

    double total_events[4] = {1479879., 951123., 823255., 548062.};
    TString size[4] = {"l", "l", "2l", "2l"};
    double pressure[4] = {1.2, 2.0, 1.2, 2.0};
    
    for(int i = 0; i<4;i++){

        //h_aN->GetXaxis()->SetRangeUser(14.3, 14.5);
        TCanvas *canvasc = new TCanvas(Form("canvasc%d", i), Form("fluxxes%d", i), 2300, 1200);
        TFile *fin = new TFile(Form("simFiles_aN/RestG4_%.1f_%s.root", pressure[i], size[i].Data()), "read");
        TTree *t = (TTree *)fin->Get("EventTree;1");

        // Create histogram
        TH1D *h = new TH1D(Form("histo%d", i), Form("histograma%d", i), 160000, 0, 16);

        // Set branch address
        TRestGeant4Event *branch = nullptr;
        t->SetBranchAddress("TRestGeant4EventBranch", &branch);

        // Loop over entries in the tree and fill histogram
        int nEntries = t->GetEntries();
        for (int j = 0; j < nEntries; ++j) {
            //t->GetEvent(j);
            t->GetEntry(j);
            h->Fill(branch->GetSensitiveVolumeEnergy());
        }
        
        // Get the number of bins in the histogram
        int nbins = h->GetNbinsX();

        // Define the scaling factor
        double scaleFactor = 4.56E27/total_events[i];
        
        // Loop over each bin and scale the bin content without affecting the error
        for (int k = 1; k <= nbins; ++k) {
            double binContent = h->GetBinContent(k);
            h->SetBinContent(k, binContent * scaleFactor);
        }
        h->SetStats(0);
        h->GetXaxis()->SetTitle("E_{a} [keV]");
        h->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @g_{aN} [keV^{-1}s^{-1}cm^{-2}]");
        h->Draw();
        TFile * fout = new TFile(Form("histograms/aN_histogram_%.1f_%s.root", pressure[i], size[i].Data()), "recreate"); 
        h->Write();
        fout->Close();
    }
    

}


void fluxes_aN_l_12() {

    double total_events = 1479879.;
    double pressure = 1.2;
    

    //h_aN->GetXaxis()->SetRangeUser(14.3, 14.5);
    TCanvas *canvasc = new TCanvas("canvasc", "fluxxes", 2300, 1200);
    TFile *fin = new TFile(Form("simFiles_aN/RestG4_%.1f_l.root", pressure), "read");
    TTree *t = (TTree *)fin->Get("EventTree;1");

    // Create histogram
    TH1D *h = new TH1D("histo", "histograma", 1000, 0, 16); //lo pongo así para dibujarlo con el del análisis simplemente

    // Set branch address
    TRestGeant4Event *branch = nullptr;
    t->SetBranchAddress("TRestGeant4EventBranch", &branch);

    // Loop over entries in the tree and fill histogram
    int nEntries = t->GetEntries();
    for (int j = 0; j < nEntries; ++j) {
        //t->GetEvent(j);
        t->GetEntry(j);
        h->Fill(branch->GetSensitiveVolumeEnergy());
    }
    
    // Get the number of bins in the histogram
    int nbins = h->GetNbinsX();

    // Define the scaling factor
    double scaleFactor = 4.56E27/total_events;
    
    // Loop over each bin and scale the bin content without affecting the error
    for (int k = 1; k <= nbins; ++k) {
        double binContent = h->GetBinContent(k);
        h->SetBinContent(k, binContent * scaleFactor);
    }
    h->SetStats(0);
    h->GetXaxis()->SetTitle("E_{a} [keV]");
    h->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @g_{aN} [keV^{-1}s^{-1}cm^{-2}]");
    h->Draw();
    TFile * fout = new TFile(Form("histograms/aN_histogram_%.1f_new.root", pressure), "recreate"); 
    h->Write();
    fout->Close();
    canvasc->SaveAs("aN_differential_flux_new.png");
    
}



//para primakoff en L = l y L = 2l con análisis
void primakoff_ana(float pressure) {
    // Open the first ROOT file and retrieve the tree
    TFile *fin = new TFile(Form("simFiles_primakoff/Run_%.1f_l.root", pressure), "read");
    TTree *t = (TTree*)fin->Get("AnalysisTree;2");

    // Open the second ROOT file and retrieve the tree
    TFile *fin2 = new TFile(Form("simFiles_primakoff/Run_%.1f_2l.root", pressure), "read");
    TTree *t2 = (TTree*)fin2->Get("AnalysisTree;2");
   
    // Create and draw the first histogram
    TCanvas *canvasc = new TCanvas("canvasc", "canvas", 2300, 1200);
    TH1F *h = new TH1F("h_primakoff_ana", "h_primakoff_ana", 1420, 0, 10);
    t->Draw("hitsAnaAfterEDiffusion_energy>>h_primakoff_ana", "", "goff");  //hitsReadoutAnalysis_readoutEnergy

    // Create and draw the second histogram
    TCanvas *canvasc2 = new TCanvas("canvasc2", "canvas2", 2300, 1200);
    TH1F *h2 = new TH1F("h_primakoff_ana2", "h_primakoff_ana2", 1420, 0, 10);
    t2->Draw("hitsAnaAfterEDiffusion_energy>>h_primakoff_ana2", "", "goff");

    // Scale the first histogram
    int nbins = h->GetNbinsX();
    double scaleFactor = 5.21959E13 / 611872.;  //cambiar
    for (int k = 1; k <= nbins; ++k) {
        double binContent = h->GetBinContent(k);
        h->SetBinContent(k, binContent * scaleFactor);
    }

    // Scale the second histogram
    int nbins2 = h2->GetNbinsX();
    double scaleFactor2 = 5.21959E13 /579520.;  //cambiar
    for (int kk = 1; kk <= nbins2; ++kk) {
        double binContent2 = h2->GetBinContent(kk);
        h2->SetBinContent(kk, binContent2 * scaleFactor2);
    }

    // Customize and draw the first histogram
    h->SetStats(0);
    h->GetXaxis()->SetTitle("E_{a} [keV]");
    h->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @g_{10} [keV^{-1}s^{-1}cm^{-2}]");
    h->Draw();

    // Save the first canvas and histogram
    canvasc->Update();
    TFile *fout = new TFile(Form("histograms/Primakoff_histogram_ana_%.1f_l.root", pressure), "recreate");
    h->Write();
    fout->Close();
    canvasc->SaveAs(Form("histograms/Primakoff_ana_%.1f_l.png", pressure));

    // Customize and draw the second histogram
    h2->SetStats(0);
    h2->GetXaxis()->SetTitle("E_{a} [keV]");
    h2->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @g_{10} [keV^{-1}s^{-1}cm^{-2}]");
    h2->Draw();

    // Save the second canvas and histogram
    TFile *fout2 = new TFile(Form("histograms/Primakoff_histogram_ana_%.1f_2l.root", pressure), "recreate");
    h2->Write();
    fout2->Close();
    canvasc2->SaveAs(Form("histograms/Primakoff_ana_%.1f_2l.png", pressure));
    
    fin->Close();
    fin2->Close();
}



//para ABC en L = l con análisis
void ABC_ana(float pressure){


  TFile * fin = new TFile (Form("simFiles_ABC/Run_%.1f_l.root", pressure), "read");
  TTree * t = (TTree*)fin ->Get("AnalysisTree;2");
  
  TCanvas *canvasc = new TCanvas("canvasc", "canvas", 2300, 1200);
  TH1F * h = new TH1F("h_ABC_ana", "h_ABC_ana", 1800, 0, 12);
  
  t->Draw("hitsAnaAfterEDiffusion_energy>>h_ABC_ana", "", "goff"); //hitsReadoutAnalysis_readoutEnergy
  
  // Get the number of bins in the histogram
  int nbins = h->GetNbinsX();

  // Define the scaling factor
  double scaleFactor = 1251.62 / 918010.;  //cambiar
  
  // Loop over each bin and scale the bin content without affecting the error
  for (int k = 1; k <= nbins; ++k) {
      double binContent = h->GetBinContent(k);
      h->SetBinContent(k, binContent * scaleFactor);
  }
  
  h->SetStats(0);
  h->GetXaxis()->SetTitle("E_{a} [keV]");
  h->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @g_{10} [keV^{-1}s^{-1}cm^{-2}]");
  h->Draw();
  
  TFile * fout = new TFile(Form("histograms/ABC_histogram_ana_%.1f_l.root", pressure), "recreate"); 
  h->Write();
  fout->Close();
  canvasc->SaveAs(Form("histograms/ABC_ana_%.1f_l.png", pressure));
  

}


//para ABC en L = 2l con análisis
void ABC_ana2(float pressure){


  TFile * fin = new TFile (Form("simFiles_ABC/Run_%.1f_2l.root", pressure), "read");
  TTree * t = (TTree*)fin ->Get("AnalysisTree;2");
  
  TCanvas *canvasc = new TCanvas("canvasc", "canvas", 2300, 1200);
  TH1F * h = new TH1F("h_ABC_ana2", "h_ABC_ana2", 1800, 0, 12);
  
  t->Draw("hitsAnaAfterEDiffusion_energy>>h_ABC_ana2", "", "goff"); 
  
  // Get the number of bins in the histogram
  int nbins = h->GetNbinsX();

  // Define the scaling factor
  double scaleFactor = 1251.62 / 872190.;  //cambiar
  
  // Loop over each bin and scale the bin content without affecting the error
  for (int k = 1; k <= nbins; ++k) {
      double binContent = h->GetBinContent(k);
      h->SetBinContent(k, binContent * scaleFactor);
  }
  
  h->SetStats(0);
  h->GetXaxis()->SetTitle("E_{a} [keV]");
  h->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @g_{10} [keV^{-1}s^{-1}cm^{-2}]");
  h->Draw();
  
  TFile * fout = new TFile(Form("histograms/ABC_histogram_ana_%.1f_2l.root", pressure), "recreate"); 
  h->Write();
  fout->Close();
  canvasc->SaveAs(Form("histograms/ABC_ana_%.1f_2l.png", pressure));
  

}


//para aN en L = l con análisis
void aN_ana(float pressure){


  TFile * fin = new TFile (Form("simFiles_aN/Run_%.1f_l.root", pressure), "read");
  TTree * t = (TTree*)fin ->Get("AnalysisTree;2");
  
  TCanvas *canvasc = new TCanvas("canvasc", "canvas", 2300, 1200);
  TH1F * h = new TH1F("h_aN_ana", "h_aN_ana", 1000, 0, 17);
  
  t->Draw("hitsAnaAfterEDiffusion_energy>>h_aN_ana", "", "goff"); 
  
  // Get the number of bins in the histogram
  int nbins = h->GetNbinsX();

  // Define the scaling factor
  double scaleFactor = 4.56E27 / 951123.;  //cambiar
  
  // Loop over each bin and scale the bin content without affecting the error
  for (int k = 1; k <= nbins; ++k) {
      double binContent = h->GetBinContent(k);
      h->SetBinContent(k, binContent * scaleFactor);
  }
  
  h->SetStats(0);
  h->GetXaxis()->SetTitle("E_{a} [keV]");
  h->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @g_{10} [keV^{-1}s^{-1}cm^{-2}]");
  h->Draw();
  
  TFile * fout = new TFile(Form("histograms/aN_histogram_ana_%.1f_l.root", pressure), "recreate"); 
  h->Write();
  fout->Close();
  canvasc->SaveAs(Form("histograms/aN_ana_%.1f_l.png", pressure)); 
  

}


//para aN en L = 2l con análisis
void aN_ana2(float pressure){


  TFile * fin = new TFile (Form("simFiles_aN/Run_%.1f_2l.root", pressure), "read");
  TTree * t = (TTree*)fin ->Get("AnalysisTree;2");
  
  TCanvas *canvasc = new TCanvas("canvasc", "canvas", 2300, 1200);
  TH1F * h = new TH1F("h_aN_ana2", "h_aN_ana2", 1000, 0, 17);  //rebinned here
  
  t->Draw("hitsAnaAfterEDiffusion_energy>>h_aN_ana2", "", "goff"); 
  
  // Get the number of bins in the histogram
  int nbins = h->GetNbinsX();

  // Define the scaling factor
  double scaleFactor = 4.56E27 / 548062.;  //cambiar
  
  // Loop over each bin and scale the bin content without affecting the error
  for (int k = 1; k <= nbins; ++k) {
      double binContent = h->GetBinContent(k);
      h->SetBinContent(k, binContent * scaleFactor);
  }
  
  h->SetStats(0);
  h->GetXaxis()->SetTitle("E_{a} [keV]");
  h->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @g_{10} [keV^{-1}s^{-1}cm^{-2}]");
  h->Draw();
  
  TFile * fout = new TFile(Form("histograms/aN_histogram_ana_%.1f_2l.root", pressure), "recreate"); 
  h->Write();
  fout->Close();
  canvasc->SaveAs(Form("histograms/aN_ana_%.1f_2l.png", pressure)); 
  

}