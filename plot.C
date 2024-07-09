void EnergySpectra (const std::string& inputFile, const std::string& observable, bool fidutial_cut = false){
    TRestRun *inputRun = new TRestRun(inputFile);
    std::string outputFileName;
    if (observable == "hits"){
        outputFileName = "R02009_Spectra_hits";
        if(fidutial_cut){
            inputRun->GetAnalysisTree()->Draw("hitsAna_energy>>spectra_hits(200,0,30000)","((hitsAna_yMean*hitsAna_yMean) + (hitsAna_xMean*hitsAna_xMean))<25");
            outputFileName += "_fidutial";
        } else {
            inputRun->GetAnalysisTree()->Draw("hitsAna_energy>>spectra_hits(200,0,30000)","");
        }
        
        TH1F *h = (TH1F*)gPad->GetPrimitive("spectra_hits");
        TCanvas* canvas = new TCanvas("c","spectra_hits", 800, 600);
        canvas->cd();
        h->Draw();
        outputFileName += ".root";

        //save in .root
        TFile* output_file = new TFile(outputFileName.c_str(), "RECREATE");
        h->Write();
        output_file->Close();
    }

    if (observable == "tracks"){
        outputFileName = "R02009_Spectra_tracks";
        if(fidutial_cut){
            inputRun->GetAnalysisTree()->Draw("tckAna_MaxTrackEnergy>>spectra_tracks(200,0,30000)",
            "((tckAna_MaxTrack_Ymean_Y*tckAna_MaxTrack_Ymean_Y) + (tckAna_MaxTrack_Xmean_X*tckAna_MaxTrack_Xmean_X))<25");

            outputFileName += "_fidutial";
        } else {
            inputRun->GetAnalysisTree()->Draw("tckAna_MaxTrackEnergy>>spectra_tracks(200,0,30000)","tckAna_MaxTrackEnergy > 0");
        } 
        TH1F *h = (TH1F*)gPad->GetPrimitive("spectra_tracks");
        TCanvas* canvas = new TCanvas("c","spectra_tracks", 800, 600);
        canvas->cd();
        h->Draw();
        outputFileName += ".root";

        //save in .root
        TFile* output_file = new TFile(outputFileName.c_str(), "RECREATE");
        h->Write();
        output_file->Close();
    }
}

void HitMap (const std::string& inputFile, const std::string& observable, bool fidutial_cut = false){
    
    TRestRun *inputRun = new TRestRun(inputFile);
    std::string outputFileName;
    // VariableY:VariableX(nBinsX,Xmin,Xmax,Ymin,Ymax)
    // the second argument is for TCut
    // the third one is the TH2 style
    if (observable == "hits"){
        outputFileName = "R02009_Hitmap_hits";
        if(fidutial_cut){
            inputRun->GetAnalysisTree()->Draw("hitsAna_yMean:hitsAna_xMean>>hitmap_hits(100,-30,30,100,-30,30)",
            "(hitsAna_yMean*hitsAna_yMean + hitsAna_xMean*hitsAna_xMean)<25 && hitsAna_energy > 0","colz");

            outputFileName += "_fidutial";
        } else {
            inputRun->GetAnalysisTree()->Draw("hitsAna_yMean:hitsAna_xMean>>hitmap_hits(100,-30,30,100,-30,30)","","colz");
        } 
        outputFileName += ".root";
        TH2F *h = (TH2F*)gPad->GetPrimitive("hitmap_hits");
        TCanvas* canvas = new TCanvas("c","hitmap_hits", 800, 600);
        canvas->cd();
        h->Draw("COLZ");

        //save in .root
        TFile* output_file = new TFile(outputFileName.c_str(), "RECREATE");
        h->Write();
        output_file->Close();
    }

    if (observable == "tracks"){
        outputFileName = "R02009_Hitmap_tracks";
         if(fidutial_cut){
            inputRun->GetAnalysisTree()->Draw("tckAna_MaxTrack_Ymean_Y:tckAna_MaxTrack_Xmean_X>>hitmap_tracks(100,-30,30,100,-30,30)",
            "((tckAna_MaxTrack_Ymean_Y*tckAna_MaxTrack_Ymean_Y) + (tckAna_MaxTrack_Xmean_X*tckAna_MaxTrack_Xmean_X))<25","colz");
            outputFileName += "_fidutial";
        } else {
            inputRun->GetAnalysisTree()->Draw("tckAna_MaxTrack_Ymean_Y:tckAna_MaxTrack_Xmean_X>>hitmap_tracks(100,-30,30,100,-30,30)","","colz");
        } 
        outputFileName += ".root";
        TH2F *h = (TH2F*)gPad->GetPrimitive("hitmap_tracks");
        TCanvas* canvas = new TCanvas("c","hitmap_tracks", 800, 600);
        canvas->cd();
        h->Draw("COLZ");

        //save in .root
        TFile* output_file = new TFile(outputFileName.c_str(), "RECREATE");
        h->Write();
        output_file->Close();

    }  
}