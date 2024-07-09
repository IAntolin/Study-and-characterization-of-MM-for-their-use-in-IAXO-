{
//=========Macro generated from canvas: canvasc/Trackings for gaee
//=========  (Wed Nov 22 21:34:51 2023) by ROOT version5.34/08
   TCanvas *canvasc = new TCanvas("canvasc", "Trackings for gaee",394,69,900,700);  // not in bash mode!!
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   canvasc->SetHighLightColor(2);
   canvasc->Range(-1.273625,-0.3487334,12.46263,3.138601);
   canvasc->SetBorderSize(2);
   canvasc->SetFrameFillColor(0);
   
    
    
    FILE *flist= fopen("lolo.dat","rwt");
    
    
    float energy, lolo;
    
    TGraph *hSpc= new TGraph(23577+1);
    TGraph *hCompton= new TGraph(23577+1);
    TGraph *hBrem= new TGraph(23577+1);
    TGraph *hRecomb= new TGraph(23577+1);

    
    factor_gae=1.e-13*1.e-13;
    factor_area=1.e4;
    factor_time=365*24*3600;
    factor_scale=1.e-20;
    
    int line=0;
    float val_total;
    char str[256];
    
    while (!feof(flist))
    {

            fscanf(flist,"%f\t%e\n",&energy, &lolo);
            val_total=lolo*factor_gae*factor_area*factor_time*factor_scale;
        
            printf("[%f\t%e] \n",energy, val_total);
        
            hSpc     -> SetPoint(line,energy,val_total);
        
        line++;
        
    }

    
    
    printf("Total Entries :: %d\n",line);
    
    
    hSpc->GetXaxis()->SetLabelFont(82);
    hSpc->GetXaxis()->SetLabelSize(0.035);
    hSpc->GetXaxis()->SetTitleFont(82);
    hSpc->GetXaxis()->SetTitleSize(0.035);
    hSpc->GetXaxis()->CenterTitle();
    hSpc->GetXaxis()->SetTitleOffset(1.3);
    hSpc->GetXaxis()->SetTitle("E_{a} [keV]");
    
    hSpc->GetYaxis()->SetLabelFont(82);
    hSpc->GetYaxis()->SetLabelSize(0.035);
    hSpc->GetYaxis()->SetTitleFont(82);
    hSpc->GetYaxis()->SetTitleSize(0.035);
    hSpc->GetYaxis()->CenterTitle();
    hSpc->GetYaxis()->SetTitleOffset(1.3);
    hSpc->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} [10^{20}keV^{-1}year^{-1}m^{-2}]");
    hSpc->SetLineColor(kMagenta+2);
    hSpc->SetMarkerColor(kMagenta+2);

    
    canvasc->cd();
    hSpc->Draw("AP");
    
   TLegend *leg = new TLegend(0.4,0.6,0.8,0.85);
   leg->SetTextFont(82);
   leg->SetTextSize(0.025);

    leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   //leg->SetFillStyle(1001);
    
   
   entry=leg->AddEntry(hSpc,"Total axion-electron flux","PL");
   //entry->SetFillStyle(1001);
   entry->SetLineColor(kMagenta+2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
    
   leg->Draw();
   canvasc->Modified();
   canvasc->cd();
   canvasc->SetSelected(canvasc);
}
