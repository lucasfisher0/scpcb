xof 0303txt 0032
template XSkinMeshHeader {
 <3cf169ce-ff7c-44ab-93c0-f78f62d172e2>
 WORD nMaxSkinWeightsPerVertex;
 WORD nMaxSkinWeightsPerFace;
 WORD nBones;
}

template VertexDuplicationIndices {
 <b8d65549-d7c9-4995-89cf-53a9a8b031e3>
 DWORD nIndices;
 DWORD nOriginalVertices;
 array DWORD indices[nIndices];
}

template SkinWeights {
 <6f0d123b-bad2-4167-a0d0-80224f25fabb>
 STRING transformNodeName;
 DWORD nWeights;
 array DWORD vertexIndices[nWeights];
 array FLOAT weights[nWeights];
 Matrix4x4 matrixOffset;
}

template AnimTicksPerSecond {
 <9e415a43-7ba6-4a73-8743-b73d47e88476>
 DWORD AnimTicksPerSecond;
}


AnimTicksPerSecond {
 24;
}

Material MatD3D01 {
 0.800000;0.800000;0.800000;1.000000;;
 50.000000;
 0.000000;0.000000;0.000000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "mechanical_lever.jpg";
 }
}

Frame Scene_Root {
 

 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
 }

 Frame Mesh01 {
  

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Mesh Mesh01 {
   122;
   -0.763060;0.173037;-0.003943;,
   -0.763060;-0.186311;1.833474;,
   -0.763060;-0.186311;-0.003943;,
   0.763060;0.173037;-0.003943;,
   0.763060;-0.186311;-0.003943;,
   0.763060;-0.186311;1.833474;,
   -0.894340;-0.265317;1.768832;,
   0.894340;-0.265317;1.768832;,
   0.894340;0.252044;1.768832;,
   -0.894340;0.252044;1.768832;,
   -0.894340;0.252044;1.768832;,
   0.894340;0.252044;1.768832;,
   0.894340;0.252044;1.953095;,
   -0.894340;0.252044;1.953095;,
   -0.615074;-0.141300;1.953095;,
   -0.894340;-0.265317;1.953095;,
   -0.502851;-0.141300;1.953095;,
   0.503026;-0.141300;1.953095;,
   0.614899;-0.141300;1.953095;,
   0.894340;-0.265317;1.953095;,
   0.894340;-0.265317;1.768832;,
   0.894340;0.252044;1.768832;,
   -0.894340;0.252044;1.768832;,
   -0.502851;0.125865;1.953095;,
   0.503026;0.125865;1.953095;,
   0.614899;0.125865;1.953095;,
   0.614899;-0.141300;1.953095;,
   0.503026;-0.141300;1.953095;,
   0.507861;-0.141300;2.187300;,
   0.503026;-0.141300;1.953095;,
   0.507861;0.125865;2.187300;,
   0.507861;-0.141300;2.187300;,
   -0.615074;0.125865;1.953095;,
   -0.502851;0.125865;1.953095;,
   -0.508445;0.125865;2.185626;,
   -0.609480;0.125865;2.234473;,
   -0.502851;0.125865;1.953095;,
   -0.508445;-0.141300;2.185626;,
   -0.508445;0.125865;2.185626;,
   -0.615074;-0.141300;1.953095;,
   -0.615074;0.125865;1.953095;,
   -0.609480;0.125865;2.234473;,
   0.507861;0.125865;2.187300;,
   0.610064;0.125865;2.232799;,
   0.357501;0.125865;2.393051;,
   0.610064;0.125865;2.232799;,
   0.610064;-0.141300;2.232799;,
   0.357501;-0.141300;2.393051;,
   -0.508445;-0.141300;2.185626;,
   -0.609480;-0.141300;2.234473;,
   -0.357677;-0.141300;2.393051;,
   -0.609480;-0.141300;2.234473;,
   -0.357677;0.125865;2.393051;,
   0.313882;-0.141300;2.303802;,
   0.313882;0.125865;2.303802;,
   -0.313707;0.125865;2.303802;,
   -0.313707;-0.141300;2.303802;,
   0.313882;0.125865;2.303802;,
   -0.313707;-0.141300;2.303802;,
   -0.894340;-0.265317;1.768832;,
   -0.718550;-0.186311;-0.003943;,
   -0.763060;-0.133189;-0.106760;,
   -0.763060;0.117754;-0.106760;,
   -0.763060;-0.133189;-0.106760;,
   -0.718550;-0.133189;-0.106760;,
   -0.718550;0.173037;1.833474;,
   -0.718550;0.173037;-0.003943;,
   -0.718550;-0.188473;1.833474;,
   -0.718550;-0.047528;-0.160835;,
   -0.763060;-0.047528;-0.160835;,
   -0.718550;0.117754;-0.106760;,
   -0.718550;-0.133189;-0.106760;,
   0.718550;0.173037;1.833474;,
   0.718550;0.173037;-0.003943;,
   0.763060;0.173037;1.833474;,
   0.718550;-0.188473;1.833474;,
   0.718550;-0.186311;-0.003943;,
   0.718550;0.173037;-0.003943;,
   -0.615074;0.125865;1.953095;,
   -0.615074;-0.141300;1.953095;,
   -0.502851;-0.141300;1.953095;,
   0.614899;0.125865;1.953095;,
   0.503026;0.125865;1.953095;,
   0.614899;0.125865;1.953095;,
   0.503026;0.125865;1.953095;,
   -0.502851;-0.141300;1.953095;,
   0.614899;-0.141300;1.953095;,
   0.610064;-0.141300;2.232799;,
   0.763060;-0.133189;-0.106760;,
   0.763060;0.117754;-0.106760;,
   0.763060;-0.133189;-0.106760;,
   0.718550;-0.133189;-0.106760;,
   -0.763060;0.173037;1.833474;,
   0.718550;0.173037;1.833474;,
   0.718550;-0.047528;-0.160835;,
   0.763060;-0.047528;-0.160835;,
   0.718550;0.117754;-0.106760;,
   0.718550;-0.133189;-0.106760;,
   -0.313707;0.125865;2.303802;,
   0.313882;-0.141300;2.303802;,
   0.718550;0.032092;-0.160835;,
   0.763060;0.032092;-0.160835;,
   0.763060;0.117754;-0.106760;,
   0.718550;0.117754;-0.106760;,
   0.763060;0.117754;-0.106760;,
   -0.718550;0.032092;-0.160835;,
   -0.763060;0.117754;-0.106760;,
   -0.763060;0.032092;-0.160835;,
   -0.718550;0.032092;-0.160835;,
   -0.718550;0.117754;-0.106760;,
   -0.718550;0.117754;-0.106760;,
   -0.763060;0.117754;-0.106760;,
   0.718550;0.117754;-0.106760;,
   0.718550;0.032092;-0.160835;,
   -0.763060;-0.047528;-0.160835;,
   -0.718550;0.173037;-0.003943;,
   0.763060;-0.047528;-0.160835;,
   -0.718550;-0.047528;-0.160835;,
   -0.763060;0.032092;-0.160835;,
   -0.718550;0.173037;1.833474;,
   0.763060;0.032092;-0.160835;,
   0.718550;-0.047528;-0.160835;;
   110;
   3;0,2,1;,
   3;3,5,4;,
   3;6,8,7;,
   3;6,9,8;,
   3;10,12,11;,
   3;10,13,12;,
   3;13,15,14;,
   3;15,16,14;,
   3;15,17,16;,
   3;15,18,17;,
   3;15,19,18;,
   3;20,21,12;,
   3;15,13,22;,
   3;16,24,23;,
   3;16,17,24;,
   3;25,19,12;,
   3;25,18,19;,
   3;26,28,27;,
   3;29,31,30;,
   3;32,34,33;,
   3;32,35,34;,
   3;36,38,37;,
   3;39,41,40;,
   3;42,44,43;,
   3;45,47,46;,
   3;45,44,47;,
   3;48,50,49;,
   3;51,52,41;,
   3;51,50,52;,
   3;53,55,54;,
   3;53,56,55;,
   3;57,52,44;,
   3;47,50,58;,
   3;13,25,12;,
   3;13,24,25;,
   3;13,23,24;,
   3;59,15,22;,
   3;60,2,61;,
   3;62,63,2;,
   3;64,60,61;,
   3;65,67,66;,
   3;68,64,69;,
   3;70,60,71;,
   3;72,74,73;,
   3;75,77,76;,
   3;60,66,67;,
   3;44,52,50;,
   3;44,50,47;,
   3;5,3,74;,
   3;78,23,13;,
   3;78,13,14;,
   3;79,80,49;,
   3;39,51,41;,
   3;81,82,43;,
   3;83,45,46;,
   3;84,29,30;,
   3;82,42,43;,
   3;85,36,37;,
   3;80,48,49;,
   3;20,12,19;,
   3;86,83,46;,
   3;26,87,28;,
   3;76,88,4;,
   3;89,4,90;,
   3;91,88,76;,
   3;92,0,1;,
   3;93,77,75;,
   3;94,95,91;,
   3;96,97,76;,
   3;34,35,98;,
   3;38,55,56;,
   3;28,87,99;,
   3;31,53,54;,
   3;37,38,56;,
   3;48,58,50;,
   3;30,31,54;,
   3;42,57,44;,
   3;98,35,52;,
   3;98,52,57;,
   3;99,87,47;,
   3;99,47,58;,
   3;3,4,89;,
   3;100,102,101;,
   3;96,76,77;,
   3;103,3,104;,
   3;70,71,105;,
   3;106,108,107;,
   3;109,108,106;,
   3;0,62,2;,
   3;110,111,0;,
   3;70,66,60;,
   3;112,102,100;,
   3;96,113,97;,
   3;69,64,61;,
   3;114,63,62;,
   3;73,74,3;,
   3;73,3,103;,
   3;115,110,0;,
   3;115,0,92;,
   3;88,91,95;,
   3;90,116,89;,
   3;105,71,117;,
   3;108,68,107;,
   3;114,62,118;,
   3;69,107,68;,
   3;119,115,92;,
   3;95,94,101;,
   3;116,120,89;,
   3;100,101,94;,
   3;113,121,97;;

   MeshNormals {
    122;
    -0.716666;0.659694;-0.226260;,
    -1.000000;0.000000;0.000000;,
    -0.948683;-0.280945;-0.145154;,
    0.716666;0.659694;-0.226260;,
    0.948683;-0.280945;-0.145154;,
    1.000000;0.000000;0.000000;,
    -0.447214;0.000000;-0.894427;,
    0.894427;0.000000;-0.447214;,
    0.408248;0.408248;-0.816497;,
    -0.666667;0.666667;-0.333333;,
    -0.666667;0.666667;-0.333333;,
    0.408248;0.408248;-0.816497;,
    0.577350;0.577350;0.577350;,
    -0.162221;0.162221;0.973329;,
    -0.529922;-0.265013;0.805575;,
    -0.371391;0.000001;0.928477;,
    0.217162;-0.434450;0.874125;,
    -0.529743;-0.264928;0.805720;,
    0.266237;-0.532553;0.803433;,
    0.316228;0.000000;0.948683;,
    0.894427;0.000000;-0.447214;,
    0.408248;0.408248;-0.816497;,
    -0.666667;0.666667;-0.333333;,
    0.528944;0.264548;0.806370;,
    -0.217319;0.434730;0.873946;,
    0.433525;0.216795;0.874675;,
    0.266237;-0.532553;0.803433;,
    -0.529743;-0.264928;0.805720;,
    -0.507567;-0.750275;-0.423630;,
    -0.529743;-0.264928;0.805720;,
    -0.628841;0.750275;-0.204072;,
    -0.507567;-0.750275;-0.423630;,
    -0.331805;0.663741;0.670338;,
    0.528944;0.264548;0.806370;,
    0.509446;0.750180;-0.421539;,
    -0.629236;0.745392;0.220122;,
    0.528944;0.264548;0.806370;,
    0.629705;-0.750180;-0.201748;,
    0.509446;0.750180;-0.421539;,
    -0.529922;-0.265013;0.805575;,
    -0.331805;0.663741;0.670338;,
    -0.629236;0.745392;0.220122;,
    -0.628841;0.750275;-0.204072;,
    0.514617;0.745331;0.423852;,
    0.128521;0.719661;0.682328;,
    0.514617;0.745331;0.423852;,
    0.629919;-0.745331;0.218367;,
    0.257042;-0.719661;0.644995;,
    0.629705;-0.750180;-0.201748;,
    -0.513227;-0.745392;0.425429;,
    -0.127809;-0.719511;0.682619;,
    -0.513227;-0.745392;0.425429;,
    -0.255617;0.719511;0.645727;,
    -0.123327;-0.718595;-0.684406;,
    -0.246654;0.718595;-0.650218;,
    0.124301;0.718790;-0.684025;,
    0.248602;-0.718790;-0.649259;,
    -0.246654;0.718595;-0.650218;,
    0.248602;-0.718790;-0.649259;,
    -0.447214;0.000000;-0.894427;,
    0.832050;-0.492811;-0.254617;,
    -0.566830;-0.654875;-0.499842;,
    -0.808412;0.393769;-0.437511;,
    -0.566830;-0.654875;-0.499842;,
    0.718172;-0.468257;-0.514746;,
    0.707107;0.707107;0.000000;,
    0.716666;0.688180;-0.113130;,
    1.000000;0.000000;0.000000;,
    0.326469;-0.174271;-0.929004;,
    -0.568365;-0.303396;-0.764796;,
    0.717498;0.548961;-0.428764;,
    0.718172;-0.468257;-0.514746;,
    -0.707107;0.707107;0.000000;,
    -0.716666;0.688180;-0.113130;,
    0.447214;0.894427;0.000000;,
    -1.000000;0.000000;0.000000;,
    -0.832050;-0.492811;-0.254617;,
    -0.716666;0.688180;-0.113130;,
    -0.331805;0.663741;0.670338;,
    -0.529922;-0.265013;0.805575;,
    0.217162;-0.434450;0.874125;,
    0.433525;0.216795;0.874675;,
    -0.217319;0.434730;0.873946;,
    0.433525;0.216795;0.874675;,
    -0.217319;0.434730;0.873946;,
    0.217162;-0.434450;0.874125;,
    0.266237;-0.532553;0.803433;,
    0.629919;-0.745331;0.218367;,
    0.566830;-0.654875;-0.499842;,
    0.808412;0.393769;-0.437511;,
    0.566830;-0.654875;-0.499842;,
    -0.718172;-0.468257;-0.514746;,
    -0.447214;0.894427;0.000000;,
    -0.707107;0.707107;0.000000;,
    -0.326469;-0.174271;-0.929004;,
    0.568365;-0.303396;-0.764796;,
    -0.717498;0.548961;-0.428764;,
    -0.718172;-0.468257;-0.514746;,
    0.124301;0.718790;-0.684025;,
    -0.123327;-0.718595;-0.684406;,
    -0.568364;0.303393;-0.764797;,
    0.326469;0.174269;-0.929004;,
    0.808412;0.393769;-0.437511;,
    -0.717498;0.548961;-0.428764;,
    0.808412;0.393769;-0.437511;,
    0.568364;0.303393;-0.764797;,
    -0.808412;0.393769;-0.437511;,
    -0.326469;0.174269;-0.929004;,
    0.568364;0.303393;-0.764797;,
    0.717498;0.548961;-0.428764;,
    0.717498;0.548961;-0.428764;,
    -0.808412;0.393769;-0.437511;,
    -0.717498;0.548961;-0.428764;,
    -0.568364;0.303393;-0.764797;,
    -0.568365;-0.303396;-0.764796;,
    0.716666;0.688180;-0.113130;,
    0.568365;-0.303396;-0.764796;,
    0.326469;-0.174271;-0.929004;,
    -0.326469;0.174269;-0.929004;,
    0.707107;0.707107;0.000000;,
    0.326469;0.174269;-0.929004;,
    -0.326469;-0.174271;-0.929004;;
    110;
    3;0,2,1;,
    3;3,5,4;,
    3;6,8,7;,
    3;6,9,8;,
    3;10,12,11;,
    3;10,13,12;,
    3;13,15,14;,
    3;15,16,14;,
    3;15,17,16;,
    3;15,18,17;,
    3;15,19,18;,
    3;20,21,12;,
    3;15,13,22;,
    3;16,24,23;,
    3;16,17,24;,
    3;25,19,12;,
    3;25,18,19;,
    3;26,28,27;,
    3;29,31,30;,
    3;32,34,33;,
    3;32,35,34;,
    3;36,38,37;,
    3;39,41,40;,
    3;42,44,43;,
    3;45,47,46;,
    3;45,44,47;,
    3;48,50,49;,
    3;51,52,41;,
    3;51,50,52;,
    3;53,55,54;,
    3;53,56,55;,
    3;57,52,44;,
    3;47,50,58;,
    3;13,25,12;,
    3;13,24,25;,
    3;13,23,24;,
    3;59,15,22;,
    3;60,2,61;,
    3;62,63,2;,
    3;64,60,61;,
    3;65,67,66;,
    3;68,64,69;,
    3;70,60,71;,
    3;72,74,73;,
    3;75,77,76;,
    3;60,66,67;,
    3;44,52,50;,
    3;44,50,47;,
    3;5,3,74;,
    3;78,23,13;,
    3;78,13,14;,
    3;79,80,49;,
    3;39,51,41;,
    3;81,82,43;,
    3;83,45,46;,
    3;84,29,30;,
    3;82,42,43;,
    3;85,36,37;,
    3;80,48,49;,
    3;20,12,19;,
    3;86,83,46;,
    3;26,87,28;,
    3;76,88,4;,
    3;89,4,90;,
    3;91,88,76;,
    3;92,0,1;,
    3;93,77,75;,
    3;94,95,91;,
    3;96,97,76;,
    3;34,35,98;,
    3;38,55,56;,
    3;28,87,99;,
    3;31,53,54;,
    3;37,38,56;,
    3;48,58,50;,
    3;30,31,54;,
    3;42,57,44;,
    3;98,35,52;,
    3;98,52,57;,
    3;99,87,47;,
    3;99,47,58;,
    3;3,4,89;,
    3;100,102,101;,
    3;96,76,77;,
    3;103,3,104;,
    3;70,71,105;,
    3;106,108,107;,
    3;109,108,106;,
    3;0,62,2;,
    3;110,111,0;,
    3;70,66,60;,
    3;112,102,100;,
    3;96,113,97;,
    3;69,64,61;,
    3;114,63,62;,
    3;73,74,3;,
    3;73,3,103;,
    3;115,110,0;,
    3;115,0,92;,
    3;88,91,95;,
    3;90,116,89;,
    3;105,71,117;,
    3;108,68,107;,
    3;114,62,118;,
    3;69,107,68;,
    3;119,115,92;,
    3;95,94,101;,
    3;116,120,89;,
    3;100,101,94;,
    3;113,121,97;;
   }

   MeshTextureCoords {
    122;
    0.776846;0.518974;,
    0.877310;0.008356;,
    0.877310;0.518974;,
    0.776846;0.518974;,
    0.877310;0.518974;,
    0.877310;0.008356;,
    0.261893;0.150684;,
    0.040205;0.150684;,
    0.040205;0.215073;,
    0.261893;0.215073;,
    0.261893;0.040620;,
    0.040205;0.040620;,
    0.040205;0.063457;,
    0.261893;0.063457;,
    0.227281;0.112208;,
    0.261893;0.127846;,
    0.213372;0.112208;,
    0.088704;0.112208;,
    0.074838;0.112208;,
    0.040205;0.127846;,
    0.017367;0.127846;,
    0.017367;0.063457;,
    0.284730;0.063457;,
    0.213372;0.079096;,
    0.088704;0.079096;,
    0.074838;0.079096;,
    0.239301;0.224761;,
    0.222630;0.224761;,
    0.223350;0.259662;,
    0.022338;0.419668;,
    0.063929;0.467112;,
    0.063929;0.419668;,
    0.056008;0.395700;,
    0.072732;0.395700;,
    0.071898;0.361048;,
    0.056841;0.353769;,
    0.273066;0.467113;,
    0.231773;0.419669;,
    0.231772;0.467113;,
    0.020538;0.290047;,
    0.020800;0.329859;,
    0.058120;0.329972;,
    0.223350;0.360799;,
    0.238581;0.354018;,
    0.200943;0.330137;,
    0.239394;0.330137;,
    0.239394;0.290324;,
    0.200943;0.290324;,
    0.071898;0.259413;,
    0.056841;0.266692;,
    0.094366;0.290324;,
    0.058217;0.290159;,
    0.094366;0.330137;,
    0.093029;0.419668;,
    0.093029;0.467112;,
    0.204478;0.467113;,
    0.204479;0.419669;,
    0.194443;0.343437;,
    0.100918;0.277024;,
    0.284730;0.127846;,
    0.889679;0.518974;,
    0.877310;0.547547;,
    0.792209;0.547547;,
    0.861946;0.547547;,
    0.889679;0.547547;,
    0.990142;0.008356;,
    0.990142;0.518974;,
    0.889679;0.008356;,
    0.889678;0.571353;,
    0.877309;0.571352;,
    0.974779;0.547547;,
    0.905042;0.547547;,
    0.764477;0.008356;,
    0.764477;0.518974;,
    0.776846;0.008356;,
    0.889679;0.008356;,
    0.889679;0.518974;,
    0.990142;0.518974;,
    0.227281;0.079096;,
    0.056008;0.224760;,
    0.072731;0.224761;,
    0.239301;0.395700;,
    0.222630;0.395700;,
    0.281076;0.330137;,
    0.022338;0.467112;,
    0.273067;0.419669;,
    0.281076;0.290323;,
    0.238581;0.266443;,
    0.877310;0.547547;,
    0.792209;0.547547;,
    0.861946;0.547547;,
    0.889679;0.547547;,
    0.776846;0.008356;,
    0.990142;0.008356;,
    0.889678;0.571353;,
    0.877309;0.571352;,
    0.974779;0.547547;,
    0.905042;0.547547;,
    0.100918;0.343437;,
    0.194443;0.277024;,
    0.889678;0.593479;,
    0.877308;0.593479;,
    0.877308;0.617284;,
    0.764477;0.547547;,
    0.776846;0.547547;,
    0.950974;0.562575;,
    0.877308;0.617284;,
    0.877308;0.593479;,
    0.889678;0.593479;,
    0.889677;0.617284;,
    0.764477;0.547547;,
    0.776846;0.547547;,
    0.889677;0.617284;,
    0.950974;0.562575;,
    0.838141;0.562575;,
    0.764477;0.518974;,
    0.838141;0.562575;,
    0.928847;0.562575;,
    0.816014;0.562575;,
    0.764477;0.008356;,
    0.816014;0.562575;,
    0.928847;0.562575;;
   }

   VertexDuplicationIndices {
    122;
    122;
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    14,
    15,
    16,
    17,
    18,
    19,
    20,
    21,
    22,
    23,
    24,
    25,
    26,
    27,
    28,
    29,
    30,
    31,
    32,
    33,
    34,
    35,
    36,
    37,
    38,
    39,
    40,
    41,
    42,
    43,
    44,
    45,
    46,
    47,
    48,
    49,
    50,
    51,
    52,
    53,
    54,
    55,
    56,
    57,
    58,
    59,
    60,
    61,
    62,
    63,
    64,
    65,
    66,
    67,
    68,
    69,
    70,
    71,
    72,
    73,
    74,
    75,
    76,
    77,
    78,
    79,
    80,
    81,
    82,
    83,
    84,
    85,
    86,
    87,
    88,
    89,
    90,
    91,
    92,
    93,
    94,
    95,
    96,
    97,
    98,
    99,
    100,
    101,
    102,
    103,
    104,
    105,
    106,
    107,
    108,
    109,
    110,
    111,
    112,
    113,
    114,
    115,
    116,
    117,
    118,
    119,
    120,
    121;
   }

   MeshMaterialList {
    1;
    110;
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0;
    { MatD3D01 }
   }

   XSkinMeshHeader {
    1;
    1;
    1;
   }

   SkinWeights {
    "Mesh01";
    122;
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    14,
    15,
    16,
    17,
    18,
    19,
    20,
    21,
    22,
    23,
    24,
    25,
    26,
    27,
    28,
    29,
    30,
    31,
    32,
    33,
    34,
    35,
    36,
    37,
    38,
    39,
    40,
    41,
    42,
    43,
    44,
    45,
    46,
    47,
    48,
    49,
    50,
    51,
    52,
    53,
    54,
    55,
    56,
    57,
    58,
    59,
    60,
    61,
    62,
    63,
    64,
    65,
    66,
    67,
    68,
    69,
    70,
    71,
    72,
    73,
    74,
    75,
    76,
    77,
    78,
    79,
    80,
    81,
    82,
    83,
    84,
    85,
    86,
    87,
    88,
    89,
    90,
    91,
    92,
    93,
    94,
    95,
    96,
    97,
    98,
    99,
    100,
    101,
    102,
    103,
    104,
    105,
    106,
    107,
    108,
    109,
    110,
    111,
    112,
    113,
    114,
    115,
    116,
    117,
    118,
    119,
    120,
    121;
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000;
    1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
   }
  }
 }

 Frame Duplicate01 {
  

  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Mesh Duplicate01 {
   20;
   0.894340;-0.265317;1.953095;,
   0.894340;-0.265317;1.768832;,
   -0.894340;-0.265317;1.768832;,
   -0.894340;-0.265317;1.953095;,
   0.614899;-0.136976;1.953095;,
   0.503026;-0.136976;1.953095;,
   -0.502851;-0.136976;1.953095;,
   0.763060;-0.186311;1.833474;,
   0.718550;-0.186311;-0.003943;,
   0.718550;-0.184148;1.833474;,
   -0.615074;-0.136976;1.953095;,
   0.763060;-0.186311;-0.003943;,
   0.763060;-0.128865;-0.106760;,
   0.718550;-0.128865;-0.106760;,
   -0.763060;-0.128865;-0.106760;,
   -0.763060;-0.186311;-0.003943;,
   -0.718550;-0.128865;-0.106760;,
   -0.718550;-0.186311;-0.003943;,
   -0.763060;-0.186311;1.833474;,
   -0.718550;-0.184148;1.833474;;
   14;
   3;0,2,1;,
   3;3,2,0;,
   3;4,3,0;,
   3;5,3,4;,
   3;6,3,5;,
   3;7,9,8;,
   3;6,10,3;,
   3;11,13,12;,
   3;14,16,15;,
   3;7,8,11;,
   3;11,8,13;,
   3;16,17,15;,
   3;15,17,18;,
   3;17,19,18;;

   MeshNormals {
    20;
    0.000000;-0.894427;0.447214;,
    0.000000;-1.000000;0.000000;,
    0.000000;-1.000000;0.000000;,
    0.000000;-0.242536;0.970142;,
    0.000000;0.000000;1.000000;,
    0.000000;0.000000;1.000000;,
    0.000000;0.000000;1.000000;,
    -0.024270;-0.999705;0.000588;,
    -0.016658;-0.985811;-0.167028;,
    -0.048526;-0.998821;0.001176;,
    0.000000;0.000000;1.000000;,
    0.000000;-0.942306;-0.334752;,
    0.000000;-0.872984;-0.487750;,
    0.000000;-0.872984;-0.487750;,
    0.000000;-0.872984;-0.487750;,
    0.000000;-0.942306;-0.334752;,
    0.000000;-0.872984;-0.487750;,
    0.016658;-0.985811;-0.167028;,
    0.024270;-0.999705;0.000588;,
    0.048526;-0.998821;0.001176;;
    14;
    3;0,2,1;,
    3;3,2,0;,
    3;4,3,0;,
    3;5,3,4;,
    3;6,3,5;,
    3;7,9,8;,
    3;6,10,3;,
    3;11,13,12;,
    3;14,16,15;,
    3;7,8,11;,
    3;11,8,13;,
    3;16,17,15;,
    3;15,17,18;,
    3;17,19,18;;
   }

   MeshTextureCoords {
    20;
    0.040205;0.063457;,
    0.040205;0.040620;,
    0.261893;0.040620;,
    0.261893;0.063457;,
    0.074838;0.079096;,
    0.088704;0.079096;,
    0.213372;0.079096;,
    0.776846;0.008356;,
    0.764477;0.518974;,
    0.764477;0.008356;,
    0.227281;0.079096;,
    0.776846;0.518974;,
    0.776846;0.547547;,
    0.764477;0.547547;,
    0.776846;0.547547;,
    0.776846;0.518974;,
    0.764477;0.547547;,
    0.764477;0.518974;,
    0.776846;0.008356;,
    0.764477;0.008356;;
   }

   VertexDuplicationIndices {
    20;
    20;
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    14,
    15,
    16,
    17,
    18,
    19;
   }

   MeshMaterialList {
    1;
    14;
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0;
    { MatD3D01 }
   }

   XSkinMeshHeader {
    1;
    1;
    1;
   }

   SkinWeights {
    "Duplicate01";
    20;
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    14,
    15,
    16,
    17,
    18,
    19;
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000,
    1.000000;
    1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
   }
  }
 }
}