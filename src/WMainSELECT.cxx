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

#include "../include/WMainSELECT.h"

using namespace std;

WMainSELECT::WMainSELECT(const TGWindow *p, UInt_t w, UInt_t h, UInt_t options){
  //=======================================================================================================
  //                                               Main Frame
  //=======================================================================================================
  MainFrame = new TGMainFrame(p, w, h, options);
  MainFrame -> Connect("CloseWindow()", "WMainSELECT", this, "TBExitCliked()");
  MainFrame -> SetName("MainFrame");
  MainFrame -> SetWindowName("CHAOS");
  MainFrame -> SetCleanup(kDeepCleanup);
  MainFrame -> SetIconPixmap("/usr/share/Chaos_V0.1/icon.jpg");
  MainFrame -> SetIconName("Chaos");
  MainFrame -> SetWMSizeHints(425, 239, 425, 239, 0, 0);
  //=======================================================================================================
  //                                           Horizontal Frame I
  //=======================================================================================================
  HFrame1 = new TGHorizontalFrame(MainFrame, 423, 237, kHorizontalFrame);
  HFrame1 -> SetName("HFrame1");
  //=======================================================================================================
  //                                            Vertical Frame I, I
  //=======================================================================================================
  VFrame11 = new TGVerticalFrame(HFrame1, 280, 227, kVerticalFrame);
  VFrame11 -> SetName("VFrame11");
  //-------------------------------------------------------------------------------------------------------
  //                                              Information Canvas
  //-------------------------------------------------------------------------------------------------------
  EmbeddedCanvasInformation = new TRootEmbeddedCanvas(0, VFrame11, 276, 223, kChildFrame);
  EmbeddedCanvasInformation -> SetName("EmbeddedCanvasInformation");
  Int_t wEmbeddedCanvasInformation = EmbeddedCanvasInformation -> GetCanvasWindowId();
  CanvasInformation = new TCanvas("CanvasInformation", 10, 10, wEmbeddedCanvasInformation);
  CanvasInformation -> SetFillColor(kWhite);

  CanvasInformation -> SetRightMargin(0.01);
  CanvasInformation -> SetLeftMargin(0.01);
  CanvasInformation -> SetTopMargin(0.01);
  CanvasInformation -> SetBottomMargin(0.01);
  CanvasInformation -> SetFillColor(kWhite);
  //-------------------------------------------------------------------------------------------------------
  imge = TImage::Open("/usr/share/Chaos_V0.1/Information.jpg");
  //img -> Scale(CanvasDiagram -> GetWw(), CanvasDiagram -> GetWh());
  imge -> Draw();
  //-------------------------------------------------------------------------------------------------------
  EmbeddedCanvasInformation -> AdoptCanvas(CanvasInformation);
  VFrame11 -> AddFrame(EmbeddedCanvasInformation, new TGLayoutHints(kLHintsLeft | kLHintsCenterX |
								    kLHintsTop | kLHintsCenterY |
								    kLHintsExpandX | kLHintsExpandY
								    , 2, 2, 2, 2));
  EmbeddedCanvasInformation -> MoveResize(2, 2, 276, 223);
  //-------------------------------------------------------------------------------------------------------
  HFrame1 -> AddFrame(VFrame11);
  VFrame11 -> MoveResize(2, 2, 280, 227);
  //=======================================================================================================
  //                                            Vertical Frame I, II
  //=======================================================================================================
  VFrame12 = new TGVerticalFrame(HFrame1,118,227,kVerticalFrame);
  VFrame12->SetName("VFrame12");
  //PAM Button---------------------------------------------------------------------------------------------
  TextButtonPAM = new TGTextButton(VFrame12, "&Pendulum", -1, TGTextButton::GetDefaultGC()()
				   , TGTextButton::GetDefaultFontStruct(), kRaisedFrame);
  TextButtonPAM -> SetTextJustify(36);
  TextButtonPAM -> SetMargins(0, 0, 0, 0);
  TextButtonPAM -> SetWrapLength(-1);
  TextButtonPAM -> Resize(114, 52);
  VFrame12 -> AddFrame(TextButtonPAM, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  TextButtonPAM -> MoveResize(2, 2, 114, 52);
  TextButtonPAM -> Connect("Clicked()", "WMainSELECT", this, "TBPAMCliked()");
  //PE Button----------------------------------------------------------------------------------------------
  TextButtonPE = new TGTextButton(VFrame12, "&Spring pendulum", -1,TGTextButton::GetDefaultGC()()
				  , TGTextButton::GetDefaultFontStruct(), kRaisedFrame);
  TextButtonPE -> SetTextJustify(36);
  TextButtonPE -> SetMargins(0,0,0,0);
  TextButtonPE -> SetWrapLength(-1);
  TextButtonPE -> Resize(114, 53);
  VFrame12 -> AddFrame(TextButtonPE,  new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  TextButtonPE -> MoveResize(2, 58, 114, 53);
  TextButtonPE -> Connect("Clicked()", "WMainSELECT", this, "TBPECliked()");
  //CHUA Button--------------------------------------------------------------------------------------------
  TextButtonCHUA = new TGTextButton(VFrame12, "&Chua's Circuit", -1,TGTextButton::GetDefaultGC()()
				    , TGTextButton::GetDefaultFontStruct(), kRaisedFrame);
  TextButtonCHUA -> SetTextJustify(36);
  TextButtonCHUA -> SetMargins(0,0,0,0);
  TextButtonCHUA -> SetWrapLength(-1);
  TextButtonCHUA -> Resize(114,53);
  VFrame12 -> AddFrame(TextButtonCHUA, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							  kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							  , 2, 2, 2, 2));
  TextButtonCHUA -> MoveResize(2,115,114,53);
  TextButtonCHUA -> Connect("Clicked()", "WMainSELECT", this, "TBCHUACliked()");
  //Exit Button--------------------------------------------------------------------------------------------
  TextButtonExit = new TGTextButton(VFrame12, "&Exit", -1,TGTextButton::GetDefaultGC()()
				    , TGTextButton::GetDefaultFontStruct() ,kRaisedFrame);
  TextButtonExit -> SetTextJustify(36);
  TextButtonExit -> SetMargins(0,0,0,0);
  TextButtonExit -> SetWrapLength(-1);
  TextButtonExit -> Resize(114, 53);
  VFrame12 -> AddFrame(TextButtonExit, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							 kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							 , 2, 2, 2, 2));
  TextButtonExit -> MoveResize(2,172,114,53);
  TextButtonExit -> Connect("Clicked()", "WMainSELECT", this, "TBExitCliked()");
  //=======================================================================================================
  VFrame12 -> MoveResize(300, 2, 118, 227);
  HFrame1 -> AddFrame(VFrame12,  new TGLayoutHints(kLHintsCenterX | kLHintsCenterY | kLHintsExpandX |
						   kLHintsExpandY, 2, 2, 2, 2));
  MainFrame -> AddFrame(HFrame1,  new TGLayoutHints(kLHintsCenterX | kLHintsCenterY | kLHintsExpandX |
						    kLHintsExpandY, 1, 1, 1, 1));
  //=======================================================================================================
  MainFrame -> SetMWMHints(kMWMDecorAll, kMWMFuncAll, kMWMInputModeless);
  MainFrame -> MapSubwindows();
  MainFrame -> Resize(425, 239);
  MainFrame -> MapWindow();
}  

void WMainSELECT::TBPAMCliked(){
  new WMainPAM(gClient -> GetRoot(), 10, 10, kMainFrame | kVerticalFrame);  
}

void WMainSELECT::TBPECliked(){
  new WMainPE(gClient -> GetRoot(), 10, 10, kMainFrame | kVerticalFrame);
}

void WMainSELECT::TBCHUACliked(){
  new WMainCHUA(gClient -> GetRoot(), 10, 10, kMainFrame | kVerticalFrame);
}

void WMainSELECT::TBExitCliked(){
  gApplication -> Terminate(0);
}

WMainSELECT::~WMainSELECT(){
  MainFrame -> Cleanup();
  delete MainFrame;
}
