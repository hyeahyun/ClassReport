void test(){

    TFile *output = new TFile("test.root","recreate");

    TFile *zz = new TFile("/u/user/hgass66/MadGraph/MG5_aMC_v2_5_5/song/data13/zz.root");

    TH1F *h1 = (TH1F*)zz->Get("histwM");

    h1->Write();

    output->Close();

}
