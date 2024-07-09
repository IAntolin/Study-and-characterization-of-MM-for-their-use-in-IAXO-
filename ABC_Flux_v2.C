

double integrateGraph(TGraph *graph) {  //using the trapezoid rule
    double integral = 0.0;
    int numPoints = graph->GetN();
    double x, y;
    for (int i = 0; i < numPoints - 1; ++i) {
        graph->GetPoint(i, x, y);
        double xNext, yNext;
        graph->GetPoint(i + 1, xNext, yNext);
        double dx = xNext - x;
        double dyAvg = (y + yNext) / 2.0;
        integral += dx * dyAvg;  // area of the trapezoid between the current and next data points using the trapezoid rule (average height times width)
    }
    return integral;
}


//void ABC_flux_from_l_and_2l() {  NOT FINISHED BUT WITH INTEGRALS!!
//  
//  // Open the file
//  const char* filename = "lolo.dat";
//  std::ifstream file(filename);
//  if (!file.is_open()) {
//      std::cerr << "Error: Unable to open file " << filename << std::endl;
//      return;
//  }
//
//  TFile * fin = new TFile("Fit_file.root");
//  TF1* fitFunc12_1 = (TF1*)fin->Get("fitFunc12_1");
//  TF1* fitFunc12_2 = (TF1*)fin->Get("fitFunc12_2");
//  TF1* fitFunc12_3 = (TF1*)fin->Get("fitFunc12_3");
//  
//  TF1* fitFunc2_1 = (TF1*)fin->Get("fitFunc2_1");
//  TF1* fitFunc2_2 = (TF1*)fin->Get("fitFunc2_2");
//  TF1* fitFunc2_3 = (TF1*)fin->Get("fitFunc2_3");
//  
//  TF1* fitFunc3_1 = (TF1*)fin->Get("fitFunc3_1");
//  TF1* fitFunc3_2 = (TF1*)fin->Get("fitFunc3_2");
//  TF1* fitFunc3_3 = (TF1*)fin->Get("fitFunc3_3");
//  
//  // Arrays to hold the data
//  std::vector<double> energy;
//  std::vector<double> lolo;
//  std::vector<double> data_12;
//  std::vector<double> data_2;
//  std::vector<double> data_3;
//  
//  // Read data from the file
//  double e, l;
//  while (file >> e >> l) {
//    energy.push_back(e);
//    
//    if (0.0 <= e && e < 3.0) {
//        if (0.0 <= e && e < 0.75) {
//    
//          data_12.push_back(0.0);
//          data_2.push_back(0.0);
//          data_3.push_back(0.0);
//        } else if (0.75 <= e && e < 3.0){
//        
//          double fit12Value = fitFunc12_1->Eval(e);
//          data_12.push_back(fit12Value);
//          double fit2Value = fitFunc2_1->Eval(e);
//          data_2.push_back(fit2Value);
//          double fit3Value = fitFunc3_1->Eval(e);
//          data_3.push_back(fit3Value);}
//          
//    } else if (3.0 <= e && e < 3.25) {
//        double fit12Value = fitFunc12_2->Eval(e);
//        data_12.push_back(fit12Value);
//        double fit2Value = fitFunc2_2->Eval(e);
//        data_2.push_back(fit2Value);
//        double fit3Value = fitFunc3_2->Eval(e);
//        data_3.push_back(fit3Value);
//        
//    } else if (3.25 <= e && e < 12.0) {
//        double fit12Value = fitFunc12_3->Eval(e);
//        data_12.push_back(fit12Value);
//        double fit2Value = fitFunc2_3->Eval(e);
//        data_2.push_back(fit2Value);
//        double fit3Value = fitFunc3_3->Eval(e);
//        data_3.push_back(fit3Value);
//    }
//  }
//  file.close();
//  
//  // Variables for scaling factors
//  const double factor_gae = 1.e-13 * 1.e-13;
//  const double factor_area = 1.e4;
//  const double factor_time = 365 * 24 * 3600;
//  const double factor_scale = 1.e-20;
//
//  // Open the file again to read lolo values
//  file.open(filename);
//  if (!file.is_open()) {
//      std::cerr << "Error: Unable to open file " << filename << std::endl;
//      return;
//  }
//
//  // Read lolo values from the file
//  while (file >> e >> l) {
//      lolo.push_back(l * factor_gae * factor_area * factor_time * factor_scale);
//  }
//  file.close();
// 
//  // Arrays to hold the convoluted data
//  std::vector<double> conv_12;
//  std::vector<double> conv_2;
//  std::vector<double> conv_3;
// 
//  // Calculate convoluted values
//  for (size_t i = 0; i < energy.size(); ++i) {
//    conv_12.push_back(lolo[i] * data_12[i]);
//  }
//  
//  for (size_t i=0; i < energy.size(); ++i) {
//    conv_2.push_back(lolo[i] * data_2[i]);
//  }
//  
//  for (size_t i=0; i < energy.size(); ++i) {
//    conv_3.push_back(lolo[i] * data_3[i]);
//  }
//
//  // Create a TGraph object for lolo
//  TGraph *hSpc = new TGraph(energy.size(), &energy[0], &lolo[0]);
//  
//  // Create TGraph objects for conv vectors
//  TGraph *hConv12 = new TGraph(energy.size(), &energy[0], &conv_12[0]);
//  TGraph *hConv2 = new TGraph(energy.size(), &energy[0], &conv_2[0]);
//  TGraph *hConv3 = new TGraph(energy.size(), &energy[0], &conv_3[0]);
//
//  // Create a canvas
//  TCanvas * c1 = new TCanvas("c1", "c1", 3000, 1500); 
//  c1 ->Divide(2,1);
//  gStyle->SetTextFont(42);
//  
//  // Draw the histogram
//  c1-> cd(1)->SetMargin(0.135, 0.005, 0.15, 0.085);
//  hSpc->Draw("AP");
//  
//  // Draw conv_12 and the rest on the same canvas
//  hConv12->SetLineColor(kBlue); // Set line color for conv_12
//  hConv12->Draw("SAME");
//  
//  hConv2->SetLineColor(kRed); // Set line color for conv_2
//  hConv2->Draw("SAME");
//  
//  hConv3->SetLineColor(kGreen+2); // Set line color for conv_3
//  hConv3->Draw("SAME");
// 
//  // Style adjustments
//  hSpc->SetLineColor(kMagenta+2);
//  hSpc->SetMarkerColor(kMagenta+2);
//  hSpc->SetMarkerSize(5);
//  gStyle->SetTitleFont(102, ""); 
//  hSpc->SetTitle("3 cm Drift Distance");  
//  hSpc->GetXaxis()->SetTitle("E_{a} [keV]");         
//  hSpc->GetXaxis()->SetTitleSize(0.05);
//  hSpc->GetXaxis()->SetTitleFont(82);
//  hSpc->GetXaxis()->CenterTitle(); 
//  hSpc->GetXaxis()->SetLabelFont(82);
//  hSpc->GetXaxis()->SetTitleOffset(1.1);  
//  hSpc->GetXaxis()->SetLabelSize(0.0475);
//  hSpc->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} [10^{20}keV^{-1}year^{-1}m^{-2}]"); 
//  hSpc->GetYaxis()->SetTitleSize(0.05);
//  hSpc->GetYaxis()->SetTitleFont(82);
//  hSpc->GetYaxis()->SetLabelFont(82);
//  hSpc->GetYaxis()->SetTitleOffset(1.3);
//  hSpc->GetYaxis()->SetLabelOffset(0.02); 
//  hSpc->GetYaxis()->CenterTitle(); 
//  hSpc->GetYaxis()->SetLabelSize(0.0475); 
// 
//
//  // Create and draw legend
//  TLegend *leg = new TLegend(0.5, 0.75, 0.86, 0.85);
//  leg->SetTextFont(82);
//  leg->SetTextSize(0.035);
//  leg->SetLineColor(1);
//  leg->SetLineStyle(1);
//  leg->SetLineWidth(1);
//  leg->SetFillColor(0);
//  
//  leg->AddEntry(hSpc, "Axion-electron flux", "PL");
//  leg->AddEntry(hConv12, "P=1.2bar", "PL");
//  leg->AddEntry(hConv2, "P=2.0bar", "PL");
//  leg->AddEntry(hConv3, "P=3.0bar", "PL");
//  leg->Draw();
//  
//  
////  double integral_hSpc = integrateGraph(hSpc);
////  std::cout << "Integral of hSpc: " << integral_hSpc << std::endl;
////  
////  double integral_hConv12 = integrateGraph(hConv12);
////  std::cout << "Integral of hConv12: " << integral_hConv12 << std::endl;
////  
////  double integral_hConv2 = integrateGraph(hConv2);
////  std::cout << "Integral of hConv2: " << integral_hConv2 << std::endl;
////  
////  double integral_hConv3 = integrateGraph(hConv3);
////  std::cout << "Integral of hConv3: " << integral_hConv3 << std::endl;
////  
////  //fractions:
////  std::cout << "fraction of hConv12: " << (integral_hConv12/integral_hSpc)*100.0 << std::endl;  //with respect to nominal value
////  
////  std::cout << "fraction of hConv2: " << (integral_hConv2/integral_hSpc)*100.0 << std::endl;
////  
////  std::cout << "fraction of hConv3: " << (integral_hConv3/integral_hSpc)*100.0 << std::endl;
////  
////  std::cout << "fraction of hcon2/hcon12:" << (integral_hConv2/integral_hConv12)*100.0 << std::endl;
////  std::cout << "fraction of hcon3/hcon12:" << (integral_hConv3/integral_hConv12)*100.0 << std::endl;
//
//  
////  // Open the file
////  const char* filename = "lolo.dat";
////  std::ifstream file(filename);
////  if (!file.is_open()) {
////      std::cerr << "Error: Unable to open file " << filename << std::endl;
////      return;
////  }
//
//  //TFile * fin = new TFile("Fit_file.root");
//  TF1* fitFunc2_12_1 = (TF1*)fin->Get("fitFunc2_12_1");
//  TF1* fitFunc2_12_2 = (TF1*)fin->Get("fitFunc2_12_2");
//  TF1* fitFunc2_12_3 = (TF1*)fin->Get("fitFunc2_12_3");
//  
//  TF1* fitFunc2_2_1 = (TF1*)fin->Get("fitFunc2_2_1");
//  TF1* fitFunc2_2_2 = (TF1*)fin->Get("fitFunc2_2_2");
//  TF1* fitFunc2_2_3 = (TF1*)fin->Get("fitFunc2_2_3");
//  
//  TF1* fitFunc2_3_1 = (TF1*)fin->Get("fitFunc2_3_1");
//  TF1* fitFunc2_3_2 = (TF1*)fin->Get("fitFunc2_3_2");
//  TF1* fitFunc2_3_3 = (TF1*)fin->Get("fitFunc2_3_3");
//  
//  // Arrays to hold the data
//  //std::vector<double> energy;
//  //std::vector<double> lolo;
//  std::vector<double> data2_12;
//  std::vector<double> data2_2;
//  std::vector<double> data2_3;
//  
//  // Read data from the file
//  double e2, l2;
//  while (file >> e2 >> l2) {
//    energy.push_back(e2);
//    
//    if (0.0 <= e2 && e2 < 3.0) {
//        if (0.0 <= e2 && e2 < 0.75) {
//    
//          data2_12.push_back(0.0);
//          data2_2.push_back(0.0);
//          data2_3.push_back(0.0);
//        } else if (0.75 <= e2 && e2 < 3.0){
//        
//          double fit12Value = fitFunc2_12_1->Eval(e2);
//          data2_12.push_back(fit12Value);
//          double fit2Value = fitFunc2_2_1->Eval(e2);
//          data2_2.push_back(fit2Value);
//          double fit3Value = fitFunc2_3_1->Eval(e2);
//          data2_3.push_back(fit3Value); }
//          
//    } else if (3.0 <= e2 && e2 < 3.25) {
//        double fit12Value = fitFunc2_12_2->Eval(e2);
//        data2_12.push_back(fit12Value);
//        double fit2Value = fitFunc2_2_2->Eval(e2);
//        data2_2.push_back(fit2Value);
//        double fit3Value = fitFunc2_3_2->Eval(e2);
//        data2_3.push_back(fit3Value);
//        
//    } else if (3.25 <= e2 && e2 < 12.0) {
//        double fit12Value = fitFunc2_12_3->Eval(e2);
//        data2_12.push_back(fit12Value);
//        double fit2Value = fitFunc2_2_3->Eval(e2);
//        data2_2.push_back(fit2Value);
//        double fit3Value = fitFunc2_3_3->Eval(e2);
//        data2_3.push_back(fit3Value);
//    }
//  }
//  file.close();
//  
//  // Variables for scaling factors
////  const double factor_gae = 1.e-13 * 1.e-13;
////  const double factor_area = 1.e4;
////  const double factor_time = 365 * 24 * 3600;
////  const double factor_scale = 1.e-20;
//
//  // Open the file again to read lolo values
//  file.open(filename);
//  if (!file.is_open()) {
//      std::cerr << "Error: Unable to open file " << filename << std::endl;
//      return;
//  }
//
//  // Read lolo values from the file
//  while (file >> e2 >> l2) {
//      lolo.push_back(l2 * factor_gae * factor_area * factor_time * factor_scale);
//  }
//  file.close();
// 
//  // Arrays to hold the convoluted data
//  std::vector<double> conv2_12;
//  std::vector<double> conv2_2;
//  std::vector<double> conv2_3;
//
//  // Calculate convoluted values
//  for (size_t i = 0; i < energy.size(); ++i) {
//    conv2_12.push_back(lolo[i] * data2_12[i]);
//  }
//  
//  for (size_t i=0; i < energy.size(); ++i) {
//    conv2_2.push_back(lolo[i] * data2_2[i]);
//  }
//  
//  for (size_t i=0; i < energy.size(); ++i) {
//    conv2_3.push_back(lolo[i] * data2_3[i]);
//  }
//
//
//  
//  // Create TGraph objects for conv vectors
//  TGraph *hConv2_12 = new TGraph(energy.size(), &energy[0], &conv2_12[0]);
//  TGraph *hConv2_2 = new TGraph(energy.size(), &energy[0], &conv2_2[0]);
//  TGraph *hConv2_3 = new TGraph(energy.size(), &energy[0], &conv2_3[0]);
//
//  c1->cd(2)->SetMargin(0.135, 0.005, 0.15, 0.085);
//  hSpc->Draw("AP");
//  
//  // Draw conv_12 and the rest on the same canvas
//  hConv2_12->SetLineColor(kBlue); // Set line color for conv_12
//  hConv2_12->Draw("SAME");
//  
//  hConv2_2->SetLineColor(kRed); // Set line color for conv_2
//  hConv2_2->Draw("SAME");
//  
//  hConv2_3->SetLineColor(kGreen+2); // Set line color for conv_3
//  hConv2_3->Draw("SAME");
// 
//  // Style adjustments
//  hSpc->SetLineColor(kMagenta+2);
//  hSpc->SetMarkerColor(kMagenta+2);
//  hSpc->SetMarkerSize(5);
//  gStyle->SetTitleFont(102, ""); 
//  hSpc->SetTitle("6 cm Drift Distance");  
//  hSpc->GetXaxis()->SetTitle("E_{a} [keV]");         
//  hSpc->GetXaxis()->SetTitleSize(0.05);
//  hSpc->GetXaxis()->SetTitleFont(82);
//  hSpc->GetXaxis()->CenterTitle(); 
//  hSpc->GetXaxis()->SetLabelFont(82);
//  hSpc->GetXaxis()->SetTitleOffset(1.1);  
//  hSpc->GetXaxis()->SetLabelSize(0.0475);
//  hSpc->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} [10^{20}keV^{-1}year^{-1}m^{-2}]"); 
//  hSpc->GetYaxis()->SetTitleSize(0.05);
//  hSpc->GetYaxis()->SetTitleFont(82);
//  hSpc->GetYaxis()->SetLabelFont(82);
//  hSpc->GetYaxis()->SetTitleOffset(1.3);
//  hSpc->GetYaxis()->SetLabelOffset(0.02); 
//  hSpc->GetYaxis()->CenterTitle(); 
//  hSpc->GetYaxis()->SetLabelSize(0.0475); 
// 
//
//  // Create and draw legend
//  TLegend *leg2 = new TLegend(0.5, 0.75, 0.86, 0.85);
//  leg2->SetTextFont(82);
//  leg2->SetTextSize(0.035);
//  leg2->SetLineColor(1);
//  leg2->SetLineStyle(1);
//  leg2->SetLineWidth(1);
//  leg2->SetFillColor(0);
//  leg2->AddEntry(hSpc, "Axion-electron flux", "PL");
//  leg2->AddEntry(hConv12, "P=1.2bar", "PL");
//  leg2->AddEntry(hConv2, "P=2.0bar", "PL");
//  leg2->AddEntry(hConv3, "P=3.0bar", "PL");
//  leg2->Draw();
//
//
//  // Save canvas as PNG
//  c1->SaveAs("ABC_flux_L and_2l.png");
//  
////  double integral_hSpc = integrateGraph(hSpc);
////  std::cout << "Integral of hSpc: " << integral_hSpc << std::endl;
////  
////  double integral_hConv12 = integrateGraph(hConv12);
////  std::cout << "Integral of hConv12: " << integral_hConv12 << std::endl;
////  
////  double integral_hConv2 = integrateGraph(hConv2);
////  std::cout << "Integral of hConv2: " << integral_hConv2 << std::endl;
////  
////  double integral_hConv3 = integrateGraph(hConv3);
////  std::cout << "Integral of hConv3: " << integral_hConv3 << std::endl;
////  
////  //fractions:
////  std::cout << "fraction of hConv12: " << (integral_hConv12/integral_hSpc)*100.0 << std::endl;  //with respect nominal value
////  
////  std::cout << "fraction of hConv2: " << (integral_hConv2/integral_hSpc)*100.0 << std::endl;
////  
////  std::cout << "fraction of hConv3: " << (integral_hConv3/integral_hSpc)*100.0 << std::endl;
////  
////  std::cout << "fraction of hcon2/hcon12:" << (integral_hConv2/integral_hConv12)*100.0 << std::endl;
////  std::cout << "fraction of hcon3/hcon12:" << (integral_hConv3/integral_hConv12)*100.0 << std::endl;
// 
//
//}


void ABC_flux_from_l_and_2l() { 
  
    // Open the file
    const char* filename = "lolo.dat";
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    TFile *fin = new TFile("Fit_file.root");
    if (!fin || fin->IsZombie()) {
        std::cerr << "Error: Unable to open file Fit_file.root" << std::endl;
        return;
    }
  
    TF1* fitFunc12_1 = (TF1*)fin->Get("fitFunc12_1");
    TF1* fitFunc12_2 = (TF1*)fin->Get("fitFunc12_2");
    TF1* fitFunc12_3 = (TF1*)fin->Get("fitFunc12_3");
  
    TF1* fitFunc2_1 = (TF1*)fin->Get("fitFunc2_1");
    TF1* fitFunc2_2 = (TF1*)fin->Get("fitFunc2_2");
    TF1* fitFunc2_3 = (TF1*)fin->Get("fitFunc2_3");
  
    TF1* fitFunc3_1 = (TF1*)fin->Get("fitFunc3_1");
    TF1* fitFunc3_2 = (TF1*)fin->Get("fitFunc3_2");
    TF1* fitFunc3_3 = (TF1*)fin->Get("fitFunc3_3");
  
    // Arrays to hold the data
    std::vector<double> energy;
    std::vector<double> lolo;
    std::vector<double> data_12;
    std::vector<double> data_2;
    std::vector<double> data_3;
  
    // Read data from the file
    double e, l;
    while (file >> e >> l) {
        energy.push_back(e);
      
        if (0.0 <= e && e < 3.0) {
            if (0.0 <= e && e < 0.75) {
                data_12.push_back(0.0);
                data_2.push_back(0.0);
                data_3.push_back(0.0);
            } else if (0.75 <= e && e < 3.0) {
                data_12.push_back(fitFunc12_1->Eval(e));
                data_2.push_back(fitFunc2_1->Eval(e));
                data_3.push_back(fitFunc3_1->Eval(e));
            }
        } else if (3.0 <= e && e < 3.25) {
            data_12.push_back(fitFunc12_2->Eval(e));
            data_2.push_back(fitFunc2_2->Eval(e));
            data_3.push_back(fitFunc3_2->Eval(e));
        } else if (3.25 <= e && e < 12.0) {
            data_12.push_back(fitFunc12_3->Eval(e));
            data_2.push_back(fitFunc2_3->Eval(e));
            data_3.push_back(fitFunc3_3->Eval(e));
        }
    }
    file.close();
  
    // Variables for scaling factors
    const double factor_gae = 1.e-13 * 1.e-13;
    const double factor_area = 1.e4;
    const double factor_time = 365 * 24 * 3600;
    const double factor_scale = 1.e-20;

    // Open the file again to read lolo values
    file.open(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    // Read lolo values from the file
    while (file >> e >> l) {
        lolo.push_back(l * factor_gae * factor_area * factor_time * factor_scale);
    }
    file.close();
 
    // Arrays to hold the convoluted data
    std::vector<double> conv_12;
    std::vector<double> conv_2;
    std::vector<double> conv_3;
 
    // Calculate convoluted values
    for (size_t i = 0; i < energy.size(); ++i) {
        conv_12.push_back(lolo[i] * data_12[i]);
        conv_2.push_back(lolo[i] * data_2[i]);
        conv_3.push_back(lolo[i] * data_3[i]);
    }

    // Create a TGraph object for lolo
    TGraph *hSpc_left = new TGraph(energy.size(), &energy[0], &lolo[0]);
  
    // Create TGraph objects for conv vectors for left pad
    TGraph *hConv12_left = new TGraph(energy.size(), &energy[0], &conv_12[0]);
    TGraph *hConv2_left = new TGraph(energy.size(), &energy[0], &conv_2[0]);
    TGraph *hConv3_left = new TGraph(energy.size(), &energy[0], &conv_3[0]);

    // Create a canvas
    TCanvas *c1 = new TCanvas("c1", "c1", 3000, 1500); 
    c1->Divide(2,1);
    gStyle->SetTextFont(42);
  
    // Draw the histogram on the left pad
    c1->cd(1)->SetMargin(0.155, 0.005, 0.15, 0.085);
    hSpc_left->Draw("AP");
  
    // Draw conv_12 and the rest on the same canvas
    hConv12_left->SetLineColor(kBlue); // Set line color for conv_12
    hConv12_left->Draw("SAME");
  
    hConv2_left->SetLineColor(kRed); // Set line color for conv_2
    hConv2_left->Draw("SAME");
  
    hConv3_left->SetLineColor(kGreen+2); // Set line color for conv_3
    hConv3_left->Draw("SAME");
 
    // Style adjustments for left pad
    hSpc_left->SetLineColor(kMagenta+2);
    hSpc_left->SetMarkerColor(kMagenta+2);
    hSpc_left->SetMarkerSize(5);
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
 
    // Create and draw legend for left pad
    TLegend *leg_left = new TLegend(0.48, 0.75, 0.86, 0.85);
    leg_left->SetTextFont(82);
    leg_left->SetTextSize(0.035);
    leg_left->SetLineColor(1);
    leg_left->SetLineStyle(1);
    leg_left->SetLineWidth(1);
    leg_left->SetFillColor(0);
    leg_left->SetFillColorAlpha(kWhite, 0);  
    leg_left->SetLineColor(kWhite);
  
    leg_left->AddEntry(hSpc_left, "Axion-electron flux", "PL");
    leg_left->AddEntry(hConv12_left, "P=1.2bar", "PL");
    leg_left->AddEntry(hConv2_left, "P=2.0bar", "PL");
    leg_left->AddEntry(hConv3_left, "P=3.0bar", "PL");
    leg_left->Draw();
    
    // Create another set of fit functions for the second plot
    TF1* fitFunc2_12_1 = (TF1*)fin->Get("fitFunc2_12_1");
    TF1* fitFunc2_12_2 = (TF1*)fin->Get("fitFunc2_12_2");
    TF1* fitFunc2_12_3 = (TF1*)fin->Get("fitFunc2_12_3");
  
    TF1* fitFunc2_2_1 = (TF1*)fin->Get("fitFunc2_2_1");
    TF1* fitFunc2_2_2 = (TF1*)fin->Get("fitFunc2_2_2");
    TF1* fitFunc2_2_3 = (TF1*)fin->Get("fitFunc2_2_3");
  
    TF1* fitFunc2_3_1 = (TF1*)fin->Get("fitFunc2_3_1");
    TF1* fitFunc2_3_2 = (TF1*)fin->Get("fitFunc2_3_2");
    TF1* fitFunc2_3_3 = (TF1*)fin->Get("fitFunc2_3_3");

    // Read data from the file again
    std::vector<double> data2_12;
    std::vector<double> data2_2;
    std::vector<double> data2_3;
    file.open(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }
  
    while (file >> e >> l) {
        if (0.0 <= e && e < 3.0) {
            if (0.0 <= e && e < 0.75) {
                data2_12.push_back(0.0);
                data2_2.push_back(0.0);
                data2_3.push_back(0.0);
            } else if (0.75 <= e && e < 3.0) {
                data2_12.push_back(fitFunc2_12_1->Eval(e));
                data2_2.push_back(fitFunc2_2_1->Eval(e));
                data2_3.push_back(fitFunc2_3_1->Eval(e));
            }
        } else if (3.0 <= e && e < 3.25) {
            data2_12.push_back(fitFunc2_12_2->Eval(e));
            data2_2.push_back(fitFunc2_2_2->Eval(e));
            data2_3.push_back(fitFunc2_3_2->Eval(e));
        } else if (3.25 <= e && e < 12.0) {
            data2_12.push_back(fitFunc2_12_3->Eval(e));
            data2_2.push_back(fitFunc2_2_3->Eval(e));
            data2_3.push_back(fitFunc2_3_3->Eval(e));
        }
    }
    file.close();
  
    // Arrays to hold the convoluted data for the second set
    std::vector<double> conv2_12;
    std::vector<double> conv2_2;
    std::vector<double> conv2_3;
 
    // Calculate convoluted values for the second set
    for (size_t i = 0; i < energy.size(); ++i) {
        conv2_12.push_back(lolo[i] * data2_12[i]);
        conv2_2.push_back(lolo[i] * data2_2[i]);
        conv2_3.push_back(lolo[i] * data2_3[i]);
    }
  
    // Create TGraph objects for the second set
    TGraph *hSpc_right = new TGraph(energy.size(), &energy[0], &lolo[0]);
    TGraph *hConv2_12 = new TGraph(energy.size(), &energy[0], &conv2_12[0]);
    TGraph *hConv2_2 = new TGraph(energy.size(), &energy[0], &conv2_2[0]);
    TGraph *hConv2_3 = new TGraph(energy.size(), &energy[0], &conv2_3[0]);

    // Draw the histogram on the right pad
    c1->cd(2)->SetMargin(0.155, 0.005, 0.15, 0.085);
    hSpc_right->Draw("AP");
  
    hConv2_12->SetLineColor(kBlue); 
    hConv2_12->Draw("SAME");
  
    hConv2_2->SetLineColor(kRed); 
    hConv2_2->Draw("SAME");
  
    hConv2_3->SetLineColor(kGreen+2); 
    hConv2_3->Draw("SAME");

    // Style adjustments for right pad
    hSpc_right->SetLineColor(kMagenta+2);
    hSpc_right->SetMarkerColor(kMagenta+2);
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
 
    // Create and draw legend for right pad
    TLegend *leg_right = new TLegend(0.48, 0.75, 0.86, 0.85);
    leg_right->SetTextFont(82);
    leg_right->SetTextSize(0.035);
    leg_right->SetLineColor(1);
    leg_right->SetLineStyle(1);
    leg_right->SetLineWidth(1);
    leg_right->SetFillColor(0);
    leg_right->SetFillColorAlpha(kWhite, 0);  
    leg_right->SetLineColor(kWhite);
  
    leg_right->AddEntry(hSpc_right, "Axion-electron flux", "PL");
    leg_right->AddEntry(hConv2_12, "P=1.2bar", "PL");
    leg_right->AddEntry(hConv2_2, "P=2.0bar", "PL");
    leg_right->AddEntry(hConv2_3, "P=3.0bar", "PL");
    leg_right->Draw();

    // Save the canvas as an image
    c1->SaveAs("ABC_flux_L_and_2l.png"); 
    c1->SaveAs("ABC_flux_L_and_2l.eps");
}






//void primakoff_flux_from_l() {
//  
//  // Open the file
//  const char* filename = "primakoff.dat";
//  std::ifstream file(filename);
//  if (!file.is_open()) {
//      std::cerr << "Error: Unable to open file " << filename << std::endl;
//      return;
//  }
//
//  TFile * fin = new TFile("Fit_file.root");
//  TF1* fitFunc12_1 = (TF1*)fin->Get("fitFunc12_1");
//  TF1* fitFunc12_2 = (TF1*)fin->Get("fitFunc12_2");
//  TF1* fitFunc12_3 = (TF1*)fin->Get("fitFunc12_3");
//  
//  TF1* fitFunc2_1 = (TF1*)fin->Get("fitFunc2_1");
//  TF1* fitFunc2_2 = (TF1*)fin->Get("fitFunc2_2");
//  TF1* fitFunc2_3 = (TF1*)fin->Get("fitFunc2_3");
//  
//  TF1* fitFunc3_1 = (TF1*)fin->Get("fitFunc3_1");
//  TF1* fitFunc3_2 = (TF1*)fin->Get("fitFunc3_2");
//  TF1* fitFunc3_3 = (TF1*)fin->Get("fitFunc3_3");
//  
//  // Arrays to hold the data
//  std::vector<double> energy;
//  std::vector<double> primakoff;
//  std::vector<double> data_12;
//  std::vector<double> data_2;
//  std::vector<double> data_3;
//  
//  // Read data from the file
//  double e,p;
//  while (file >> e >> p) {
//    energy.push_back(e);
//    
//    if (0.0 <= e && e < 3.0) {
//        if (0.0 <= e && e < 0.75) {
//    
//          data_12.push_back(0.0);
//          data_2.push_back(0.0);
//          data_3.push_back(0.0);
//        } else if (0.75 <= e && e < 3.0){
//        
//          double fit12Value = fitFunc12_1->Eval(e);
//          data_12.push_back(fit12Value);
//          double fit2Value = fitFunc2_1->Eval(e);
//          data_2.push_back(fit2Value);
//          double fit3Value = fitFunc3_1->Eval(e);
//          data_3.push_back(fit3Value);}
//          
//    } else if (3.0 <= e && e < 3.25) {
//        double fit12Value = fitFunc12_2->Eval(e);
//        data_12.push_back(fit12Value);
//        double fit2Value = fitFunc2_2->Eval(e);
//        data_2.push_back(fit2Value);
//        double fit3Value = fitFunc3_2->Eval(e);
//        data_3.push_back(fit3Value);
//        
//    } else if (3.25 <= e && e < 12.0) {
//        double fit12Value = fitFunc12_3->Eval(e);
//        data_12.push_back(fit12Value);
//        double fit2Value = fitFunc2_3->Eval(e);
//        data_2.push_back(fit2Value);
//        double fit3Value = fitFunc3_3->Eval(e);
//        data_3.push_back(fit3Value);
//    }
//  }
//  file.close();
//
//  // Open the file again to read lolo values
//  file.open(filename); 
//  if (!file.is_open()) {
//      std::cerr << "Error: Unable to open file " << filename << std::endl;
//      return;
//  }
//
//  // Read lolo values from the file
//  while (file >> e >> p) {
//      primakoff.push_back(p);
//  }
//  file.close();
// 
// 
//  // Arrays to hold the convoluted data
//  std::vector<double> conv_12;
//  std::vector<double> conv_2;
//  std::vector<double> conv_3;
//
//  // Calculate convoluted values
//  for (size_t i = 0; i < energy.size(); ++i) {
//    conv_12.push_back(primakoff[i] * data_12[i]);
//  }
//  
//  for (size_t i=0; i < energy.size(); ++i) {
//    conv_2.push_back(primakoff[i] * data_2[i]);
//  }
//  
//  for (size_t i=0; i < energy.size(); ++i) {
//    conv_3.push_back(primakoff[i] * data_3[i]);
//  }
//
//  // Create a TGraph object for lolo
//  TGraph *hSpc = new TGraph(energy.size(), &energy[0], &primakoff[0]);
//  
//  // Create TGraph objects for conv vectors
//  TGraph *hConv12 = new TGraph(energy.size(), &energy[0], &conv_12[0]);
//  TGraph *hConv2 = new TGraph(energy.size(), &energy[0], &conv_2[0]);
//  TGraph *hConv3 = new TGraph(energy.size(), &energy[0], &conv_3[0]);
//
//  // Create a canvas
//  TCanvas *canvasc = new TCanvas("canvasc", "Trackings for ga#gamma", 2300, 1200);
//  
//  // Draw the histogram
//  canvasc->cd();
//  hSpc->Draw("APL");
//  hSpc->SetLineWidth(2);
//  
//  // Draw conv_12 and the rest on the same canvas
//  hConv12->SetLineColor(kBlue); // Set line color for conv_12
//  hConv12->SetLineWidth(2);
//  hConv12->Draw("SAME");
//  
//  hConv2->SetLineColor(kRed); // Set line color for conv_2
//  hConv2->SetLineWidth(2);
//  hConv2->Draw("SAME");
//  
//  hConv3->SetLineColor(kGreen+2); // Set line color for conv_3
//  hConv3->SetLineWidth(2);
//  hConv3->Draw("SAME");
// 
//  // Style adjustments
//  hSpc-> SetTitle("Convoluted primakoff spectra for L=3cm drift distance");
//  hSpc->GetXaxis()->SetTitle("E_{a} [keV]");
//  hSpc->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @ g_{10} [s^{-1}cm^{-2}]");
//  hSpc->SetLineColor(kMagenta+2);
//  hSpc->SetMarkerColor(kMagenta+2);
//  hSpc->SetMarkerSize(5);
//
//  // Create and draw legend
//  TLegend *leg = new TLegend(0.48, 0.75, 0.89, 0.85);
//  leg->SetTextFont(82);
//  leg->SetTextSize(0.025);
//  leg->SetLineColor(1);
//  leg->SetLineStyle(1);
//  leg->SetLineWidth(1);
//  leg->SetFillColor(0);
//  
//  leg->AddEntry(hSpc, "Axion spectra on Earth (hadronic model)", "PL");
//  leg->AddEntry(hConv12, "Convoluted Primakoff flux with P=1.2bar eff", "PL");
//  leg->AddEntry(hConv2, "Convoluted Primakoff flux with P=2.0bar eff", "PL");
//  leg->AddEntry(hConv3, "Convoluted Primakoff flux with P=3.0bar eff", "PL");
//  leg->Draw();
//
//  canvasc->Modified();
//  canvasc->Update();
//
//  // Save canvas as PNG
//  canvasc->SaveAs("Primakoff_flux_l.png");
//  
//  double integral_hSpc = integrateGraph(hSpc);
//  std::cout << "Integral of hSpc: " << integral_hSpc << std::endl;
//  
//  double integral_hConv12 = integrateGraph(hConv12);
//  std::cout << "Integral of hConv12: " << integral_hConv12 << std::endl;
//  
//  double integral_hConv2 = integrateGraph(hConv2);
//  std::cout << "Integral of hConv2: " << integral_hConv2 << std::endl;
//  
//  double integral_hConv3 = integrateGraph(hConv3);
//  std::cout << "Integral of hConv3: " << integral_hConv3 << std::endl;
//  
//  //fractions:
//  std::cout << "fraction of hConv12: " << (integral_hConv12/integral_hSpc)*100.0 << std::endl;  //with respect nominal value
//  
//  std::cout << "fraction of hConv2: " << (integral_hConv2/integral_hSpc)*100.0 << std::endl;
//  
//  std::cout << "fraction of hConv3: " << (integral_hConv3/integral_hSpc)*100.0 << std::endl;
//  
//
//  std::cout << "fraction of hcon2/hcon12:" << (integral_hConv2/integral_hConv12)*100.0 << std::endl;
//  std::cout << "fraction of hcon3/hcon12:" << (integral_hConv3/integral_hConv12)*100.0 << std::endl;
//
//}
//
//
//void primakoff_flux_from_2l() {
//  
//  // Open the file
//  const char* filename = "primakoff.dat";
//  std::ifstream file(filename);
//  if (!file.is_open()) {
//      std::cerr << "Error: Unable to open file " << filename << std::endl;
//      return;
//  }
//
//  TFile * fin = new TFile("Fit_file.root");
//  TF1* fitFunc2_12_1 = (TF1*)fin->Get("fitFunc2_12_1");
//  TF1* fitFunc2_12_2 = (TF1*)fin->Get("fitFunc2_12_2");
//  TF1* fitFunc2_12_3 = (TF1*)fin->Get("fitFunc2_12_3");
//  
//  TF1* fitFunc2_2_1 = (TF1*)fin->Get("fitFunc2_2_1");
//  TF1* fitFunc2_2_2 = (TF1*)fin->Get("fitFunc2_2_2");
//  TF1* fitFunc2_2_3 = (TF1*)fin->Get("fitFunc2_2_3");
//  
//  TF1* fitFunc2_3_1 = (TF1*)fin->Get("fitFunc2_3_1");
//  TF1* fitFunc2_3_2 = (TF1*)fin->Get("fitFunc2_3_2");
//  TF1* fitFunc2_3_3 = (TF1*)fin->Get("fitFunc2_3_3");
//  
//  // Arrays to hold the data
//  std::vector<double> energy;
//  std::vector<double> primakoff;
//  std::vector<double> data2_12;
//  std::vector<double> data2_2;
//  std::vector<double> data2_3;
//  
//  // Read data from the file
//  double e, p;
//  while (file >> e >> p) {
//    energy.push_back(e);
//    
//    if (0.0 <= e && e < 3.0) {
//        if (0.0 <= e && e < 0.75) {
//    
//          data2_12.push_back(0.0);
//          data2_2.push_back(0.0);
//          data2_3.push_back(0.0);
//        } else if (0.75 <= e && e < 3.0){
//        
//          double fit12Value = fitFunc2_12_1->Eval(e);
//          data2_12.push_back(fit12Value);
//          double fit2Value = fitFunc2_2_1->Eval(e);
//          data2_2.push_back(fit2Value);
//          double fit3Value = fitFunc2_3_1->Eval(e);
//          data2_3.push_back(fit3Value); }
//          
//    } else if (3.0 <= e && e < 3.25) {
//        double fit12Value = fitFunc2_12_2->Eval(e);
//        data2_12.push_back(fit12Value);
//        double fit2Value = fitFunc2_2_2->Eval(e);
//        data2_2.push_back(fit2Value);
//        double fit3Value = fitFunc2_3_2->Eval(e);
//        data2_3.push_back(fit3Value);
//        
//    } else if (3.25 <= e && e < 12.0) {
//        double fit12Value = fitFunc2_12_3->Eval(e);
//        data2_12.push_back(fit12Value);
//        double fit2Value = fitFunc2_2_3->Eval(e);
//        data2_2.push_back(fit2Value);
//        double fit3Value = fitFunc2_3_3->Eval(e);
//        data2_3.push_back(fit3Value);
//    }
//  }
//  file.close();
//
//  // Open the file again to read lolo values
//  file.open(filename); 
//  if (!file.is_open()) {
//      std::cerr << "Error: Unable to open file " << filename << std::endl;
//      return;
//  }
//
//  // Read lolo values from the file
//  while (file >> e >> p) {
//      primakoff.push_back(p);
//  }
//  file.close();
// 
// 
//  // Arrays to hold the convoluted data
//  std::vector<double> conv_12;
//  std::vector<double> conv_2;
//  std::vector<double> conv_3;
//
//  // Calculate convoluted values
//  for (size_t i = 0; i < energy.size(); ++i) {
//    conv_12.push_back(primakoff[i] * data2_12[i]);
//  }
//  
//  for (size_t i=0; i < energy.size(); ++i) {
//    conv_2.push_back(primakoff[i] * data2_2[i]);
//  }
//  
//  for (size_t i=0; i < energy.size(); ++i) {
//    conv_3.push_back(primakoff[i] * data2_3[i]);
//  }
//
//  // Create a TGraph object for lolo
//  TGraph *hSpc = new TGraph(energy.size(), &energy[0], &primakoff[0]);
//  
//  // Create TGraph objects for conv vectors
//  TGraph *hConv12 = new TGraph(energy.size(), &energy[0], &conv_12[0]);
//  TGraph *hConv2 = new TGraph(energy.size(), &energy[0], &conv_2[0]);
//  TGraph *hConv3 = new TGraph(energy.size(), &energy[0], &conv_3[0]);
//
//  // Create a canvas
//  TCanvas *canvasc = new TCanvas("canvasc", "Trackings for ga#gamma", 2300, 1200);
//  
//  // Draw the histogram
//  canvasc->cd();
//  hSpc->Draw("APL");
//  hSpc->SetLineWidth(2);
//  
//  // Draw conv_12 and the rest on the same canvas
//  hConv12->SetLineColor(kBlue); // Set line color for conv_12
//  hConv12->SetLineWidth(2);
//  hConv12->Draw("SAME");
//  
//  hConv2->SetLineColor(kRed); // Set line color for conv_2
//  hConv2->SetLineWidth(2);
//  hConv2->Draw("SAME");
//  
//  hConv3->SetLineColor(kGreen+2); // Set line color for conv_3
//  hConv3->SetLineWidth(2);
//  hConv3->Draw("SAME");
// 
//  // Style adjustments
//  hSpc-> SetTitle("Convoluted primakoff spectra for L=6cm drift distance");
//  hSpc->GetXaxis()->SetTitle("E_{a} [keV]");
//  hSpc->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @ g_{10} [s^{-1}cm^{-2}]");
//  hSpc->SetLineColor(kMagenta+2);
//  hSpc->SetMarkerColor(kMagenta+2);
//  hSpc->SetMarkerSize(5);
//
//  // Create and draw legend
//  TLegend *leg = new TLegend(0.48, 0.75, 0.89, 0.85);
//  leg->SetTextFont(82);
//  leg->SetTextSize(0.025);
//  leg->SetLineColor(1);
//  leg->SetLineStyle(1);
//  leg->SetLineWidth(1);
//  leg->SetFillColor(0);
//  
//  leg->AddEntry(hSpc, "Axion spectra on Earth (hadronic model)", "PL");
//  leg->AddEntry(hConv12, "Convoluted Primakoff flux with P=1.2bar eff", "PL");
//  leg->AddEntry(hConv2, "Convoluted Primakoff flux with P=2.0bar eff", "PL");
//  leg->AddEntry(hConv3, "Convoluted Primakoff flux with P=3.0bar eff", "PL");
//  leg->Draw();
//
//  canvasc->Modified();
//  canvasc->Update();
//
//  // Save canvas as PNG
//  canvasc->SaveAs("Primakoff_flux_2l.png");
//  
//  double integral_hSpc = integrateGraph(hSpc);
//  std::cout << "Integral of hSpc: " << integral_hSpc << std::endl;
//  
//  double integral_hConv12 = integrateGraph(hConv12);
//  std::cout << "Integral of hConv12: " << integral_hConv12 << std::endl;
//  
//  double integral_hConv2 = integrateGraph(hConv2);
//  std::cout << "Integral of hConv2: " << integral_hConv2 << std::endl;
//  
//  double integral_hConv3 = integrateGraph(hConv3);
//  std::cout << "Integral of hConv3: " << integral_hConv3 << std::endl;
//  
//  //fractions:
//  std::cout << "fraction of hConv12: " << (integral_hConv12/integral_hSpc)*100.0 << std::endl;  //with respect nominal value
//  
//  std::cout << "fraction of hConv2: " << (integral_hConv2/integral_hSpc)*100.0 << std::endl;
//  
//  std::cout << "fraction of hConv3: " << (integral_hConv3/integral_hSpc)*100.0 << std::endl;
//  
//
//  std::cout << "fraction of hcon2/hcon12:" << (integral_hConv2/integral_hConv12)*100.0 << std::endl;
//  std::cout << "fraction of hcon3/hcon12:" << (integral_hConv3/integral_hConv12)*100.0 << std::endl;
//
//}



void primakoff_flux_from_l_and_2l() { 
  
    // Open the file
    const char* filename = "primakoff.dat";
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    TFile *fin = new TFile("Fit_file.root");
    if (!fin || fin->IsZombie()) {
        std::cerr << "Error: Unable to open file Fit_file.root" << std::endl;
        return;
    }
  
    TF1* fitFunc12_1 = (TF1*)fin->Get("fitFunc12_1");
    TF1* fitFunc12_2 = (TF1*)fin->Get("fitFunc12_2");
    TF1* fitFunc12_3 = (TF1*)fin->Get("fitFunc12_3");
  
    TF1* fitFunc2_1 = (TF1*)fin->Get("fitFunc2_1");
    TF1* fitFunc2_2 = (TF1*)fin->Get("fitFunc2_2");
    TF1* fitFunc2_3 = (TF1*)fin->Get("fitFunc2_3");
  
    TF1* fitFunc3_1 = (TF1*)fin->Get("fitFunc3_1");
    TF1* fitFunc3_2 = (TF1*)fin->Get("fitFunc3_2");
    TF1* fitFunc3_3 = (TF1*)fin->Get("fitFunc3_3");
  
    // Arrays to hold the data
    std::vector<double> energy;
    std::vector<double> primakoff;
    std::vector<double> data_12;
    std::vector<double> data_2;
    std::vector<double> data_3;
  
    // Read data from the file
    double e, l;
    while (file >> e >> l) {
        energy.push_back(e);
      
        if (0.0 <= e && e < 3.0) {
            if (0.0 <= e && e < 0.75) {
                data_12.push_back(0.0);
                data_2.push_back(0.0);
                data_3.push_back(0.0);
            } else if (0.75 <= e && e < 3.0) {
                data_12.push_back(fitFunc12_1->Eval(e));
                data_2.push_back(fitFunc2_1->Eval(e));
                data_3.push_back(fitFunc3_1->Eval(e));
            }
        } else if (3.0 <= e && e < 3.25) {
            data_12.push_back(fitFunc12_2->Eval(e));
            data_2.push_back(fitFunc2_2->Eval(e));
            data_3.push_back(fitFunc3_2->Eval(e));
        } else if (3.25 <= e && e < 12.0) {
            data_12.push_back(fitFunc12_3->Eval(e));
            data_2.push_back(fitFunc2_3->Eval(e));
            data_3.push_back(fitFunc3_3->Eval(e));
        }
    }
    file.close();

    // Open the file again to read lolo values
    file.open(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    // Read lolo values from the file
    while (file >> e >> l) {
        primakoff.push_back(l);
    }
    file.close();
 
    // Arrays to hold the convoluted data
    std::vector<double> conv_12;
    std::vector<double> conv_2;
    std::vector<double> conv_3;
 
    // Calculate convoluted values
    for (size_t i = 0; i < energy.size(); ++i) {
        conv_12.push_back(primakoff[i] * data_12[i]);
        conv_2.push_back(primakoff[i] * data_2[i]);
        conv_3.push_back(primakoff[i] * data_3[i]);
    }

    // Create a TGraph object for lolo
    TGraph *hSpc_left = new TGraph(energy.size(), &energy[0], &primakoff[0]);
  
    // Create TGraph objects for conv vectors for left pad
    TGraph *hConv12_left = new TGraph(energy.size(), &energy[0], &conv_12[0]);
    TGraph *hConv2_left = new TGraph(energy.size(), &energy[0], &conv_2[0]);
    TGraph *hConv3_left = new TGraph(energy.size(), &energy[0], &conv_3[0]);

    // Create a canvas
    TCanvas *c1 = new TCanvas("c1", "c1", 3000, 1500); 
    c1->Divide(2,1);
    gStyle->SetTextFont(42);
  
    // Draw the histogram on the left pad
    c1->cd(1)->SetMargin(0.155, 0.005, 0.15, 0.085);
    hSpc_left->Draw("APL");
    hSpc_left->SetLineWidth(1);
  
    // Draw conv_12 and the rest on the same canvas
    hConv12_left->SetLineColor(kBlue); // Set line color for conv_12
    hConv12_left->Draw("SAME");
  
    hConv2_left->SetLineColor(kRed); // Set line color for conv_2
    hConv2_left->Draw("SAME");
  
    hConv3_left->SetLineColor(kGreen+2); // Set line color for conv_3
    hConv3_left->Draw("SAME");
 
    // Style adjustments for left pad
    hSpc_left->SetLineColor(kMagenta+2);
    hSpc_left->SetMarkerColor(kMagenta+2);
    hSpc_left->SetMarkerSize(5);
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
 
    // Create and draw legend for left pad
    TLegend *leg_left = new TLegend(0.55, 0.75, 0.98, 0.85);
    leg_left->SetTextFont(82);
    leg_left->SetTextSize(0.035);
    leg_left->SetLineColor(1);
    leg_left->SetLineStyle(1);
    leg_left->SetLineWidth(1);
    leg_left->SetFillColor(0);
    leg_left->SetFillColorAlpha(kWhite, 0);  
    leg_left->SetLineColor(kWhite);
  
    leg_left->AddEntry(hSpc_left, "Hadronic model", "PL");
    leg_left->AddEntry(hConv12_left, "P=1.2bar", "PL");
    leg_left->AddEntry(hConv2_left, "P=2.0bar", "PL");
    leg_left->AddEntry(hConv3_left, "P=3.0bar", "PL");
    leg_left->Draw();
    
    // Create another set of fit functions for the second plot
    TF1* fitFunc2_12_1 = (TF1*)fin->Get("fitFunc2_12_1");
    TF1* fitFunc2_12_2 = (TF1*)fin->Get("fitFunc2_12_2");
    TF1* fitFunc2_12_3 = (TF1*)fin->Get("fitFunc2_12_3");
  
    TF1* fitFunc2_2_1 = (TF1*)fin->Get("fitFunc2_2_1");
    TF1* fitFunc2_2_2 = (TF1*)fin->Get("fitFunc2_2_2");
    TF1* fitFunc2_2_3 = (TF1*)fin->Get("fitFunc2_2_3");
  
    TF1* fitFunc2_3_1 = (TF1*)fin->Get("fitFunc2_3_1");
    TF1* fitFunc2_3_2 = (TF1*)fin->Get("fitFunc2_3_2");
    TF1* fitFunc2_3_3 = (TF1*)fin->Get("fitFunc2_3_3");

    // Read data from the file again
    std::vector<double> data2_12;
    std::vector<double> data2_2;
    std::vector<double> data2_3;
    file.open(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }
  
    while (file >> e >> l) {
        if (0.0 <= e && e < 3.0) {
            if (0.0 <= e && e < 0.75) {
                data2_12.push_back(0.0);
                data2_2.push_back(0.0);
                data2_3.push_back(0.0);
            } else if (0.75 <= e && e < 3.0) {
                data2_12.push_back(fitFunc2_12_1->Eval(e));
                data2_2.push_back(fitFunc2_2_1->Eval(e));
                data2_3.push_back(fitFunc2_3_1->Eval(e));
            }
        } else if (3.0 <= e && e < 3.25) {
            data2_12.push_back(fitFunc2_12_2->Eval(e));
            data2_2.push_back(fitFunc2_2_2->Eval(e));
            data2_3.push_back(fitFunc2_3_2->Eval(e));
        } else if (3.25 <= e && e < 12.0) {
            data2_12.push_back(fitFunc2_12_3->Eval(e));
            data2_2.push_back(fitFunc2_2_3->Eval(e));
            data2_3.push_back(fitFunc2_3_3->Eval(e));
        }
    }
    file.close();
  
    // Arrays to hold the convoluted data for the second set
    std::vector<double> conv2_12;
    std::vector<double> conv2_2;
    std::vector<double> conv2_3;
 
    // Calculate convoluted values for the second set
    for (size_t i = 0; i < energy.size(); ++i) {
        conv2_12.push_back(primakoff[i] * data2_12[i]);
        conv2_2.push_back(primakoff[i] * data2_2[i]);
        conv2_3.push_back(primakoff[i] * data2_3[i]);
    }
  
    // Create TGraph objects for the second set
    TGraph *hSpc_right = new TGraph(energy.size(), &energy[0], &primakoff[0]);
    TGraph *hConv2_12 = new TGraph(energy.size(), &energy[0], &conv2_12[0]);
    TGraph *hConv2_2 = new TGraph(energy.size(), &energy[0], &conv2_2[0]);
    TGraph *hConv2_3 = new TGraph(energy.size(), &energy[0], &conv2_3[0]);

    // Draw the histogram on the right pad
    c1->cd(2)->SetMargin(0.155, 0.005, 0.15, 0.085);
    hSpc_right->Draw("APL");
    hSpc_right->SetLineWidth(1);
  
    hConv2_12->SetLineColor(kBlue); 
    hConv2_12->Draw("SAME");
  
    hConv2_2->SetLineColor(kRed); 
    hConv2_2->Draw("SAME");
  
    hConv2_3->SetLineColor(kGreen+2); 
    hConv2_3->Draw("SAME");

    // Style adjustments for right pad
    hSpc_right->SetLineColor(kMagenta+2);
    hSpc_right->SetMarkerColor(kMagenta+2);
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
 
    // Create and draw legend for right pad
    TLegend *leg_right = new TLegend(0.55, 0.75, 0.98, 0.85);
    leg_right->SetTextFont(82);
    leg_right->SetTextSize(0.035);
    leg_right->SetLineColor(1);
    leg_right->SetLineStyle(1);
    leg_right->SetLineWidth(1);
    leg_right->SetFillColor(0);
    leg_right->SetFillColorAlpha(kWhite, 0);  
    leg_right->SetLineColor(kWhite);
  
    leg_right->AddEntry(hSpc_right, "Hadronic model", "PL");
    leg_right->AddEntry(hConv2_12, "P=1.2bar", "PL");
    leg_right->AddEntry(hConv2_2, "P=2.0bar", "PL");
    leg_right->AddEntry(hConv2_3, "P=3.0bar", "PL");
    leg_right->Draw();

    // Save the canvas as an image
    c1->SaveAs("primakoff_flux_L_and_2l.png"); 
    c1->SaveAs("primakoff_flux_L_and_2l.eps");
}



void from_primakoff_to_histogram(const char* filename) {

    // Open the file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    // Create a histogram
    TH1D *histogram = new TH1D("primakoff", "primakoff", 1420, 0, 10); // Adjust binning as needed
    gStyle->SetOptStat(0);

    // Variables to read data from the file
    double x, y;

    // Read data from the file and manually fill the histogram
    while (file >> x >> y) {
        int bin = histogram->GetXaxis()->FindBin(x); // Find the bin corresponding to the x value
        histogram->SetBinContent(bin, y); // Set the content of the bin to the y value
    }

    // Close the file
    file.close();
    
    TFile * fout = new TFile("Primakoff_histogram.root", "recreate"); 
    histogram->Write();
    fout->Close();
    
    TFile * fout2 = new TFile("histograms/Primakoff_histogram.root", "recreate");
    histogram->Write();
    fout2->Close();

    // Create a canvas and draw the histogram
    TCanvas *canvas = new TCanvas("canvas", "Canvas", 1500, 1000);
    histogram->Draw(); // Draw the histogram
    canvas->SaveAs("primakof_histogram.png"); // Save the histogram as an image file
    double area = histogram->Integral();
    cout << "The integral of the histogram is:" << area << endl;
}


void from_ABC_to_histogram(const char* filename) {

    // Open the file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    // Create a histogram
    TH1D *histogram = new TH1D("ABC", "ABC", 1800, 0, 12); // Adjust binning as needed
    gStyle->SetOptStat(0);
    
    // Variables for scaling factors
    const double factor_gae = 1.e-13 * 1.e-13;
    const double factor_area = 1.e4;
    const double factor_time = 365 * 24 * 3600;
    const double factor_scale = 1.e-20; 

    // Variables to read data from the file
    double x, y;

    // Read data from the file and manually fill the histogram
    while (file >> x >> y) {
        int bin = histogram->GetXaxis()->FindBin(x); // Find the bin corresponding to the x value
        histogram->SetBinContent(bin, y*factor_gae*factor_area*factor_time*factor_scale); // Set the content of the bin to the y value
    }

    // Close the file
    file.close();
    
    TFile * fout = new TFile("ABC_histogram.root", "recreate"); 
    histogram->Write();
    fout->Close();
    
    TFile * fout2 = new TFile("histograms/ABC_histogram.root", "recreate");
    histogram->Write();
    fout2->Close();

    // Create a canvas and draw the histogram
    TCanvas *canvas = new TCanvas("canvas", "Canvas", 1500, 1000);
    histogram->Draw(); // Draw the histogram
    canvas->SaveAs("ABC_histogram.png"); // Save the histogram as an image file
    double area = histogram->Integral();
    cout << "The integral of the histogram is:" << area << endl;
}




//void aN_flux_from_l() {
//  
//  // Open the file
//  const char* filename = "aN_flux_data.dat";
//  std::ifstream file(filename);
//  if (!file.is_open()) {
//      std::cerr << "Error: Unable to open file " << filename << std::endl;
//      return;
//  }
//
//  TFile * fin = new TFile("Fit_file.root");
//  TF1* fitFunc12_1 = (TF1*)fin->Get("fitFunc12_1");
//  TF1* fitFunc12_2 = (TF1*)fin->Get("fitFunc12_2");
//  TF1* fitFunc12_3 = (TF1*)fin->Get("fitFunc12_3");
//  
//  TF1* fitFunc2_1 = (TF1*)fin->Get("fitFunc2_1");
//  TF1* fitFunc2_2 = (TF1*)fin->Get("fitFunc2_2");
//  TF1* fitFunc2_3 = (TF1*)fin->Get("fitFunc2_3");
//  
//  TF1* fitFunc3_1 = (TF1*)fin->Get("fitFunc3_1");
//  TF1* fitFunc3_2 = (TF1*)fin->Get("fitFunc3_2");
//  TF1* fitFunc3_3 = (TF1*)fin->Get("fitFunc3_3");
//  
//  // Arrays to hold the data
//  std::vector<double> energy;
//  std::vector<double> aN;
//  std::vector<double> data_12;
//  std::vector<double> data_2;
//  std::vector<double> data_3;
//  
//  // Read data from the file
//  double e,p;
//  while (file >> e >> p) {
//    energy.push_back(e);
//    
//    if (0.0 <= e && e < 3.0) {
//        if (0.0 <= e && e < 0.75) {
//    
//          data_12.push_back(0.0);
//          data_2.push_back(0.0);
//          data_3.push_back(0.0);
//        } else if (0.75 <= e && e < 3.0){
//        
//          double fit12Value = fitFunc12_1->Eval(e);
//          data_12.push_back(fit12Value);
//          double fit2Value = fitFunc2_1->Eval(e);
//          data_2.push_back(fit2Value);
//          double fit3Value = fitFunc3_1->Eval(e);
//          data_3.push_back(fit3Value);}
//          
//    } else if (3.0 <= e && e < 3.25) {
//        double fit12Value = fitFunc12_2->Eval(e);
//        data_12.push_back(fit12Value);
//        double fit2Value = fitFunc2_2->Eval(e);
//        data_2.push_back(fit2Value);
//        double fit3Value = fitFunc3_2->Eval(e);
//        data_3.push_back(fit3Value);
//        
//    } else if (3.25 <= e && e < 16.0) {
//        double fit12Value = fitFunc12_3->Eval(e);
//        data_12.push_back(fit12Value);
//        double fit2Value = fitFunc2_3->Eval(e);
//        data_2.push_back(fit2Value);
//        double fit3Value = fitFunc3_3->Eval(e);
//        data_3.push_back(fit3Value);
//    }
//  }
//  file.close();
//
//  // Open the file again to read lolo values
//  file.open(filename); 
//  if (!file.is_open()) {
//      std::cerr << "Error: Unable to open file " << filename << std::endl;
//      return;
//  }
//
//  // Read lolo values from the file
//  while (file >> e >> p) {
//      aN.push_back(p);
//  }
//  file.close();
// 
// 
//  // Arrays to hold the convoluted data
//  std::vector<double> conv_12;
//  std::vector<double> conv_2;
//  std::vector<double> conv_3;
//
//  // Calculate convoluted values
//  for (size_t i = 0; i < energy.size(); ++i) {
//    conv_12.push_back(aN[i] * data_12[i]);
//  }
//  
//  for (size_t i=0; i < energy.size(); ++i) {
//    conv_2.push_back(aN[i] * data_2[i]);
//  }
//  
//  for (size_t i=0; i < energy.size(); ++i) {
//    conv_3.push_back(aN[i] * data_3[i]);
//  }
//
//  // Create a TGraph object for lolo
//  TGraph *hSpc = new TGraph(energy.size(), &energy[0], &aN[0]);
//  
//  // Create TGraph objects for conv vectors
//  TGraph *hConv12 = new TGraph(energy.size(), &energy[0], &conv_12[0]);
//  TGraph *hConv2 = new TGraph(energy.size(), &energy[0], &conv_2[0]);
//  TGraph *hConv3 = new TGraph(energy.size(), &energy[0], &conv_3[0]);
//
//  // Create a canvas
//  TCanvas *canvasc = new TCanvas("canvasc", "Trackings for gaN", 2300, 1200);
//  
//  // Draw the histogram
//  canvasc->cd();
//  hSpc->Draw("APL");
//  hSpc->GetXaxis()->SetRangeUser(14.3, 14.5);
//  hSpc->SetLineWidth(2);
//  
//  // Draw conv_12 and the rest on the same canvas
//  hConv12->SetLineColor(kBlue); // Set line color for conv_12
//  hConv12->SetLineWidth(2);
//  hConv12->Draw("SAME");
//
//  
//  hConv2->SetLineColor(kRed); // Set line color for conv_2
//  hConv2->SetLineWidth(2);
//  hConv2->Draw("SAME");
//  
//  hConv3->SetLineColor(kGreen+2); // Set line color for conv_3
//  hConv3->SetLineWidth(2);
//  hConv3->Draw("SAME");
// 
//  // Style adjustments
//  hSpc-> SetTitle("Convoluted aN spectra for L=3cm drift distance");
//  hSpc->GetXaxis()->SetTitle("E_{a} [keV]");
//  hSpc->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @g_{aN}^{eff} [s^{-1}cm^{-2}]");
//  hSpc->SetLineColor(kMagenta+2);
//  hSpc->SetMarkerColor(kMagenta+2);
//  hSpc->SetMarkerSize(5);
//
//  // Create and draw legend
//  TLegend *leg = new TLegend(0.53, 0.75, 0.89, 0.85);
//  leg->SetTextFont(82);
//  leg->SetTextSize(0.025);
//  leg->SetLineColor(1);
//  leg->SetLineStyle(1);
//  leg->SetLineWidth(1);
//  leg->SetFillColor(0);
//  
//  leg->AddEntry(hSpc, "Axion spectra on Earth form Fe57 decay", "PL");
//  leg->AddEntry(hConv12, "Convoluted aN flux with P=1.2bar eff", "PL");
//  leg->AddEntry(hConv2, "Convoluted aN flux with P=2.0bar eff", "PL");
//  leg->AddEntry(hConv3, "Convoluted aN flux with P=3.0bar eff", "PL");
//  leg->Draw();
//
//  canvasc->Modified();
//  canvasc->Update();
//
//  // Save canvas as PNG
//  canvasc->SaveAs("aN_flux_l.png");
//  
//  double integral_hSpc = integrateGraph(hSpc);
//  std::cout << "Integral of hSpc: " << integral_hSpc << std::endl;
//  
//  double integral_hConv12 = integrateGraph(hConv12);
//  std::cout << "Integral of hConv12: " << integral_hConv12 << std::endl;
//  
//  double integral_hConv2 = integrateGraph(hConv2);
//  std::cout << "Integral of hConv2: " << integral_hConv2 << std::endl;
//  
//  double integral_hConv3 = integrateGraph(hConv3);
//  std::cout << "Integral of hConv3: " << integral_hConv3 << std::endl;
//  
//  //fractions:
//  std::cout << "fraction of hConv12: " << (integral_hConv12/integral_hSpc)*100.0 << std::endl;  //with respect nominal value
//  
//  std::cout << "fraction of hConv2: " << (integral_hConv2/integral_hSpc)*100.0 << std::endl;
//  
//  std::cout << "fraction of hConv3: " << (integral_hConv3/integral_hSpc)*100.0 << std::endl;
//  
//
//  std::cout << "fraction of hcon2/hcon12:" << (integral_hConv2/integral_hConv12)*100.0 << std::endl;
//  std::cout << "fraction of hcon3/hcon12:" << (integral_hConv3/integral_hConv12)*100.0 << std::endl;
//
//}
//
//
//void aN_flux_from_2l() {
//  
//  // Open the file
//  const char* filename = "aN_flux_data.dat";
//  std::ifstream file(filename);
//  if (!file.is_open()) {
//      std::cerr << "Error: Unable to open file " << filename << std::endl;
//      return;
//  }
//
//  TFile * fin = new TFile("Fit_file.root");
//  TF1* fitFunc2_12_1 = (TF1*)fin->Get("fitFunc2_12_1");
//  TF1* fitFunc2_12_2 = (TF1*)fin->Get("fitFunc2_12_2");
//  TF1* fitFunc2_12_3 = (TF1*)fin->Get("fitFunc2_12_3");
//  
//  TF1* fitFunc2_2_1 = (TF1*)fin->Get("fitFunc2_2_1");
//  TF1* fitFunc2_2_2 = (TF1*)fin->Get("fitFunc2_2_2");
//  TF1* fitFunc2_2_3 = (TF1*)fin->Get("fitFunc2_2_3");
//  
//  TF1* fitFunc2_3_1 = (TF1*)fin->Get("fitFunc2_3_1");
//  TF1* fitFunc2_3_2 = (TF1*)fin->Get("fitFunc2_3_2");
//  TF1* fitFunc2_3_3 = (TF1*)fin->Get("fitFunc2_3_3");
//  
//  // Arrays to hold the data
//  std::vector<double> energy;
//  std::vector<double> aN;
//  std::vector<double> data2_12;
//  std::vector<double> data2_2;
//  std::vector<double> data2_3;
//  
//  // Read data from the file
//  double e, p;
//  while (file >> e >> p) {
//    energy.push_back(e);
//    
//    if (0.0 <= e && e < 3.0) {
//        if (0.0 <= e && e < 0.75) {
//    
//          data2_12.push_back(0.0);
//          data2_2.push_back(0.0);
//          data2_3.push_back(0.0);
//        } else if (0.75 <= e && e < 3.0){
//        
//          double fit12Value = fitFunc2_12_1->Eval(e);
//          data2_12.push_back(fit12Value);
//          double fit2Value = fitFunc2_2_1->Eval(e);
//          data2_2.push_back(fit2Value);
//          double fit3Value = fitFunc2_3_1->Eval(e);
//          data2_3.push_back(fit3Value); }
//          
//    } else if (3.0 <= e && e < 3.25) {
//        double fit12Value = fitFunc2_12_2->Eval(e);
//        data2_12.push_back(fit12Value);
//        double fit2Value = fitFunc2_2_2->Eval(e);
//        data2_2.push_back(fit2Value);
//        double fit3Value = fitFunc2_3_2->Eval(e);
//        data2_3.push_back(fit3Value);
//        
//    } else if (3.25 <= e && e < 16.0) {
//        double fit12Value = fitFunc2_12_3->Eval(e);
//        data2_12.push_back(fit12Value);
//        double fit2Value = fitFunc2_2_3->Eval(e);
//        data2_2.push_back(fit2Value);
//        double fit3Value = fitFunc2_3_3->Eval(e);
//        data2_3.push_back(fit3Value);
//    }
//  }
//  file.close();
//
//  // Open the file again to read lolo values
//  file.open(filename); 
//  if (!file.is_open()) {
//      std::cerr << "Error: Unable to open file " << filename << std::endl;
//      return;
//  }
//
//  // Read lolo values from the file
//  while (file >> e >> p) {
//      aN.push_back(p);
//  }
//  file.close();
// 
// 
//  // Arrays to hold the convoluted data
//  std::vector<double> conv_12;
//  std::vector<double> conv_2;
//  std::vector<double> conv_3;
//
//  // Calculate convoluted values
//  for (size_t i = 0; i < energy.size(); ++i) {
//    conv_12.push_back(aN[i] * data2_12[i]);
//  }
//  
//  for (size_t i=0; i < energy.size(); ++i) {
//    conv_2.push_back(aN[i] * data2_2[i]);
//  }
//  
//  for (size_t i=0; i < energy.size(); ++i) {
//    conv_3.push_back(aN[i] * data2_3[i]);
//  }
//
//  // Create a TGraph object for lolo
//  TGraph *hSpc = new TGraph(energy.size(), &energy[0], &aN[0]);
//  
//  // Create TGraph objects for conv vectors
//  TGraph *hConv12 = new TGraph(energy.size(), &energy[0], &conv_12[0]);
//  TGraph *hConv2 = new TGraph(energy.size(), &energy[0], &conv_2[0]);
//  TGraph *hConv3 = new TGraph(energy.size(), &energy[0], &conv_3[0]);
//
//  // Create a canvas
//  TCanvas *canvasc = new TCanvas("canvasc", "Trackings for gaN", 2300, 1200);
//  
//  // Draw the histogram
//  canvasc->cd();
//  hSpc->Draw("APL");
//  hSpc->GetXaxis()->SetRangeUser(14.3, 14.5);
//  hSpc->SetLineWidth(2);
//  
//  // Draw conv_12 and the rest on the same canvas
//  hConv12->SetLineColor(kBlue); // Set line color for conv_12
//  hConv12->SetLineWidth(2);
//  hConv12->Draw("SAME");
//  
//  hConv2->SetLineColor(kRed); // Set line color for conv_2
//  hConv2->SetLineWidth(2);
//  hConv2->Draw("SAME");
//  
//  hConv3->SetLineColor(kGreen+2); // Set line color for conv_3
//  hConv3->SetLineWidth(2);
//  hConv3->Draw("SAME");
// 
//  // Style adjustments
//  hSpc-> SetTitle("Convoluted aN spectra for L=6cm drift distance");
//  hSpc->GetXaxis()->SetTitle("E_{a} [keV]");
//  hSpc->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @g_{aN}^{eff} [s^{-1}cm^{-2}]");
//  hSpc->SetLineColor(kMagenta+2);
//  hSpc->SetMarkerColor(kMagenta+2);
//  hSpc->GetXaxis()->SetRangeUser(14.3, 14.5);
//  hSpc->SetMarkerSize(5);
//
//  // Create and draw legend
//  TLegend *leg = new TLegend(0.53, 0.75, 0.89, 0.85);
//  leg->SetTextFont(82);
//  leg->SetTextSize(0.025);
//  leg->SetLineColor(1);
//  leg->SetLineStyle(1);
//  leg->SetLineWidth(1);
//  leg->SetFillColor(0);
//  
//  leg->AddEntry(hSpc, "Axion spectra on Earth from Fe57 decay", "PL");
//  leg->AddEntry(hConv12, "Convoluted aN flux with P=1.2bar eff", "PL");
//  leg->AddEntry(hConv2, "Convoluted aN flux with P=2.0bar eff", "PL");
//  leg->AddEntry(hConv3, "Convoluted aN flux with P=3.0bar eff", "PL");
//  leg->Draw();
//
//  canvasc->Modified();
//  canvasc->Update();
//
//  // Save canvas as PNG
//  canvasc->SaveAs("aN_flux_2l.png");
//  
//  double integral_hSpc = integrateGraph(hSpc);
//  std::cout << "Integral of hSpc: " << integral_hSpc << std::endl;
//  
//  double integral_hConv12 = integrateGraph(hConv12);
//  std::cout << "Integral of hConv12: " << integral_hConv12 << std::endl;
//  
//  double integral_hConv2 = integrateGraph(hConv2);
//  std::cout << "Integral of hConv2: " << integral_hConv2 << std::endl;
//  
//  double integral_hConv3 = integrateGraph(hConv3);
//  std::cout << "Integral of hConv3: " << integral_hConv3 << std::endl;
//  
//  //fractions:
//  std::cout << "fraction of hConv12: " << (integral_hConv12/integral_hSpc)*100.0 << std::endl;  //with respect nominal value
//  
//  std::cout << "fraction of hConv2: " << (integral_hConv2/integral_hSpc)*100.0 << std::endl;
//  
//  std::cout << "fraction of hConv3: " << (integral_hConv3/integral_hSpc)*100.0 << std::endl;
//  
//  std::cout << "fraction of hcon2/hcon12:" << (integral_hConv2/integral_hConv12)*100.0 << std::endl;
//  std::cout << "fraction of hcon3/hcon12:" << (integral_hConv3/integral_hConv12)*100.0 << std::endl;
//
//
//}



void aN_flux_from_l_and_2l() { 
  
    // Open the file
    const char* filename = "aN_flux_data.dat";
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    TFile *fin = new TFile("Fit_file.root");
    if (!fin || fin->IsZombie()) {
        std::cerr << "Error: Unable to open file Fit_file.root" << std::endl;
        return;
    }
  
    TF1* fitFunc12_1 = (TF1*)fin->Get("fitFunc12_1");
    TF1* fitFunc12_2 = (TF1*)fin->Get("fitFunc12_2");
    TF1* fitFunc12_3 = (TF1*)fin->Get("fitFunc12_3");
  
    TF1* fitFunc2_1 = (TF1*)fin->Get("fitFunc2_1");
    TF1* fitFunc2_2 = (TF1*)fin->Get("fitFunc2_2");
    TF1* fitFunc2_3 = (TF1*)fin->Get("fitFunc2_3");
  
    TF1* fitFunc3_1 = (TF1*)fin->Get("fitFunc3_1");
    TF1* fitFunc3_2 = (TF1*)fin->Get("fitFunc3_2");
    TF1* fitFunc3_3 = (TF1*)fin->Get("fitFunc3_3");
  
    // Arrays to hold the data
    std::vector<double> energy;
    std::vector<double> aN;
    std::vector<double> data_12;
    std::vector<double> data_2;
    std::vector<double> data_3;
  
    // Read data from the file 
    double e, l;
    while (file >> e >> l) {
        energy.push_back(e);
      
        if (0.0 <= e && e < 3.0) {
            if (0.0 <= e && e < 0.75) {
                data_12.push_back(0.0);
                data_2.push_back(0.0);
                data_3.push_back(0.0);
            } else if (0.75 <= e && e < 3.0) {
                data_12.push_back(fitFunc12_1->Eval(e));
                data_2.push_back(fitFunc2_1->Eval(e));
                data_3.push_back(fitFunc3_1->Eval(e));
            }
        } else if (3.0 <= e && e < 3.25) {
            data_12.push_back(fitFunc12_2->Eval(e));
            data_2.push_back(fitFunc2_2->Eval(e));
            data_3.push_back(fitFunc3_2->Eval(e));
        } else if (3.25 <= e && e < 16.0) {
            data_12.push_back(fitFunc12_3->Eval(e));
            data_2.push_back(fitFunc2_3->Eval(e));
            data_3.push_back(fitFunc3_3->Eval(e));
        }
    }
    file.close();

    // Open the file again to read lolo values
    file.open(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    // Read lolo values from the file
    while (file >> e >> l) {
        aN.push_back(l);
    }
    file.close();
 
    // Arrays to hold the convoluted data
    std::vector<double> conv_12;
    std::vector<double> conv_2;
    std::vector<double> conv_3;
 
    // Calculate convoluted values
    for (size_t i = 0; i < energy.size(); ++i) {
        conv_12.push_back(aN[i] * data_12[i]);
        conv_2.push_back(aN[i] * data_2[i]);
        conv_3.push_back(aN[i] * data_3[i]);
    }

    // Create a TGraph object for lolo
    TGraph *hSpc_left = new TGraph(energy.size(), &energy[0], &aN[0]);
  
    // Create TGraph objects for conv vectors for left pad
    TGraph *hConv12_left = new TGraph(energy.size(), &energy[0], &conv_12[0]);
    TGraph *hConv2_left = new TGraph(energy.size(), &energy[0], &conv_2[0]);
    TGraph *hConv3_left = new TGraph(energy.size(), &energy[0], &conv_3[0]);

    // Create a canvas
    TCanvas *c1 = new TCanvas("c1", "c1", 3000, 1500); 
    c1->Divide(2,1);
    gStyle->SetTextFont(42);
  
    // Draw the histogram on the left pad
    c1->cd(1)->SetMargin(0.155, 0.058, 0.15, 0.085);
    hSpc_left->GetXaxis()->SetRangeUser(14.3, 14.5);
    hSpc_left->Draw("APL");
    hSpc_left->SetLineWidth(1);
  
    // Draw conv_12 and the rest on the same canvas
    hConv12_left->SetLineColor(kBlue); // Set line color for conv_12
    hConv12_left->Draw("SAME");
  
    hConv2_left->SetLineColor(kRed); // Set line color for conv_2
    hConv2_left->Draw("SAME");
  
    hConv3_left->SetLineColor(kGreen+2); // Set line color for conv_3
    hConv3_left->Draw("SAME");
 
    // Style adjustments for left pad
    hSpc_left->SetLineColor(kMagenta+2);
    hSpc_left->SetMarkerColor(kMagenta+2);
    hSpc_left->SetMarkerSize(5);
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
    hSpc_left->GetXaxis()->SetRangeUser(14.38, 14.44);
    hSpc_left->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @g_{aN}^{eff} [s^{-1}cm^{-2}]");
    hSpc_left->GetYaxis()->SetTitleSize(0.04);
    hSpc_left->GetYaxis()->SetTitleFont(82);
    hSpc_left->GetYaxis()->SetLabelFont(82);
    hSpc_left->GetYaxis()->SetTitleOffset(1.8);
    hSpc_left->GetYaxis()->SetLabelOffset(0.02); 
    hSpc_left->GetYaxis()->CenterTitle(); 
    hSpc_left->GetYaxis()->SetLabelSize(0.04); 
 
    // Create and draw legend for left pad
    TLegend *leg_left = new TLegend(0.5, 0.75, 0.88, 0.85);
    leg_left->SetTextFont(82);
    leg_left->SetTextSize(0.035);
    leg_left->SetLineColor(1);
    leg_left->SetLineStyle(1);
    leg_left->SetLineWidth(1);
    leg_left->SetFillColor(0);
    leg_left->SetFillColorAlpha(kWhite, 0);  
    leg_left->SetLineColor(kWhite);
  
    leg_left->AddEntry(hSpc_left, "From Fe57 decay", "PL");
    leg_left->AddEntry(hConv12_left, "P=1.2bar", "PL");
    leg_left->AddEntry(hConv2_left, "P=2.0bar", "PL");
    leg_left->AddEntry(hConv3_left, "P=3.0bar", "PL");
    leg_left->Draw();
    
    // Create another set of fit functions for the second plot
    TF1* fitFunc2_12_1 = (TF1*)fin->Get("fitFunc2_12_1");
    TF1* fitFunc2_12_2 = (TF1*)fin->Get("fitFunc2_12_2");
    TF1* fitFunc2_12_3 = (TF1*)fin->Get("fitFunc2_12_3");
  
    TF1* fitFunc2_2_1 = (TF1*)fin->Get("fitFunc2_2_1");
    TF1* fitFunc2_2_2 = (TF1*)fin->Get("fitFunc2_2_2");
    TF1* fitFunc2_2_3 = (TF1*)fin->Get("fitFunc2_2_3");
  
    TF1* fitFunc2_3_1 = (TF1*)fin->Get("fitFunc2_3_1");
    TF1* fitFunc2_3_2 = (TF1*)fin->Get("fitFunc2_3_2");
    TF1* fitFunc2_3_3 = (TF1*)fin->Get("fitFunc2_3_3");

    // Read data from the file again
    std::vector<double> data2_12;
    std::vector<double> data2_2;
    std::vector<double> data2_3;
    file.open(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }
  
    while (file >> e >> l) {
        if (0.0 <= e && e < 3.0) {
            if (0.0 <= e && e < 0.75) {
                data2_12.push_back(0.0);
                data2_2.push_back(0.0);
                data2_3.push_back(0.0);
            } else if (0.75 <= e && e < 3.0) {
                data2_12.push_back(fitFunc2_12_1->Eval(e));
                data2_2.push_back(fitFunc2_2_1->Eval(e));
                data2_3.push_back(fitFunc2_3_1->Eval(e));
            }
        } else if (3.0 <= e && e < 3.25) {
            data2_12.push_back(fitFunc2_12_2->Eval(e));
            data2_2.push_back(fitFunc2_2_2->Eval(e));
            data2_3.push_back(fitFunc2_3_2->Eval(e));
        } else if (3.25 <= e && e < 16.0) {
            data2_12.push_back(fitFunc2_12_3->Eval(e));
            data2_2.push_back(fitFunc2_2_3->Eval(e));
            data2_3.push_back(fitFunc2_3_3->Eval(e));
        }
    }
    file.close();
  
    // Arrays to hold the convoluted data for the second set
    std::vector<double> conv2_12;
    std::vector<double> conv2_2;
    std::vector<double> conv2_3;
 
    // Calculate convoluted values for the second set
    for (size_t i = 0; i < energy.size(); ++i) {
        conv2_12.push_back(aN[i] * data2_12[i]);
        conv2_2.push_back(aN[i] * data2_2[i]);
        conv2_3.push_back(aN[i] * data2_3[i]);
    }
  
    // Create TGraph objects for the second set
    TGraph *hSpc_right = new TGraph(energy.size(), &energy[0], &aN[0]);
    TGraph *hConv2_12 = new TGraph(energy.size(), &energy[0], &conv2_12[0]);
    TGraph *hConv2_2 = new TGraph(energy.size(), &energy[0], &conv2_2[0]);
    TGraph *hConv2_3 = new TGraph(energy.size(), &energy[0], &conv2_3[0]);

    // Draw the histogram on the right pad
    c1->cd(2)->SetMargin(0.155, 0.058, 0.15, 0.085);
    hSpc_right->GetXaxis()->SetRangeUser(14.3, 14.5);
    hSpc_right->Draw("APL");
    hSpc_right->SetLineWidth(1);
  
    hConv2_12->SetLineColor(kBlue); 
    hConv2_12->Draw("SAME");
  
    hConv2_2->SetLineColor(kRed); 
    hConv2_2->Draw("SAME");
  
    hConv2_3->SetLineColor(kGreen+2); 
    hConv2_3->Draw("SAME");

    // Style adjustments for right pad
    hSpc_right->SetLineColor(kMagenta+2);
    hSpc_right->SetMarkerColor(kMagenta+2);
    hSpc_right->SetMarkerSize(5);
    gStyle->SetTitleFont(102, ""); 
    hSpc_right->SetTitle("6 cm Drift Distance");  
    hSpc_right->GetXaxis()->SetTitle("E_{a} [keV]");         
    hSpc_right->GetXaxis()->SetTitleSize(0.04);
    hSpc_right->GetXaxis()->SetTitleFont(82);
    hSpc_right->GetXaxis()->CenterTitle(); 
    hSpc_right->GetXaxis()->SetLabelFont(82);
    hSpc_right->GetXaxis()->SetTitleOffset(1.1); 
    hSpc_right->GetXaxis()->SetRangeUser(14.38, 14.44); 
    hSpc_right->GetXaxis()->SetLabelSize(0.038);
    hSpc_right->GetYaxis()->SetTitle("#frac{d#phi_{a}}{dE_{a}} @g_{aN}^{eff} [s^{-1}cm^{-2}]");
    hSpc_right->GetYaxis()->SetTitleSize(0.04);
    hSpc_right->GetYaxis()->SetTitleFont(82);
    hSpc_right->GetYaxis()->SetLabelFont(82);
    hSpc_right->GetYaxis()->SetTitleOffset(1.8);
    hSpc_right->GetYaxis()->SetLabelOffset(0.02); 
    hSpc_right->GetYaxis()->CenterTitle(); 
    hSpc_right->GetYaxis()->SetLabelSize(0.04); 
 
    // Create and draw legend for right pad
    TLegend *leg_right = new TLegend(0.5, 0.75, 0.88, 0.85);
    leg_right->SetTextFont(82);
    leg_right->SetTextSize(0.035);
    leg_right->SetLineColor(1);
    leg_right->SetLineStyle(1);
    leg_right->SetLineWidth(1);
    leg_right->SetFillColor(0);
    leg_right->SetFillColorAlpha(kWhite, 0);  
    leg_right->SetLineColor(kWhite);
  
    leg_right->AddEntry(hSpc_right, "From Fe57 decay", "PL");
    leg_right->AddEntry(hConv2_12, "P=1.2bar", "PL");
    leg_right->AddEntry(hConv2_2, "P=2.0bar", "PL");
    leg_right->AddEntry(hConv2_3, "P=3.0bar", "PL");
    leg_right->Draw();

    // Save the canvas as an image
    c1->SaveAs("aN_flux_L_and_2l.png"); 
    c1->SaveAs("aN_flux_L_and_2l.eps");
}




void from_aN_to_histogram(const char* filename) {

    // Open the file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    // Create a histogram
    TH1D *histogram = new TH1D("aN", "aN", 160000, 0, 16); 
    gStyle->SetOptStat(0);

    // Variables to read data from the file
    double x, y;

    // Read data from the file and manually fill the histogram
    while (file >> x >> y) {
        int bin = histogram->GetXaxis()->FindBin(x); // Find the bin corresponding to the x value
        histogram->SetBinContent(bin, y); // Set the content of the bin to the y value
    }

    // Close the file
    file.close();
    
    TFile * fout = new TFile("aN_histogram.root", "recreate"); 
    histogram->Write();
    fout->Close();
    
    TFile * fout2 = new TFile("histograms/aN_histogram.root", "recreate");
    histogram->Write();
    fout2->Close();

    // Create a canvas and draw the histogram
    TCanvas *canvas = new TCanvas("canvas", "Canvas", 1500, 1000);
    histogram->Draw(); // Draw the histogram
    histogram->GetXaxis()->SetRangeUser(14.3, 14.5);
    canvas->SaveAs("aN_histogram.png"); // Save the histogram as an image file
    double area = histogram->Integral();
    cout << "The integral of the histogram is:" << area << endl;
}
