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

#include "../include/WMainCHUA.h"

using namespace std;

WMainCHUA::WMainCHUA(const TGWindow *p, UInt_t w, UInt_t h, UInt_t options){
  //=======================================================================================================
  //                                               Main Frame
  //=======================================================================================================
  MainFrame = new TGMainFrame(p, w, h, options);
  MainFrame -> Connect("CloseWindow()", "WMainCHUA", this, "TBExitCliked()");
  MainFrame -> SetName("MainFrame ");
  MainFrame -> SetCleanup(kDeepCleanup);
  MainFrame -> SetWindowName("Chua's Circuit");
  MainFrame -> SetIconPixmap("/usr/share/Chaos_V0.1/icon.jpg");
  MainFrame -> SetIconName("CHAOS");
  //=======================================================================================================
  //                                           Horizontal Frame I
  //=======================================================================================================
  HFrame1 = new TGHorizontalFrame(MainFrame, 1123, 404, kHorizontalFrame);
  HFrame1 -> SetName("HFrame1");
  //=======================================================================================================
  //                                           Vertical Frame I, I
  //=======================================================================================================
  VFrame11 = new TGVerticalFrame(HFrame1, 370, 400, kVerticalFrame);
  VFrame11->SetName("VFrame11");
  //-------------------------------------------------------------------------------------------------------
  //                                         Resistances Group Frame 
  //-------------------------------------------------------------------------------------------------------
  GroupRes = new TGGroupFrame(VFrame11, "Resistance");
  //-------------------------------------------------------------------------------------------------------
  // Horizontal Frame R & R_0
  //-------------------------------------------------------------------------------------------------------
  HFrame1111 = new TGHorizontalFrame(GroupRes, 330, 52, kHorizontalFrame);
  //Resistance Label---------------------------------------------------------------------------------------
  LabelRes1 = new TGLabel(HFrame1111, "R[ohm]: ");
  LabelRes1 -> SetTextJustify(36);
  LabelRes1 -> SetMargins(0, 0, 0, 0);
  LabelRes1 -> SetWrapLength(-1);
  HFrame1111 -> AddFrame(LabelRes1, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						      kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						      , 2, 2, 2, 2));
  //Resistance Number Entry--------------------------------------------------------------------------------
  NumEntRes1 = new TGNumberEntry(HFrame1111, (Double_t) 0, 9, -1, TGNumberFormat::kNESReal
				 , TGNumberFormat::kNEAAnyNumber
				 , TGNumberFormat::kNELLimitMinMax, 0.00001, 10000000.);
  HFrame1111 -> AddFrame(NumEntRes1, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						       kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntRes1 -> SetNumber(0.33065);
  //Resistance_0 Label-------------------------------------------------------------------------------------
  LabelRes2 = new TGLabel(HFrame1111, "R_0[ohm]: ");
  LabelRes2 -> SetTextJustify(36);
  LabelRes2 -> SetMargins(0, 0, 0, 0);
  LabelRes2 -> SetWrapLength(-1);
  HFrame1111 -> AddFrame(LabelRes2, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						      kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						      , 2, 2, 2, 2));
  //Resistance_0 Number Entry------------------------------------------------------------------------------
  NumEntRes2 = new TGNumberEntry(HFrame1111, (Double_t) 0, 9, -1, TGNumberFormat::kNESReal
				 , TGNumberFormat::kNEAAnyNumber
				 , TGNumberFormat::kNELLimitMinMax, 0.0, 10000000.);
  HFrame1111 -> AddFrame(NumEntRes2, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						       kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntRes2 -> SetNumber(0.00035);
  //-------------------------------------------------------------------------------------------------------
  GroupRes -> AddFrame(HFrame1111, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						     kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						     , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  GroupRes -> SetLayoutManager(new TGVerticalLayout(GroupRes));
  GroupRes -> Resize(366, 88);
  VFrame11 -> AddFrame(GroupRes, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						   kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						   , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //                                         Capacitances Group Frame 
  //-------------------------------------------------------------------------------------------------------
  GroupCap = new TGGroupFrame(VFrame11, "Capacitance");
  //-------------------------------------------------------------------------------------------------------
  // Horizontal Frame C_1 & C_2
  //-------------------------------------------------------------------------------------------------------
  HFrame1121 = new TGHorizontalFrame(GroupCap,330,53,kHorizontalFrame);
  //Capacitance_1 Label------------------------------------------------------------------------------------
  LabelCap1 = new TGLabel(HFrame1121, "C_1[F]: ");
  LabelCap1 -> SetTextJustify(36);
  LabelCap1 -> SetMargins(0, 0, 0, 0);
  LabelCap1 -> SetWrapLength(-1);
  HFrame1121 -> AddFrame(LabelCap1, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						      kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						      , 2, 2, 2, 2));
  //Capacitance_1 Number Entry-----------------------------------------------------------------------------
  NumEntCap1 = new TGNumberEntry(HFrame1121, (Double_t) 0, 9, -1, TGNumberFormat::kNESReal
				 , TGNumberFormat::kNEAAnyNumber
				 , TGNumberFormat::kNELLimitMinMax, 0.00000001, 10.);
  HFrame1121 -> AddFrame(NumEntCap1, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						       kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntCap1 -> SetNumber(1.0);
  //Capacitance_2 Label------------------------------------------------------------------------------------
  LabelCap2 = new TGLabel(HFrame1121,"C_2[F]: ");
  LabelCap2 -> SetTextJustify(36);
  LabelCap2 -> SetMargins(0,0,0,0);
  LabelCap2 -> SetWrapLength(-1);
  HFrame1121 -> AddFrame(LabelCap2, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						      kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						      , 2, 2, 2, 2));
  //Capacitance_2 Number Entry-----------------------------------------------------------------------------
  NumEntCap2 = new TGNumberEntry(HFrame1121, (Double_t) 0, 9, -1, TGNumberFormat::kNESReal
				 , TGNumberFormat::kNEAAnyNumber
				 , TGNumberFormat::kNELLimitMinMax, 0.00000001, 10.);
  HFrame1121 -> AddFrame(NumEntCap2, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						       kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntCap2 -> SetNumber(9.3515);
  //-------------------------------------------------------------------------------------------------------
  GroupCap -> AddFrame(HFrame1121, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						     kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						     , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  GroupCap -> SetLayoutManager(new TGVerticalLayout(GroupCap));
  GroupCap -> Resize(366,89);
  VFrame11 -> AddFrame(GroupCap, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						   kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						   , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //                                    Inductance & CalculateButton Group Frame 
  //-------------------------------------------------------------------------------------------------------
  GroupInduc = new TGGroupFrame(VFrame11, "Inductance");
  //-------------------------------------------------------------------------------------------------------
  // Horizontal Frame L & CalculateButton
  //-------------------------------------------------------------------------------------------------------
  HFrame1131 = new TGHorizontalFrame(GroupInduc, 330, 52, kHorizontalFrame);
  //-------------------------------------------------------------------------------------------------------
  // Horizontal Frame L
  //-------------------------------------------------------------------------------------------------------
  HFrame11311 = new TGHorizontalFrame(HFrame1131, 161, 48, kHorizontalFrame);
  //Inductance Label---------------------------------------------------------------------------------------
  LabelInduc = new TGLabel(HFrame11311, "L[H]: ");
  LabelInduc -> SetTextJustify(36);
  LabelInduc -> SetMargins(0, 0, 0, 0);
  LabelInduc -> SetWrapLength(-1);
  HFrame11311 -> AddFrame(LabelInduc, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  //Inductance Number Entry--------------------------------------------------------------------------------
  NumEntInduc = new TGNumberEntry(HFrame11311, (Double_t) 0, 9, -1, TGNumberFormat::kNESReal
				  , TGNumberFormat::kNEAAnyNumber
				  , TGNumberFormat::kNELLimitMinMax, 0.00000001, 1.);
  HFrame11311 -> AddFrame(NumEntInduc, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							 kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntInduc -> SetNumber(0.06913);
  //-------------------------------------------------------------------------------------------------------
  HFrame1131 -> AddFrame(HFrame11311, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  // Horizontal Frame CalculateButton
  //-------------------------------------------------------------------------------------------------------
  HFrame11312 = new TGHorizontalFrame(HFrame1131, 161, 48, kHorizontalFrame);
  //Calculate Button---------------------------------------------------------------------------------------
  TextButtonCalculate = new TGTextButton(HFrame11312, "&Calculate", -1, TGTextButton::GetDefaultGC()()
					 , TGTextButton::GetDefaultFontStruct(), kRaisedFrame);
  TextButtonCalculate -> SetTextJustify(36);
  TextButtonCalculate -> SetMargins(0, 0, 0, 0);
  TextButtonCalculate -> SetWrapLength(-1);
  TextButtonCalculate -> Resize(157, 44);
  HFrame11312 -> AddFrame(TextButtonCalculate, new TGLayoutHints(kLHintsLeft | kLHintsCenterX |
								 kLHintsTop | kLHintsCenterY |
								 kLHintsExpandX | kLHintsExpandY
								 , 2, 2, 2, 2));
  TextButtonCalculate -> Connect("Clicked()", "WMainCHUA", this, "TBCalculateSimulCliked()");
  //-------------------------------------------------------------------------------------------------------
  HFrame1131 -> AddFrame(HFrame11312, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2,2 , 2, 2));
  //-------------------------------------------------------------------------------------------------------
  GroupInduc -> AddFrame(HFrame1131, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						       kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						       , 2, 2, 2, 2));
  GroupInduc -> SetLayoutManager(new TGVerticalLayout(GroupInduc));
  GroupInduc -> Resize(366,88);
  //-------------------------------------------------------------------------------------------------------
  VFrame11 -> AddFrame(GroupInduc, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						     kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						     , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //                                          Diode parameters Group Frame 
  //-------------------------------------------------------------------------------------------------------
  GroupDioPar = new TGGroupFrame(VFrame11, "Diode parameters");
  //-------------------------------------------------------------------------------------------------------
  // G_a & G_b Frame
  //-------------------------------------------------------------------------------------------------------
  HFrame1141 = new TGHorizontalFrame(GroupDioPar, 330, 24, kHorizontalFrame);
  //G_a Label----------------------------------------------------------------------------------------------
  LabelGa = new TGLabel(HFrame1141, "Ga[A/V]: ");
  LabelGa -> SetTextJustify(36);
  LabelGa -> SetMargins(0, 0, 0, 0);
  LabelGa -> SetWrapLength(-1);
  HFrame1141 -> AddFrame(LabelGa, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						    kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						    , 2, 2, 2, 2));
  //G_a Number Entry---------------------------------------------------------------------------------------
  NumEntGa = new TGNumberEntry(HFrame1141, (Double_t) 0, 9, -1, TGNumberFormat::kNESReal
			       , TGNumberFormat::kNEAAnyNumber
			       , TGNumberFormat::kNELLimitMinMax, -100., 100.);
  HFrame1141 -> AddFrame(NumEntGa, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						     kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntGa -> SetNumber(-3.4429);
  NumEntGa -> Connect("ValueSet(Long_t)", "WMainCHUA", this, "DrawDiodeFunct()");
  //G_b Label----------------------------------------------------------------------------------------------
  LabelGb = new TGLabel(HFrame1141, "Gb[A/V]: ");
  LabelGb -> SetTextJustify(36);
  LabelGb -> SetMargins(0,0,0,0);
  LabelGb -> SetWrapLength(-1);
  HFrame1141 -> AddFrame(LabelGb, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						    kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						    , 2, 2, 2, 2));
  //G_b Number Entry---------------------------------------------------------------------------------------
  NumEntGb = new TGNumberEntry(HFrame1141, (Double_t) 0, 9, -1, TGNumberFormat::kNESReal
			       , TGNumberFormat::kNEAAnyNumber
			       , TGNumberFormat::kNELLimitMinMax, -100., 100.);
  HFrame1141 -> AddFrame(NumEntGb, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						     kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntGb -> SetNumber(-2.1849);
  NumEntGb -> Connect("ValueSet(Long_t)", "WMainCHUA", this, "DrawDiodeFunct()");
  //-------------------------------------------------------------------------------------------------------
  GroupDioPar -> AddFrame(HFrame1141, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //E Frame
  //-------------------------------------------------------------------------------------------------------
  HFrame1142 = new TGHorizontalFrame(GroupDioPar,330,25,kHorizontalFrame);
  //E Label------------------------------------------------------------------------------------------------
  LabelE = new TGLabel(HFrame1142, "E[V]: ");
  LabelE -> SetTextJustify(36);
  LabelE -> SetMargins(0,0,0,0);
  LabelE -> SetWrapLength(-1);
  HFrame1142 -> AddFrame(LabelE, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						   kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						   , 2, 2, 2, 2));
  //E Number Entry-----------------------------------------------------------------------------------------
  NumEntE = new TGNumberEntry(HFrame1142, (Double_t) 0, 9, -1, TGNumberFormat::kNESReal
			      , TGNumberFormat::kNEAAnyNumber
			      , TGNumberFormat::kNELLimitMinMax, -100., 100.);
  HFrame1142 -> AddFrame(NumEntE, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						    kLHintsCenterY, 2, 2, 2, 2));
  NumEntE -> SetNumber(1.);
  NumEntE -> Connect("ValueSet(Long_t)", "WMainCHUA", this, "DrawDiodeFunct()");
  //-------------------------------------------------------------------------------------------------------
  GroupDioPar -> AddFrame(HFrame1142, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  GroupDioPar -> SetLayoutManager(new TGVerticalLayout(GroupDioPar));
  GroupDioPar -> Resize(366,89);
  //-------------------------------------------------------------------------------------------------------
  VFrame11 -> AddFrame(GroupDioPar, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						      kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						      , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //                                     Initial Conditions Group Frame 
  //-------------------------------------------------------------------------------------------------------
  GroupIniCon = new TGGroupFrame(VFrame11, "Initial Conditions");
  //-------------------------------------------------------------------------------------------------------
  // V_1 & V_2 Frame
  //-------------------------------------------------------------------------------------------------------
  HFrame1151 = new TGHorizontalFrame(GroupIniCon, 330, 24, kHorizontalFrame);
  //V_1 Label----------------------------------------------------------------------------------------------
  LabelV1 = new TGLabel(HFrame1151, "V1[V]: ");
  LabelV1 -> SetTextJustify(36);
  LabelV1 -> SetMargins(0, 0, 0, 0);
  LabelV1 -> SetWrapLength(-1);
  HFrame1151 -> AddFrame(LabelV1, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						    kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						    , 2, 2, 2, 2));
  //V_1 Number Entry---------------------------------------------------------------------------------------
  NumEntV1 = new TGNumberEntry(HFrame1151, (Double_t) 0, 9, -1, TGNumberFormat::kNESReal
			       , TGNumberFormat::kNEAAnyNumber
			       , TGNumberFormat::kNELLimitMinMax, -10000., 10000.);
  HFrame1151 -> AddFrame(NumEntV1, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						     kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntV1 -> SetNumber(0.1);
  //V_2 Label----------------------------------------------------------------------------------------------
  LabelV2 = new TGLabel(HFrame1151, "V2[V]: ");
  LabelV2 -> SetTextJustify(36);
  LabelV2 -> SetMargins(0, 0, 0, 0);
  LabelV2 -> SetWrapLength(-1);
  HFrame1151 -> AddFrame(LabelV2, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						    kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						    , 2, 2, 2, 2));
  //V_2 Number Entry---------------------------------------------------------------------------------------
  NumEntV2 = new TGNumberEntry(HFrame1151, (Double_t) 0, 9, -1, TGNumberFormat::kNESReal
			       , TGNumberFormat::kNEAAnyNumber
			       , TGNumberFormat::kNELLimitMinMax, -10000., 10000.);
  HFrame1151 -> AddFrame(NumEntV2, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						     kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntV2 -> SetNumber(0.1);
  //-------------------------------------------------------------------------------------------------------
  GroupIniCon -> AddFrame(HFrame1151, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  // I_3 Frame
  //-------------------------------------------------------------------------------------------------------
  HFrame1152 = new TGHorizontalFrame(GroupIniCon,330,25,kHorizontalFrame);
  //I_3 Label----------------------------------------------------------------------------------------------
  LabelI3 = new TGLabel(HFrame1152, "I3[A]: ");
  LabelI3 -> SetTextJustify(36);
  LabelI3 -> SetMargins(0, 0, 0, 0);
  LabelI3 -> SetWrapLength(-1);
  HFrame1152 -> AddFrame(LabelI3, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						    kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						    , 2, 2, 2, 2));
  //I_3 Number Entry---------------------------------------------------------------------------------------
  NumEntI3 = new TGNumberEntry(HFrame1152, (Double_t) 0, 9, -1, TGNumberFormat::kNESReal
			       , TGNumberFormat::kNEAAnyNumber
			       , TGNumberFormat::kNELLimitMinMax, -10000., 10000.);
  HFrame1152 -> AddFrame(NumEntI3, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						     kLHintsCenterY, 2, 2, 2, 2));
  NumEntI3 -> SetNumber(0.1);
  //-------------------------------------------------------------------------------------------------------
  GroupIniCon -> AddFrame(HFrame1152, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  GroupIniCon -> SetLayoutManager(new TGVerticalLayout(GroupIniCon));
  GroupIniCon -> Resize(366, 89);
  //-------------------------------------------------------------------------------------------------------
  VFrame11 -> AddFrame(GroupIniCon, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						      kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						      , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //                                         Buttons Horizontal Frame
  //-------------------------------------------------------------------------------------------------------
  HFrame116 = new TGHorizontalFrame(VFrame11, 366, 26, kHorizontalFrame);
  HFrame116 -> SetName("HFrame116");
  //Play Button--------------------------------------------------------------------------------------------
  TextButtonPlay = new TGTextButton(HFrame116, "&Play", -1,TGTextButton::GetDefaultGC()()
				    ,TGTextButton::GetDefaultFontStruct(), kRaisedFrame);
  TextButtonPlay -> SetTextJustify(36);
  TextButtonPlay -> SetMargins(0,0,0,0);
  TextButtonPlay -> SetWrapLength(-1);
  TextButtonPlay -> Resize(118,22);
  HFrame116 -> AddFrame(TextButtonPlay, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							  kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  TextButtonPlay -> Connect("Clicked()", "WMainCHUA", this, "TBPlayCliked()");
  //Clear Button-------------------------------------------------------------------------------------------
  TextButtonClear = new TGTextButton(HFrame116, "&Clear", -1, TGTextButton::GetDefaultGC()()
				     , TGTextButton::GetDefaultFontStruct(), kRaisedFrame);
  TextButtonClear -> SetTextJustify(36);
  TextButtonClear -> SetMargins(0, 0, 0, 0);
  TextButtonClear -> SetWrapLength(-1);
  TextButtonClear -> Resize(118, 22);
  HFrame116 -> AddFrame(TextButtonClear, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							   kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  TextButtonClear -> Connect("Clicked()", "WMainCHUA", this, "TBClearCliked()");
  //Exit Button--------------------------------------------------------------------------------------------
  TextButtonExit = new TGTextButton(HFrame116, "&Exit", -1, TGTextButton::GetDefaultGC()()
				    , TGTextButton::GetDefaultFontStruct(), kRaisedFrame);
  TextButtonExit -> SetTextJustify(36);
  TextButtonExit -> SetMargins(0, 0, 0, 0);
  TextButtonExit -> SetWrapLength(-1);
  TextButtonExit -> Resize(118, 22);
  HFrame116 -> AddFrame(TextButtonExit, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							  kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  TextButtonExit -> Connect("Clicked()", "WMainCHUA", this, "TBExitCliked()");
  //-------------------------------------------------------------------------------------------------------
  VFrame11 -> AddFrame(HFrame116, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						    kLHintsExpandX, 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  HFrame1 -> AddFrame(VFrame11, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						  kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						  , 2, 2, 2, 2));
  //=======================================================================================================
  //                                           Vertical Frame I, II
  //=======================================================================================================
  VFrame12 = new TGVerticalFrame(HFrame1, 370, 490, kVerticalFrame);
  VFrame12 -> SetName("VFrame12");
  //-------------------------------------------------------------------------------------------------------
  //                                              Diagram Canvas
  //-------------------------------------------------------------------------------------------------------
  EmbeddedDiagramCanvas = new TRootEmbeddedCanvas(0, VFrame12, 366, 234, kSunkenFrame);
  EmbeddedDiagramCanvas -> SetName("EmbeddedDiagramCanvas");
  Int_t wEmbeddedDiagramCanvas = EmbeddedDiagramCanvas -> GetCanvasWindowId();
  CanvasDiagram = new TCanvas("CanvasDiagram", 10, 10, wEmbeddedDiagramCanvas);
  CanvasDiagram -> ToggleEditor();
  CanvasDiagram -> SetRightMargin(0.01);
  CanvasDiagram -> SetLeftMargin(0.01);
  CanvasDiagram -> SetTopMargin(0.01);
  CanvasDiagram -> SetBottomMargin(0.01);
  CanvasDiagram -> SetFillColor(kWhite);
  //-------------------------------------------------------------------------------------------------------
  img = TImage::Open("/usr/share/Chaos_V0.1/chua.jpg");
  //img -> Scale(CanvasDiagram -> GetWw(), CanvasDiagram -> GetWh());
  img -> Draw();
  //-------------------------------------------------------------------------------------------------------
  EmbeddedDiagramCanvas -> AdoptCanvas(CanvasDiagram);
  VFrame12 -> AddFrame(EmbeddedDiagramCanvas, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
								kLHintsCenterY | kLHintsExpandX |
								kLHintsExpandY, 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //                                              Diode Function Canvas
  //-------------------------------------------------------------------------------------------------------
  EmbeddedDiodeFunctCanvas = new TRootEmbeddedCanvas(0, VFrame12, 366, 234, kSunkenFrame);
  EmbeddedDiodeFunctCanvas -> SetName("EmbeddedDiodeFunctCanvas");
  Int_t wEmbeddedDiodeFunctCanvas = EmbeddedDiodeFunctCanvas -> GetCanvasWindowId();
  CanvasDiodeFunct = new TCanvas("CanvasDiodeFunct", 10, 10, wEmbeddedDiodeFunctCanvas);
  CanvasDiodeFunct -> ToggleEditor();
  CanvasDiodeFunct -> SetGrid();
  CanvasDiodeFunct -> SetFillColor(kWhite);
  //-------------------------------------------------------------------------------------------------------
  DiodeFunct = new TF1("DiodeFunction", "[1]*x + 0.5*([0]-[1])*(TMath::Abs(x+[2]) - TMath::Abs(x-[2]))",
		       -2., 2.);
  DiodeFunct -> SetTitle("Diode Function; V1(V); I(A)");
  DiodeFunct -> SetParameters(NumEntGa -> GetNumber(), NumEntGb -> GetNumber(), NumEntE -> GetNumber());
  DiodeFunct -> GetXaxis() -> SetLabelSize(0.05);
  DiodeFunct -> GetYaxis() -> SetLabelSize(0.05);

  DiodeFunct -> Draw();
  //-------------------------------------------------------------------------------------------------------
  EmbeddedDiodeFunctCanvas -> AdoptCanvas(CanvasDiodeFunct);
  VFrame12 -> AddFrame(EmbeddedDiodeFunctCanvas, new TGLayoutHints(kLHintsLeft | kLHintsCenterX |
								   kLHintsTop | kLHintsCenterY |
								   kLHintsExpandX | kLHintsExpandY
								   , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  HFrame1 -> AddFrame(VFrame12, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						  kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						  , 2, 2, 2, 2));
  //=======================================================================================================
  //                                           Vertical Frame I, III
  //=======================================================================================================
  VFrame13 = new TGVerticalFrame(HFrame1, 371, 400, kVerticalFrame);
  VFrame13 -> SetName("VFrame13");
  //=======================================================================================================
  //                                           Tabs I - III
  //=======================================================================================================
  Tabs = new TGTab(VFrame13, 367, 396);
  //-------------------------------------------------------------------------------------------------------
  //                                        Container Tab1
  //-------------------------------------------------------------------------------------------------------
  CompFrame1311 = Tabs -> AddTab("Attractor");
  CompFrame1311 -> SetLayoutManager(new TGVerticalLayout(CompFrame1311));
  // embedded canvas
  EmbeddedAttractorCanvas = new TRootEmbeddedCanvas(0, CompFrame1311, 359, 407, kSunkenFrame);
  Int_t wEmbeddedAttractorCanvas = EmbeddedAttractorCanvas -> GetCanvasWindowId();
  CanvasAttractor = new TCanvas("CanvasAttractor", 10, 10, wEmbeddedAttractorCanvas);
  CanvasAttractor -> ToggleEditor();
  CanvasAttractor -> SetFillColor(kWhite);
  CanvasAttractor -> SetGrid();
  
  EmbeddedAttractorCanvas -> AdoptCanvas(CanvasAttractor);
  CompFrame1311 -> AddFrame(EmbeddedAttractorCanvas, new TGLayoutHints(kLHintsLeft | kLHintsCenterX |
								       kLHintsTop | kLHintsCenterY |
								       kLHintsExpandX | kLHintsExpandY
								       , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //                                        Container Tab2
  //-------------------------------------------------------------------------------------------------------
  CompFrame1312 = Tabs -> AddTab("V1 Vs. T");
  CompFrame1312 -> SetLayoutManager(new TGVerticalLayout(CompFrame1312));
  // embedded canvas
  EmbeddedV1TCanvas = new TRootEmbeddedCanvas(0, CompFrame1312, 359, 407, kSunkenFrame);
  Int_t wEmbeddedV1TCanvas = EmbeddedV1TCanvas -> GetCanvasWindowId();
  CanvasV1T = new TCanvas("CanvasV1T", 10, 10, wEmbeddedV1TCanvas);
  CanvasV1T -> ToggleEditor();
  CanvasV1T -> SetFillColor(kWhite);
  CanvasV1T -> SetGrid();
  
  EmbeddedV1TCanvas -> AdoptCanvas(CanvasV1T);
  CompFrame1312 -> AddFrame(EmbeddedV1TCanvas, new TGLayoutHints(kLHintsLeft | kLHintsCenterX |
								 kLHintsTop | kLHintsCenterY |
								 kLHintsExpandX | kLHintsExpandY
								 , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //                                        Container Tab3
  //-------------------------------------------------------------------------------------------------------
  CompFrame1313 = Tabs -> AddTab("V2 Vs. T");
  CompFrame1313 -> SetLayoutManager(new TGVerticalLayout(CompFrame1313));
  // embedded canvas
  EmbeddedV2TCanvas = new TRootEmbeddedCanvas(0, CompFrame1313, 359, 407, kSunkenFrame);
  Int_t wEmbeddedV2TCanvas = EmbeddedV2TCanvas -> GetCanvasWindowId();
  CanvasV2T = new TCanvas("CanvasV2T", 10, 10, wEmbeddedV2TCanvas);
  CanvasV2T -> ToggleEditor();
  CanvasV2T -> SetFillColor(kWhite);
  CanvasV2T -> SetGrid();
  
  EmbeddedV2TCanvas -> AdoptCanvas(CanvasV2T);
  CompFrame1313 -> AddFrame(EmbeddedV2TCanvas, new TGLayoutHints(kLHintsLeft | kLHintsCenterX |
								 kLHintsTop | kLHintsCenterY |
								 kLHintsExpandX | kLHintsExpandY
								 , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //                                        Container Tab4
  //-------------------------------------------------------------------------------------------------------
  CompFrame1314 = Tabs -> AddTab("I3 Vs. T");
  CompFrame1314 -> SetLayoutManager(new TGVerticalLayout(CompFrame1314));
  // embedded canvas
  EmbeddedI3TCanvas = new TRootEmbeddedCanvas(0, CompFrame1314, 359, 407, kSunkenFrame);
  Int_t wEmbeddedI3TCanvas = EmbeddedI3TCanvas -> GetCanvasWindowId();
  CanvasI3T = new TCanvas("CanvasI3T", 10, 10, wEmbeddedI3TCanvas);
  CanvasI3T -> ToggleEditor();
  CanvasI3T -> SetFillColor(kWhite);
  CanvasI3T -> SetGrid();
  
  EmbeddedI3TCanvas -> AdoptCanvas(CanvasI3T);
  CompFrame1314 -> AddFrame(EmbeddedI3TCanvas, new TGLayoutHints(kLHintsLeft | kLHintsCenterX |
								 kLHintsTop | kLHintsCenterY |
								 kLHintsExpandX | kLHintsExpandY
								 , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //                                        Container Tab5
  //-------------------------------------------------------------------------------------------------------
  CompFrame1315 = Tabs -> AddTab("Lyapunov");
  CompFrame1315 -> SetLayoutManager(new TGVerticalLayout(CompFrame1315));
  // embedded canvas
  EmbeddedLyapuCanvas = new TRootEmbeddedCanvas(0, CompFrame1315, 359, 4007, kSunkenFrame);
  Int_t wEmbeddedLyapuCanvas = EmbeddedLyapuCanvas -> GetCanvasWindowId();
  CanvasLyapu = new TCanvas("CanvasLyapu", 10, 10, wEmbeddedLyapuCanvas);
  CanvasLyapu -> ToggleEditor();
  CanvasLyapu -> SetFillColor(kWhite);
  CanvasLyapu -> SetGrid();
  
  EmbeddedLyapuCanvas -> AdoptCanvas(CanvasLyapu);
  CompFrame1315 -> AddFrame(EmbeddedLyapuCanvas, new TGLayoutHints(kLHintsLeft | kLHintsCenterX |
								   kLHintsTop | kLHintsCenterY |
								   kLHintsExpandX | kLHintsExpandY
								   , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  Tabs -> SetTab(0);
  Tabs -> Resize(Tabs -> GetDefaultSize());
  VFrame13 -> AddFrame(Tabs, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | kLHintsCenterY |
					       kLHintsExpandX | kLHintsExpandY, 2, 2, 2, 2));
  //=======================================================================================================
  HFrame1 -> AddFrame(VFrame13, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						  kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						  , 2, 2, 2, 2));
  //=======================================================================================================
  MainFrame -> AddFrame(HFrame1, new TGLayoutHints(kLHintsCenterX | kLHintsCenterY | kLHintsExpandX |
						   kLHintsExpandY, 1, 1, 1, 1));
  
  MainFrame -> SetMWMHints(kMWMDecorAll, kMWMFuncAll, kMWMInputModeless);
  MainFrame -> MapSubwindows();
  MainFrame -> Resize(MainFrame -> GetDefaultSize());
  MainFrame -> Resize(1125, 498);
  MainFrame -> MapWindow();
  MainFrame -> Resize(1125, 499);
  //=======================================================================================================
  Cont = new TTimer(100);
  Cont -> Connect("Timeout()", "WMainCHUA", this, "DoDraw()");
  IsActive = -1;
}

void WMainCHUA::Disable(){
  //-------------------------------------------------------------------------------------------------------
  // Disable object modification
  //-------------------------------------------------------------------------------------------------------
  TextButtonCalculate -> SetEnabled(kFALSE);
  NumEntRes1          -> SetState(kFALSE);
  NumEntRes2          -> SetState(kFALSE);
  NumEntCap1          -> SetState(kFALSE);
  NumEntCap2          -> SetState(kFALSE);
  NumEntInduc         -> SetState(kFALSE); 
  NumEntGa            -> SetState(kFALSE);
  NumEntGb            -> SetState(kFALSE);
  NumEntE             -> SetState(kFALSE);
  NumEntV1            -> SetState(kFALSE);
  NumEntV2            -> SetState(kFALSE);
  NumEntI3            -> SetState(kFALSE);
  
}

void WMainCHUA::Enable(){
  //-------------------------------------------------------------------------------------------------------
  // Enable modification of objects
  //-------------------------------------------------------------------------------------------------------
  TextButtonCalculate -> SetEnabled(kTRUE);
  NumEntRes1          -> SetState(kTRUE);
  NumEntRes2          -> SetState(kTRUE);
  NumEntCap1          -> SetState(kTRUE);
  NumEntCap2          -> SetState(kTRUE);
  NumEntInduc         -> SetState(kTRUE); 
  NumEntGa            -> SetState(kTRUE);
  NumEntGb            -> SetState(kTRUE);
  NumEntE             -> SetState(kTRUE);
  NumEntV1            -> SetState(kTRUE);
  NumEntV2            -> SetState(kTRUE);
  NumEntI3            -> SetState(kTRUE);
  
}

void WMainCHUA::DrawDiodeFunct(){
  CanvasDiodeFunct -> cd();
  if(TMath::Abs(NumEntE -> GetNumber()) > 0.){
    DiodeFunct -> SetRange(-2.*TMath::Abs(NumEntE -> GetNumber()), 2.*TMath::Abs(NumEntE -> GetNumber()));
  }
  DiodeFunct -> SetParameters(NumEntGa -> GetNumber(), NumEntGb -> GetNumber(), NumEntE -> GetNumber());
  DiodeFunct -> GetXaxis() -> SetLabelSize(0.05);
  DiodeFunct -> GetYaxis() -> SetLabelSize(0.05);

  DiodeFunct -> Draw();
  
  CanvasDiodeFunct -> Modified();
  CanvasDiodeFunct -> Update();
}

void WMainCHUA::TBCalculateSimulCliked(){
  //t0 = clock();
  CanvasDiodeFunct -> cd();
  TText * text = new TText(0.0, 0.0, "Estimating...");
  text -> SetTextAlign(22);
  text -> SetTextSize(0.07);
  text -> Draw();
  CanvasDiodeFunct -> Update();
  
  outfile.open("/tmp/Chua.m");
  
  Ga = NumEntGa -> GetNumber();
  Gb = NumEntGb -> GetNumber();
  E  = NumEntE -> GetNumber();
  
  //=======================================================================================================
  // OCTAVE SCRIPT 
  //=======================================================================================================
  outfile << "## Solve Diferencial Equation"<< endl;
  //outfile << "tic;" << endl;
  outfile << "x = 0.;" << endl;
  outfile << "t = 0.;" << endl;
  outfile << "function xdot = f(x,t)" << endl;
  outfile << "    xdot(1) = (1./" << setprecision(15) << GetC_1() << ")*(((x(2)-x(1))/("
	  << setprecision(15) << GetR() << ")) - (" << setprecision(15) << Gb << "*x(1) + 0.5*("
	  << setprecision(15) << Ga - Gb << ")*(abs(x(1) + " << setprecision(15) << E << ") - abs(x(1) - "
	  << setprecision(15) << E << "))));" << endl;
  outfile << "    xdot(2) = (1./" << setprecision(15) << GetC_2() << ")*(((x(1)-x(2))/("
	  << setprecision(15) << GetR() << ")) + x(3));"<< endl;
  outfile << "    xdot(3) = -(1./" << setprecision(15) << GetL() << ")*(x(2) - "
	  << setprecision(15) << GetR_0() << "*x(3));"<< endl; 
  outfile << "endfunction"<< endl;
  outfile << "x = lsode('f', [" << setprecision(15) << GetV1() << ";" << setprecision(15) << GetV2() << ";"
	  << setprecision(15) << GetI3() << "], (t = linspace(0, 10000, 1000000)'));"<< endl;
  outfile << "M = [t, x];"<< endl;
  outfile << "dlmwrite('/tmp/chua.dat',M,'\t');"<< endl;
  //outfile << "toc;" << endl;
  outfile.close();
  //-------------------------------------------------------------------------------------------------------
  // Running GNU Octave
  //-------------------------------------------------------------------------------------------------------
  system("octave -q /tmp/Chua.m");
  
  delete text;
  CanvasDiodeFunct -> Update();
  
  infile.open("/tmp/chua.dat");
  
  //t1 = clock();
  //double time_med = (double(t1-t0)/CLOCKS_PER_SEC);
  //cout << "execution time: " << time_med << endl;
}

void WMainCHUA::TBPlayCliked(){
  //-------------------------------------------------------------------------------------------------------
  // If the process has not started
  //-------------------------------------------------------------------------------------------------------
  if(IsActive == -1){
    TextButtonPlay -> SetText("&Pause");
    Cont -> TurnOn();
    Disable();
    IsActive = 0;
  }
  //-------------------------------------------------------------------------------------------------------
  // If the simulation is paused
  //-------------------------------------------------------------------------------------------------------
  else if(IsActive == 0){
    TextButtonPlay -> SetText("&Continue");
    TextButtonClear -> SetEnabled(kTRUE);
    Cont -> TurnOff();
    
    IsActive = 1;
  }
  //-------------------------------------------------------------------------------------------------------
  // If the simulation continues
  //-------------------------------------------------------------------------------------------------------
  else if(IsActive == 1){
    TextButtonPlay -> SetText("&Pause");
    TextButtonClear -> SetEnabled(kFALSE);
    Cont -> TurnOn();
    
    IsActive = 0;
  }
}

void WMainCHUA::TBClearCliked(){
  Enable();
  n = 0;
  
  SeigenvalV1 = 0.;
  SeigenvalV2 = 0.;
  SeigenvalI3 = 0.;
  
  for(i = 0; i <= 490; i ++){
    Time_Matrix[i] = 0.;
    V1_Matrix[i]   = 0.; 
    V2_Matrix[i]   = 0.;
    I3_Matrix[i]   = 0.;
    
    LV1[i] = 0.;
    LV2[i] = 0.;
    LI3[i] = 0.;
  }
  i = 0;
  
  infile.close();
  IsActive = -1;
}
void WMainCHUA::DoDraw(){
  for(k = 0; k <= 20; k ++){
    n ++;
    
    infile >> Time;
    infile >> V1;
    infile >> V2;
    infile >> I3;
    
    //======================================================================================================
    // JACOBIAN MATRIX
    //======================================================================================================
    TMatrixD J(3, 3);
    
    if(TMath::Abs(V1) >= NumEntE -> GetNumber())
      J(0,0) = -1./(GetC_1()*GetR()) - (NumEntGb -> GetNumber()/GetC_1());
    else
      J(0,0) = -1./(GetC_1()*GetR()) - (NumEntGa -> GetNumber()/GetC_1());
        
    J(0,1) = 1./(GetC_1()*GetR());
    J(0,2) = 0.;
    J(1,0) = 1./(GetC_2()*GetR());
    J(1,1) = -1./(GetC_2()*GetR());
    J(1,2) = 1./GetC_2();
    J(2,0) = 0.;
    J(2,1) = -1./GetL();
    J(2,2) = GetR_0()/GetL();

    //------------------------------------------------------------------------------------------------------
    // CALCULATION OF OWN VALUES
    //------------------------------------------------------------------------------------------------------

    TMatrixDEigen me(J);
    TVectorD eigenval = me.GetEigenValuesRe();
    
    SeigenvalV1 += eigenval(0);
    SeigenvalV2 += eigenval(1);
    SeigenvalI3 += eigenval(2);

    //------------------------------------------------------------------------------------------------------
    // AVERAGE
    //------------------------------------------------------------------------------------------------------
    MeigenvalV1 = SeigenvalV1/(Double_t)n;
    MeigenvalV2 = SeigenvalV2/(Double_t)n;
    MeigenvalI3 = SeigenvalI3/(Double_t)n;

  }

  NumEntV1 -> SetNumber(V1);
  NumEntV2 -> SetNumber(V2);
  NumEntI3 -> SetNumber(I3);
  
  Time_Matrix[i%500] = Time;
  V1_Matrix[i%500]   = V1; 
  V2_Matrix[i%500]   = V2;
  I3_Matrix[i%500]   = I3;

  CanvasAttractor -> cd();
  TGraph2DAttractor = new TGraph2D(500, V1_Matrix, V2_Matrix, I3_Matrix);
  TGraph2DAttractor -> SetTitle("Attractor; V_{1}(V); V_{2}(V); I_{3}(A)");
  TGraph2DAttractor -> SetMarkerColor(2);
  TGraph2DAttractor -> SetMarkerSize(0.2);
  TGraph2DAttractor -> SetMarkerStyle(1);
  TGraph2DAttractor -> GetXaxis() -> SetLabelSize(0.05);
  TGraph2DAttractor -> GetYaxis() -> SetLabelSize(0.05);
  TGraph2DAttractor -> Draw();
  CanvasAttractor -> Modified();
  CanvasAttractor -> Update();
  delete TGraph2DAttractor;

  CanvasV1T -> cd();
  TGraphV1T = new TGraph(500, Time_Matrix, V1_Matrix);
  TGraphV1T -> SetTitle("V1 Vs. T; t(s); V_{1}(V)");
  TGraphV1T -> SetMarkerColor(3);
  TGraphV1T -> SetMarkerStyle(20);
  TGraphV1T -> SetMarkerSize(0.5);
  TGraphV1T -> GetXaxis() -> SetLabelSize(0.05);
  TGraphV1T -> GetYaxis() -> SetLabelSize(0.05);
  TGraphV1T -> Draw("AP");
  CanvasV1T -> Modified();
  CanvasV1T -> Update();
  delete TGraphV1T;

  CanvasV2T -> cd(); 
  TGraphV2T = new TGraph(500, Time_Matrix, V2_Matrix);
  TGraphV2T -> SetTitle("V2 Vs. T; t(s); V_{2}(V)");
  TGraphV2T -> SetMarkerColor(4);
  TGraphV2T -> SetMarkerStyle(20);
  TGraphV2T -> SetMarkerSize(0.5);
  TGraphV2T -> GetXaxis() -> SetLabelSize(0.05);
  TGraphV2T -> GetYaxis() -> SetLabelSize(0.05);
  TGraphV2T -> Draw("AP");
  CanvasV2T -> Modified();
  CanvasV2T -> Update();
  delete TGraphV2T;

  CanvasI3T -> cd();
  TGraphI3T = new TGraph(500, Time_Matrix, I3_Matrix);
  TGraphI3T -> SetTitle("I3 Vs. T; t(s); I_{3}(A)");
  TGraphI3T -> SetMarkerColor(6);
  TGraphI3T -> SetMarkerStyle(20);
  TGraphI3T -> SetMarkerSize(0.5);
  TGraphI3T -> GetXaxis() -> SetLabelSize(0.05);
  TGraphI3T -> GetYaxis() -> SetLabelSize(0.05);
  TGraphI3T -> Draw("AP");
  CanvasI3T -> Modified();
  CanvasI3T -> Update();
  delete TGraphI3T;

  //i ++;
  LV1[i%500] = MeigenvalV1;
  LV2[i%500] = MeigenvalV2;
  LI3[i%500] = MeigenvalI3;
  
  CanvasLyapu -> cd();
  Exponentes = new TMultiGraph();
  Exponentes -> GetXaxis() -> SetTitle("t(s)");
  Exponentes -> GetYaxis() -> SetTitle("#lambda");
  Exponentes -> GetXaxis() -> SetLabelSize(0.05);
  Exponentes -> GetYaxis() -> SetLabelSize(0.05);
    
  TGraphL1 = new TGraph(500, Time_Matrix, LV1);
  TGraphL1 -> SetTitle("#lambda_{V1}"); 
  TGraphL1 -> SetMarkerColor(4);
  TGraphL1 -> SetMarkerStyle(20);
  TGraphL1 -> SetMarkerSize(0.5);
  TGraphL1 -> GetXaxis() -> SetLabelSize(0.05);
  TGraphL1 -> GetYaxis() -> SetLabelSize(0.05);    
  
  TGraphL2 = new TGraph(500, Time_Matrix, LV2);
  TGraphL2 -> SetTitle("#lambda_{V2}");
  TGraphL2 -> SetMarkerColor(5);
  TGraphL2 -> SetMarkerStyle(20);
  TGraphL2 -> SetMarkerSize(0.5);
  TGraphL2 -> GetXaxis() -> SetLabelSize(0.05);
  TGraphL2 -> GetYaxis() -> SetLabelSize(0.05);

  TGraphL3 = new TGraph(500, Time_Matrix, LI3);
  TGraphL3 -> SetTitle("#lambda_{I3}");
  TGraphL3 -> SetMarkerColor(6);
  TGraphL3 -> SetMarkerStyle(20);
  TGraphL3 -> SetMarkerSize(0.5);
  TGraphL3 -> GetXaxis() -> SetLabelSize(0.05);
  TGraphL3 -> GetYaxis() -> SetLabelSize(0.05);

  Exponentes -> Add(TGraphL1);
  Exponentes -> Add(TGraphL2);
  Exponentes -> Add(TGraphL3);
  
  Exponentes -> Draw("ap");
  CanvasLyapu -> BuildLegend();
  CanvasLyapu -> Modified();
  CanvasLyapu -> Update();
    
  delete TGraphL1;
  delete TGraphL2;
  delete TGraphL3;
  
  i ++;
}

void WMainCHUA::TBExitCliked(){
  //-------------------------------------------------------------------------------------------------------
  // Stop the simulation and finish the application
  //-------------------------------------------------------------------------------------------------------
  Cont -> TurnOff();
  MainFrame -> CloseWindow();
}

WMainCHUA::~WMainCHUA(){
  MainFrame -> Cleanup();
  delete MainFrame;
}
