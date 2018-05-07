#ifdef __CLING__
R__LOAD_LIBRARY(libDelphes.so)
#include "/u/user/hgass66/MadGraph/MG5_aMC_v2_6_0/Delphes/classes/DelphesClasses.h"
#include "/u/user/hgass66/MadGraph/MG5_aMC_v2_6_0/Delphes/external/ExRootAnalysis/ExRootTreeReader.h"
#include "TMath.h"
#include <iostream>
#include "TClonesArray.h"
#include "TH2F.h"
#include "TH1F.h"
#include <TVector2.h>
#include <TProfile.h>
#endif
using namespace std;

void pTeta(){

    TChain *inChain = new TChain("Delphes");

    TFile *myFile = new TFile("sig+bg/pTeta.root","recreate");

