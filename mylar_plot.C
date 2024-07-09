void transmittance() {
    // Open files
    std::ifstream infile1("Mylar.dat");
    std::ifstream infile2("Al.dat");

    if (!infile1 || !infile2) {
        std::cerr << "Error: Unable to open input files." << std::endl;
        return;
    }

    // Vectors to store data
    std::vector<double> x_values;
    std::vector<double> y_values1;
    std::vector<double> y_values2;
    std::vector<double> multiplied_values;

    // Read data from Mylar.dat
    double x1, y1;
    while (infile1 >> x1 >> y1) {
        x_values.push_back(x1);
        y_values1.push_back(y1);
    }

    // Read data from Al.dat
    double x2, y2;
    while (infile2 >> x2 >> y2) {
        y_values2.push_back(y2);
    }

    // Check if both files have the same number of entries
    if (x_values.size() != y_values2.size()) {
        std::cerr << "Error: Number of entries in the two files do not match!" << std::endl;
        return;
    }

    // Perform multiplication
    for (size_t i = 0; i < x_values.size(); ++i) {
        multiplied_values.push_back(y_values1[i] * y_values2[i]);
    }

    // Create TGraph
    TGraph *graph = new TGraph(x_values.size(), &x_values[0], &multiplied_values[0]);

    // Divide X axis values by 1000 for display
    for (int i = 0; i < graph->GetN(); ++i) {
        double x, y;
        graph->GetPoint(i, x, y);
        graph->SetPoint(i, x / 1000.0, y); // Divide x by 1000
    }

    // Set graphical attributes
    graph->SetMarkerColor(kTeal-1);
    graph->SetLineWidth(2);
    graph->SetLineColor(kTeal+4);
    gStyle->SetTitleFont(102, "");
    graph->SetTitle("");
    graph->GetXaxis()->SetTitle("Energy (MeV)"); // Adjusted to MeV since divided by 1000
    graph->GetXaxis()->SetTitleSize(0.05);
    graph->GetXaxis()->SetTitleFont(82);
    graph->GetXaxis()->CenterTitle();
    graph->GetXaxis()->SetLabelFont(82);
    graph->GetXaxis()->SetTitleOffset(1.1);
    graph->GetXaxis()->SetLabelSize(0.0475);
    graph->GetXaxis()->SetRangeUser(0,17);
    
    graph->GetYaxis()->SetTitle("Transmittance");
    graph->GetYaxis()->SetTitleSize(0.05);
    graph->GetYaxis()->SetTitleFont(82);
    graph->GetYaxis()->SetLabelFont(82);
    graph->GetYaxis()->SetTitleOffset(1.6);
    graph->GetYaxis()->SetLabelOffset(0.02);
    graph->GetYaxis()->CenterTitle();
    graph->GetYaxis()->SetLabelSize(0.0475);
    
    TLegend *legend = new TLegend(0.27,0.4,0.7,0.5);  
    legend->SetTextSize(0.035);
    legend->SetTextFont(82); 
    legend->AddEntry(graph,"Cathode window transmittance","pl"); 
    legend->SetFillColor(kWhite); 
    legend->SetLineColor(kWhite);
    
    // Draw the graph
    TCanvas *c1 = new TCanvas("c1", "Multiplication Graph", 1000, 1000);
    c1->cd()->SetMargin(0.2, 0.03, 0.15, 0.1);
    graph->Draw("APL");
    
    auto nPoints = graph->GetN(); // number of points in your TGraph
    printf("Total entries %d\n",nPoints);
    double x,y;
    for(int i=0;i<=nPoints;i++)
    {
        x=graph->GetPointX(i);
        y=graph->GetPointY(i);
        printf("[%1.2f, %1.2f]\n",x,y*100);
    }
   
    
    legend->Draw();

    // Save or display the plot
    c1->SaveAs("transmittance_plot.png");
    c1->SaveAs("transmittance_plot.eps");

}

void multiplied_data() {
    // Open input files
    std::ifstream mylar_file("Mylar.dat");
    std::ifstream al_file("Al.dat");

    // Check if files are open
    if (!mylar_file.is_open()) {
        std::cerr << "Failed to open Mylar.dat" << std::endl;
        return;
    }
    if (!al_file.is_open()) {
        std::cerr << "Failed to open Al.dat" << std::endl;
        return;
    }

    // Open output file
    std::ofstream output_file("together.dat");

    // Variables to hold data
    double mylar_x, mylar_y;
    double al_x, al_y;

    // Vectors to store data
    std::vector<double> mylar_x_values;
    std::vector<double> mylar_y_al_y_values;

    // Read and process data line by line
    while (mylar_file >> mylar_x >> mylar_y && al_file >> al_x >> al_y) {
        // Store data in vectors
        mylar_x_values.push_back(mylar_x / 1000.0); // Divide mylar_x by 1000
        mylar_y_al_y_values.push_back(mylar_y * al_y);
    }

    // Close files
    mylar_file.close();
    al_file.close();

    // Write data to output file
    output_file << "{";
    for (size_t i = 0; i < mylar_x_values.size(); ++i) {
        output_file << mylar_x_values[i];
        if (i != mylar_x_values.size() - 1) {
            output_file << ", ";
        }
    }
    output_file << "}," << std::endl;

    output_file << "{";
    for (size_t i = 0; i < mylar_y_al_y_values.size(); ++i) {
        output_file << mylar_y_al_y_values[i];
        if (i != mylar_y_al_y_values.size() - 1) {
            output_file << ", ";
        }
    }
    output_file << "}," << std::endl;

    // Close output file
    output_file.close();

    std::cout << "Data processing complete. Output written to together.dat" << std::endl;
}


