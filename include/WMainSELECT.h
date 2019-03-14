///////////////////////////////////////////////////////////////////////////
//                                                                       //
// NOTICE OF COPYRIGHT                                                   //
//                                                                       //
//                       Copyright (C) 2019                              //
//                Arnold Alonso¹  - Julian Salamanca²                    //
//                                                                       //
//                aralonsoa@correo.udistrital.edu.co¹                    //
//                   jasalamanca@udistrital.edu.co²                      //
//                                                                       //
//       ¹²Grupo de Física e Informática (FISINFOR) Universidad          //
//                  Distrital Francisco José de Caldas                   //
//                                                                       //
//                                                                       //
//                 https://github.com/fisinforgh/CHAOS                   //
//                                                                       //
// This program is free software; you can redistribute it and/or modify  //
// it under the terms of the GNU General Public License as published by  //
// the Free Software Foundation; either version 2 of the License, or     //
// (at your option) any later version.                                   //
//                                                                       //
// This program is distributed in the hope that it will be useful,       //
// but WITHOUT ANY WARRANTY; without even the implied warranty of        //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         //
// GNU General Public License for more details:                          //
//                                                                       //
//               http://www.gnu.org/copyleft/gpl.html                    //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

#ifndef _CHAOS_WMainSELECT
#define _CHAOS_WMainSELECT

#include "WMainPAM.h"
#include "WMainPE.h"
#include "WMainCHUA.h"

#include "TRootEmbeddedCanvas.h"
#include "TGButtonGroup.h"
#include "TGNumberEntry.h"
#include "TApplication.h"
#include "TRootCanvas.h"
#include "TGTextEntry.h"
#include "TGComboBox.h"
#include "TCurlyLine.h"
#include "RQ_OBJECT.h"
#include "TGClient.h"
#include "TG3DLine.h"
#include "TGLayout.h"
#include "TGClient.h"
#include "TGWindow.h"
#include "TGButton.h"
#include "TGraph2D.h"
#include "TGFrame.h"
#include "TGLabel.h"
#include "TCanvas.h"
#include "TSystem.h"
#include "TImage.h"
#include "TText.h"
#include "TGTab.h"

#include <fstream>
#include <iostream>
#include <iomanip> 

#include "TMatrixDUtils.h"
#include "TMatrixDEigen.h"
#include "TMultiGraph.h"
#include "Riostream.h"
#include "TEllipse.h"
#include "TMatrixD.h"
#include "TVectorD.h"
#include "TArrayD.h"
#include "TGraph.h"
#include "TArrow.h"
#include "TTimer.h"
#include "TMath.h"
#include "TLine.h"
#include "TAxis.h"
#include "TBox.h"

using namespace std;

class WMainSELECT{
  RQ_OBJECT("WMainSELECT");
 private:
  TRootEmbeddedCanvas *EmbeddedCanvasInformation;
  TGHorizontalFrame   *HFrame1;
  TGVerticalFrame     *VFrame11, *VFrame12;
  TGTextButton        *TextButtonPAM, *TextButtonPE, *TextButtonCHUA, *TextButtonExit;
  TGMainFrame         *MainFrame;   
  TCanvas             *CanvasInformation;
  TImage              *imge;
  
  Int_t               IsActive;
  
 public:
  WMainSELECT(const TGWindow *p, UInt_t w, UInt_t h, UInt_t options);
  virtual ~WMainSELECT();  
  
  void TBPAMCliked();
  void TBPECliked();
  void TBCHUACliked();
  void TBExitCliked();
  
  ClassDef(WMainSELECT, 0);
};

#endif
