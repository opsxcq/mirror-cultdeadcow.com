// getmacmf.cpp - Get the manufacturer string for a MAC prefix


char *GetManufacturerString(unsigned long MacPrefix)
{
	char *ptr = "Unknown";

	switch (MacPrefix)
	{
	case 0x00000000:
	case 0x00000100:
	case 0x00000200:
	case 0x00000300:
	case 0x00000400:
	case 0x00000500:
	case 0x00000600:
	case 0x00000700:
	case 0x00000800:
	case 0x00000900:
		ptr = "	XEROX CORPORATION";
		break;
	case 0x00000A00:
		ptr = "	OMRON TATEISI ELECTRONICS CO.";
		break;
	case 0x00000B00:
		ptr = "	MATRIX CORPORATION";
		break;
	case 0x00000C00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00000D00:
		ptr = "	FIBRONICS LTD.";
		break;
	case 0x00000E00:
		ptr = "	FUJITSU LIMITED";
		break;
	case 0x00000F00:
		ptr = "	NEXT, INC.";
		break;
	case 0x00001000:
		ptr = "	SYTEK INC.";
		break;
	case 0x00001100:
		ptr = "	NORMEREL SYSTEMES";
		break;
	case 0x00001200:
		ptr = "	INFORMATION TECHNOLOGY LIMITED";
		break;
	case 0x00001300:
		ptr = "	CAMEX";
		break;
	case 0x00001400:
		ptr = "	NETRONIX";
		break;
	case 0x00001500:
		ptr = "	DATAPOINT CORPORATION";
		break;
	case 0x00001600:
		ptr = "	DU PONT PIXEL SYSTEMS     .";
		break;
	case 0x00001800:
		ptr = "	WEBSTER COMPUTER CORPORATION";
		break;
	case 0x00001900:
		ptr = "	APPLIED DYNAMICS INTERNATIONAL";
		break;
	case 0x00001A00:
		ptr = "	ADVANCED MICRO DEVICES";
		break;
	case 0x00001B00:
		ptr = "	NOVELL INC.";
		break;
	case 0x00001C00:
		ptr = "	BELL TECHNOLOGIES";
		break;
	case 0x00001D00:
		ptr = "	CABLETRON SYSTEMS, INC.";
		break;
	case 0x00001E00:
		ptr = "	TELSIST INDUSTRIA ELECTRONICA";
		break;
	case 0x00001F00:
		ptr = "	Telco Systems, Inc.";
		break;
	case 0x00002000:
		ptr = "	DATAINDUSTRIER DIAB AB";
		break;
	case 0x00002100:
		ptr = "	SUREMAN COMP. & COMMUN. CORP.";
		break;
	case 0x00002200:
		ptr = "	VISUAL TECHNOLOGY INC.";
		break;
	case 0x00002300:
		ptr = "	ABB INDUSTRIAL SYSTEMS AB";
		break;
	case 0x00002400:
		ptr = "	CONNECT AS";
		break;
	case 0x00002500:
		ptr = "	RAMTEK CORP.";
		break;
	case 0x00002600:
		ptr = "	SHA-KEN CO., LTD.";
		break;
	case 0x00002700:
		ptr = "	JAPAN RADIO COMPANY";
		break;
	case 0x00002800:
		ptr = "	PRODIGY SYSTEMS CORPORATION";
		break;
	case 0x00002900:
		ptr = "	IMC NETWORKS CORP.";
		break;
	case 0x00002A00:
		ptr = "	TRW - SEDD/INP";
		break;
	case 0x00002B00:
		ptr = "	CRISP AUTOMATION, INC";
		break;
	case 0x00002C00:
		ptr = "	AUTOTOTE LIMITED";
		break;
	case 0x00002D00:
		ptr = "	CHROMATICS INC";
		break;
	case 0x00002E00:
		ptr = "	SOCIETE EVIRA";
		break;
	case 0x00002F00:
		ptr = "	TIMEPLEX INC.";
		break;
	case 0x00003000:
		ptr = "	VG LABORATORY SYSTEMS LTD";
		break;
	case 0x00003100:
		ptr = "	QPSX COMMUNICATIONS PTY LTD";
		break;
	case 0x00003200:
		ptr = "	Marconi plc";
		break;
	case 0x00003300:
		ptr = "	EGAN MACHINERY COMPANY";
		break;
	case 0x00003400:
		ptr = "	NETWORK RESOURCES CORPORATION";
		break;
	case 0x00003500:
		ptr = "	SPECTRAGRAPHICS CORPORATION";
		break;
	case 0x00003600:
		ptr = "	ATARI CORPORATION";
		break;
	case 0x00003700:
		ptr = "	OXFORD METRICS LIMITED";
		break;
	case 0x00003800:
		ptr = "	CSS LABS";
		break;
	case 0x00003900:
		ptr = "	TOSHIBA CORPORATION";
		break;
	case 0x00003A00:
		ptr = "	CHYRON CORPORATION";
		break;
	case 0x00003B00:
		ptr = "	i Controls, Inc.";
		break;
	case 0x00003C00:
		ptr = "	AUSPEX SYSTEMS INC.";
		break;
	case 0x00003D00:
		ptr = "	UNISYS";
		break;
	case 0x00003E00:
		ptr = "	SIMPACT";
		break;
	case 0x00003F00:
		ptr = "	SYNTREX, INC.";
		break;
	case 0x00004000:
		ptr = "	APPLICON, INC.";
		break;
	case 0x00004100:
		ptr = "	ICE CORPORATION";
		break;
	case 0x00004200:
		ptr = "	METIER MANAGEMENT SYSTEMS LTD.";
		break;
	case 0x00004300:
		ptr = "	MICRO TECHNOLOGY";
		break;
	case 0x00004400:
		ptr = "	CASTELLE CORPORATION";
		break;
	case 0x00004500:
		ptr = "	FORD AEROSPACE & COMM. CORP.";
		break;
	case 0x00004600:
		ptr = "	OLIVETTI NORTH AMERICA";
		break;
	case 0x00004700:
		ptr = "	NICOLET INSTRUMENTS CORP.";
		break;
	case 0x00004800:
		ptr = "	SEIKO EPSON CORPORATION";
		break;
	case 0x00004900:
		ptr = "	APRICOT COMPUTERS, LTD";
		break;
	case 0x00004A00:
		ptr = "	ADC CODENOLL TECHNOLOGY CORP.";
		break;
	case 0x00004B00:
		ptr = "	ICL DATA OY";
		break;
	case 0x00004C00:
		ptr = "	NEC CORPORATION";
		break;
	case 0x00004D00:
		ptr = "	DCI CORPORATION";
		break;
	case 0x00004E00:
		ptr = "	AMPEX CORPORATION";
		break;
	case 0x00004F00:
		ptr = "	LOGICRAFT, INC.";
		break;
	case 0x00005000:
		ptr = "	RADISYS CORPORATION";
		break;
	case 0x00005100:
		ptr = "	HOB ELECTRONIC GMBH & CO. KG";
		break;
	case 0x00005200:
		ptr = "	OPTICAL DATA SYSTEMS";
		break;
	case 0x00005300:
		ptr = "	COMPUCORP";
		break;
	case 0x00005400:
		ptr = "	MODICON, INC.";
		break;
	case 0x00005500:
		ptr = "	COMMISSARIAT A L`ENERGIE ATOM.";
		break;
	case 0x00005600:
		ptr = "	DR. B. STRUCK";
		break;
	case 0x00005700:
		ptr = "	SCITEX CORPORATION LTD.";
		break;
	case 0x00005800:
		ptr = "	RACORE COMPUTER PRODUCTS INC.";
		break;
	case 0x00005900:
		ptr = "	HELLIGE GMBH";
		break;
	case 0x00005A00:
		ptr = "	SYSKONNECT--A BUSINESS UNIT OF";
		break;
	case 0x00005B00:
		ptr = "	ELTEC ELEKTRONIK AG";
		break;
	case 0x00005C00:
		ptr = "	TELEMATICS INTERNATIONAL INC.";
		break;
	case 0x00005D00:
		ptr = "	CS TELECOM";
		break;
	case 0x00005E00:
		ptr = "	USC INFORMATION SCIENCES INST";
		break;
	case 0x00005F00:
		ptr = "	SUMITOMO ELECTRIC IND., LTD.";
		break;
	case 0x00006000:
		ptr = "	KONTRON ELEKTRONIK GMBH";
		break;
	case 0x00006100:
		ptr = "	GATEWAY COMMUNICATIONS";
		break;
	case 0x00006200:
		ptr = "	BULL HN INFORMATION SYSTEMS";
		break;
	case 0x00006300:
		ptr = "	DR.ING.SEUFERT GMBH";
		break;
	case 0x00006400:
		ptr = "	YOKOGAWA DIGITAL COMPUTER CORP";
		break;
	case 0x00006500:
		ptr = "	NETWORK ASSOCIATES, INC.";
		break;
	case 0x00006600:
		ptr = "	TALARIS SYSTEMS, INC.";
		break;
	case 0x00006700:
		ptr = "	SOFT * RITE, INC.";
		break;
	case 0x00006800:
		ptr = "	ROSEMOUNT CONTROLS";
		break;
	case 0x00006900:
		ptr = "	CONCORD COMMUNICATIONS INC";
		break;
	case 0x00006A00:
		ptr = "	COMPUTER CONSOLES INC.";
		break;
	case 0x00006B00:
		ptr = "	SILICON GRAPHICS INC./MIPS";
		break;
	case 0x00006D00:
		ptr = "	CRAY COMMUNICATIONS, LTD.";
		break;
	case 0x00006E00:
		ptr = "	ARTISOFT, INC.";
		break;
	case 0x00006F00:
		ptr = "	MADGE NETWORKS LTD.";
		break;
	case 0x00007000:
		ptr = "	HCL LIMITED";
		break;
	case 0x00007100:
		ptr = "	ADRA SYSTEMS INC.";
		break;
	case 0x00007200:
		ptr = "	MINIWARE TECHNOLOGY";
		break;
	case 0x00007300:
		ptr = "	SIECOR CORPORATION";
		break;
	case 0x00007400:
		ptr = "	RICOH COMPANY LTD.";
		break;
	case 0x00007500:
		ptr = "	NORTHERN TELECOM";
		break;
	case 0x00007600:
		ptr = "	ABEKAS VIDEO SYSTEM";
		break;
	case 0x00007700:
		ptr = "	INTERPHASE CORPORATION";
		break;
	case 0x00007800:
		ptr = "	LABTAM LIMITED";
		break;
	case 0x00007900:
		ptr = "	NETWORTH INCORPORATED";
		break;
	case 0x00007A00:
		ptr = "	DANA COMPUTER INC.";
		break;
	case 0x00007B00:
		ptr = "	RESEARCH MACHINES";
		break;
	case 0x00007C00:
		ptr = "	AMPERE INCORPORATED";
		break;
	case 0x00007D00:
		ptr = "	SUN MICROSYSTEMS, INC.";
		break;
	case 0x00007E00:
		ptr = "	CLUSTRIX CORPORATION";
		break;
	case 0x00007F00:
		ptr = "	LINOTYPE-HELL AG";
		break;
	case 0x00008000:
		ptr = "	CRAY COMMUNICATIONS A/S";
		break;
	case 0x00008100:
		ptr = "	BAY NETWORKS";
		break;
	case 0x00008200:
		ptr = "	LECTRA SYSTEMES SA";
		break;
	case 0x00008300:
		ptr = "	TADPOLE TECHNOLOGY PLC";
		break;
	case 0x00008400:
		ptr = "	SUPERNET";
		break;
	case 0x00008500:
		ptr = "	CANON INC.";
		break;
	case 0x00008600:
		ptr = "	MEGAHERTZ CORPORATION";
		break;
	case 0x00008700:
		ptr = "	HITACHI, LTD.";
		break;
	case 0x00008800:
		ptr = "	COMPUTER NETWORK TECH. CORP.";
		break;
	case 0x00008900:
		ptr = "	CAYMAN SYSTEMS INC.";
		break;
	case 0x00008A00:
		ptr = "	DATAHOUSE INFORMATION SYSTEMS";
		break;
	case 0x00008B00:
		ptr = "	INFOTRON";
		break;
	case 0x00008C00:
		ptr = "	ALLOY COMPUTER PRODUCTS, INC.";
		break;
	case 0x00008D00:
		ptr = "	VERDIX CORPORATION";
		break;
	case 0x00008E00:
		ptr = "	SOLBOURNE COMPUTER, INC.";
		break;
	case 0x00008F00:
		ptr = "	RAYTHEON COMPANY";
		break;
	case 0x00009000:
		ptr = "	MICROCOM";
		break;
	case 0x00009100:
		ptr = "	ANRITSU CORPORATION";
		break;
	case 0x00009200:
		ptr = "	COGENT DATA TECHNOLOGIES";
		break;
	case 0x00009300:
		ptr = "	PROTEON INC.";
		break;
	case 0x00009400:
		ptr = "	ASANTE TECHNOLOGIES";
		break;
	case 0x00009500:
		ptr = "	SONY TEKTRONIX CORP.";
		break;
	case 0x00009600:
		ptr = "	MARCONI ELECTRONICS LTD.";
		break;
	case 0x00009700:
		ptr = "	EPOCH SYSTEMS";
		break;
	case 0x00009800:
		ptr = "	CROSSCOMM CORPORATION";
		break;
	case 0x00009900:
		ptr = "	MTX, INC.";
		break;
	case 0x00009A00:
		ptr = "	RC COMPUTER A/S";
		break;
	case 0x00009B00:
		ptr = "	INFORMATION INTERNATIONAL, INC";
		break;
	case 0x00009C00:
		ptr = "	ROLM MIL-SPEC COMPUTERS";
		break;
	case 0x00009D00:
		ptr = "	LOCUS COMPUTING CORPORATION";
		break;
	case 0x00009E00:
		ptr = "	MARLI S.A.";
		break;
	case 0x00009F00:
		ptr = "	AMERISTAR TECHNOLOGIES INC.";
		break;
	case 0x0000A000:
		ptr = "	TOKYO SANYO ELECTRIC CO. LTD.";
		break;
	case 0x0000A100:
		ptr = "	MARQUETTE ELECTRIC CO.";
		break;
	case 0x0000A200:
		ptr = "	BAY NETWORKS";
		break;
	case 0x0000A300:
		ptr = "	NETWORK APPLICATION TECHNOLOGY";
		break;
	case 0x0000A400:
		ptr = "	ACORN COMPUTERS LIMITED";
		break;
	case 0x0000A500:
		ptr = "	COMPATIBLE SYSTEMS CORP.";
		break;
	case 0x0000A600:
		ptr = "	NETWORK GENERAL CORPORATION";
		break;
	case 0x0000A700:
		ptr = "	NETWORK COMPUTING DEVICES INC.";
		break;
	case 0x0000A800:
		ptr = "	STRATUS COMPUTER INC.";
		break;
	case 0x0000A900:
		ptr = "	NETWORK SYSTEMS CORP.";
		break;
	case 0x0000AA00:
		ptr = "	XEROX CORPORATION";
		break;
	case 0x0000AB00:
		ptr = "	LOGIC MODELING CORPORATION";
		break;
	case 0x0000AC00:
		ptr = "	CONWARE COMPUTER CONSULTING";
		break;
	case 0x0000AD00:
		ptr = "	BRUKER INSTRUMENTS INC.";
		break;
	case 0x0000AE00:
		ptr = "	DASSAULT ELECTRONIQUE";
		break;
	case 0x0000AF00:
		ptr = "	NUCLEAR DATA INSTRUMENTATION";
		break;
	case 0x0000B000:
		ptr = "	RND-RAD NETWORK DEVICES";
		break;
	case 0x0000B100:
		ptr = "	ALPHA MICROSYSTEMS INC.";
		break;
	case 0x0000B200:
		ptr = "	TELEVIDEO SYSTEMS, INC.";
		break;
	case 0x0000B300:
		ptr = "	CIMLINC INCORPORATED";
		break;
	case 0x0000B400:
		ptr = "	EDIMAX COMPUTER COMPANY";
		break;
	case 0x0000B500:
		ptr = "	DATABILITY SOFTWARE SYS. INC.";
		break;
	case 0x0000B600:
		ptr = "	MICRO-MATIC RESEARCH";
		break;
	case 0x0000B700:
		ptr = "	DOVE COMPUTER CORPORATION";
		break;
	case 0x0000B800:
		ptr = "	SEIKOSHA CO., LTD.";
		break;
	case 0x0000B900:
		ptr = "	MCDONNELL DOUGLAS COMPUTER SYS";
		break;
	case 0x0000BA00:
		ptr = "	SIIG, INC.";
		break;
	case 0x0000BB00:
		ptr = "	TRI-DATA";
		break;
	case 0x0000BC00:
		ptr = "	ALLEN-BRADLEY CO. INC.";
		break;
	case 0x0000BD00:
		ptr = "	MITSUBISHI CABLE COMPANY";
		break;
	case 0x0000BE00:
		ptr = "	THE NTI GROUP";
		break;
	case 0x0000BF00:
		ptr = "	SYMMETRIC COMPUTER SYSTEMS";
		break;
	case 0x0000C000:
		ptr = "	WESTERN DIGITAL CORPORATION";
		break;
	case 0x0000C100:
		ptr = "	Madge Networks Ltd.";
		break;
	case 0x0000C200:
		ptr = "	INFORMATION PRESENTATION TECH.";
		break;
	case 0x0000C300:
		ptr = "	HARRIS CORP COMPUTER SYS DIV";
		break;
	case 0x0000C400:
		ptr = "	WATERS DIV. OF MILLIPORE";
		break;
	case 0x0000C500:
		ptr = "	FARALLON COMPUTING/NETOPIA";
		break;
	case 0x0000C600:
		ptr = "	EON SYSTEMS";
		break;
	case 0x0000C700:
		ptr = "	ARIX CORPORATION";
		break;
	case 0x0000C800:
		ptr = "	ALTOS COMPUTER SYSTEMS";
		break;
	case 0x0000C900:
		ptr = "	EMULEX CORPORATION";
		break;
	case 0x0000CA00:
		ptr = "	APPLITEK";
		break;
	case 0x0000CB00:
		ptr = "	COMPU-SHACK ELECTRONIC GMBH";
		break;
	case 0x0000CC00:
		ptr = "	DENSAN CO., LTD.";
		break;
	case 0x0000CD00:
		ptr = "	Centrecom Systems, Ltd.";
		break;
	case 0x0000CE00:
		ptr = "	MEGADATA CORP.";
		break;
	case 0x0000CF00:
		ptr = "	HAYES MICROCOMPUTER PRODUCTS";
		break;
	case 0x0000D000:
		ptr = "	DEVELCON ELECTRONICS LTD.";
		break;
	case 0x0000D100:
		ptr = "	ADAPTEC INCORPORATED";
		break;
	case 0x0000D200:
		ptr = "	SBE, INC.";
		break;
	case 0x0000D300:
		ptr = "	WANG LABORATORIES INC.";
		break;
	case 0x0000D400:
		ptr = "	PURE DATA LTD.";
		break;
	case 0x0000D500:
		ptr = "	MICROGNOSIS INTERNATIONAL";
		break;
	case 0x0000D600:
		ptr = "	PUNCH LINE HOLDING";
		break;
	case 0x0000D700:
		ptr = "	DARTMOUTH COLLEGE";
		break;
	case 0x0000D800:
		ptr = "	NOVELL, INC.";
		break;
	case 0x0000D900:
		ptr = "	NIPPON TELEGRAPH & TELEPHONE";
		break;
	case 0x0000DA00:
		ptr = "	ATEX";
		break;
	case 0x0000DB00:
		ptr = "	BRITISH TELECOMMUNICATIONS PLC";
		break;
	case 0x0000DC00:
		ptr = "	HAYES MICROCOMPUTER PRODUCTS";
		break;
	case 0x0000DD00:
		ptr = "	TCL INCORPORATED";
		break;
	case 0x0000DE00:
		ptr = "	CETIA";
		break;
	case 0x0000DF00:
		ptr = "	BELL & HOWELL PUB SYS DIV";
		break;
	case 0x0000E000:
		ptr = "	QUADRAM CORP.";
		break;
	case 0x0000E100:
		ptr = "	GRID SYSTEMS";
		break;
	case 0x0000E200:
		ptr = "	ACER TECHNOLOGIES CORP.";
		break;
	case 0x0000E300:
		ptr = "	INTEGRATED MICRO PRODUCTS LTD";
		break;
	case 0x0000E400:
		ptr = "	IN2 GROUPE INTERTECHNIQUE";
		break;
	case 0x0000E500:
		ptr = "	SIGMEX LTD.";
		break;
	case 0x0000E600:
		ptr = "	APTOR PRODUITS DE COMM INDUST";
		break;
	case 0x0000E700:
		ptr = "	STAR GATE TECHNOLOGIES";
		break;
	case 0x0000E800:
		ptr = "	ACCTON TECHNOLOGY CORP.";
		break;
	case 0x0000E900:
		ptr = "	ISICAD, INC.";
		break;
	case 0x0000EA00:
		ptr = "	UPNOD AB";
		break;
	case 0x0000EB00:
		ptr = "	MATSUSHITA COMM. IND. CO. LTD.";
		break;
	case 0x0000EC00:
		ptr = "	MICROPROCESS";
		break;
	case 0x0000ED00:
		ptr = "	APRIL";
		break;
	case 0x0000EE00:
		ptr = "	NETWORK DESIGNERS, LTD.";
		break;
	case 0x0000EF00:
		ptr = "	KTI";
		break;
	case 0x0000F000:
		ptr = "	SAMSUNG ELECTRONICS CO., LTD.";
		break;
	case 0x0000F100:
		ptr = "	MAGNA COMPUTER CORPORATION";
		break;
	case 0x0000F200:
		ptr = "	SPIDER COMMUNICATIONS";
		break;
	case 0x0000F300:
		ptr = "	GANDALF DATA LIMITED";
		break;
	case 0x0000F400:
		ptr = "	ALLIED TELESYN INTERNATIONAL";
		break;
	case 0x0000F500:
		ptr = "	DIAMOND SALES LIMITED";
		break;
	case 0x0000F600:
		ptr = "	APPLIED MICROSYSTEMS CORP.";
		break;
	case 0x0000F700:
		ptr = "	YOUTH KEEP ENTERPRISE CO LTD";
		break;
	case 0x0000F800:
		ptr = "	DIGITAL EQUIPMENT CORPORATION";
		break;
	case 0x0000F900:
		ptr = "	QUOTRON SYSTEMS INC.";
		break;
	case 0x0000FA00:
		ptr = "	MICROSAGE COMPUTER SYSTEMS INC";
		break;
	case 0x0000FB00:
		ptr = "	RECHNER ZUR KOMMUNIKATION";
		break;
	case 0x0000FC00:
		ptr = "	MEIKO";
		break;
	case 0x0000FD00:
		ptr = "	HIGH LEVEL HARDWARE";
		break;
	case 0x0000FE00:
		ptr = "	ANNAPOLIS MICRO SYSTEMS";
		break;
	case 0x0000FF00:
		ptr = "	CAMTEC ELECTRONICS LTD.";
		break;
	case 0x00010000:
		ptr = "	EQUIP'TRANS";
		break;
	case 0x00010200:
	case 0x00010300:
		ptr = "	3COM CORPORATION";
		break;
	case 0x00010400:
		ptr = "	DVICO Co., Ltd.";
		break;
	case 0x00010500:
		ptr = "	BECKHOFF GmbH";
		break;
	case 0x00010600:
		ptr = "	Tews Datentechnik GmbH";
		break;
	case 0x00010700:
		ptr = "	Leiser GmbH";
		break;
	case 0x00010800:
		ptr = "	AVLAB Technology, Inc.";
		break;
	case 0x00010900:
		ptr = "	Nagano Japan Radio Co., Ltd.";
		break;
	case 0x00010A00:
		ptr = "	CIS TECHNOLOGY INC.";
		break;
	case 0x00010B00:
		ptr = "	Space CyberLink, Inc.";
		break;
	case 0x00010C00:
		ptr = "	System Talks Inc.";
		break;
	case 0x00010D00:
		ptr = "	CORECO, INC.";
		break;
	case 0x00010E00:
		ptr = "	Bri-Link Technologies Co., Ltd";
		break;
	case 0x00010F00:
		ptr = "	Nishan Systems, Inc.";
		break;
	case 0x00011000:
		ptr = "	Gotham Networks";
		break;
	case 0x00011100:
		ptr = "	iDigm Inc.";
		break;
	case 0x00011200:
		ptr = "	Shark Multimedia Inc.";
		break;
	case 0x00011300:
		ptr = "	OLYMPUS OPTICAL CO., LTD.";
		break;
	case 0x00011400:
		ptr = "	KANDA TSUSHIN KOGYO CO., LTD.";
		break;
	case 0x00011500:
		ptr = "	EXTRATECH CORPORATION";
		break;
	case 0x00011600:
		ptr = "	Netspect Technologies, Inc.";
		break;
	case 0x00011700:
		ptr = "	CANAL +";
		break;
	case 0x00011800:
		ptr = "	EZ Digital Co., Ltd.";
		break;
	case 0x00011900:
		ptr = "	Action Controls Pty. Ltd.";
		break;
	case 0x00011A00:
		ptr = "	EEH DataLink GmbH";
		break;
	case 0x00011B00:
		ptr = "	Unizone Technologies, Inc.";
		break;
	case 0x00011C00:
		ptr = "	Universal Talkware Corporation";
		break;
	case 0x00011D00:
		ptr = "	Centillium Communications";
		break;
	case 0x00011E00:
		ptr = "	Precidia Technologies, Inc.";
		break;
	case 0x00011F00:
		ptr = "	RC Networks, Inc.";
		break;
	case 0x00012000:
		ptr = "	OSCILLOQUARTZ S.A.";
		break;
	case 0x00012100:
		ptr = "	RapidStream Inc.";
		break;
	case 0x00012200:
		ptr = "	Trend Communications, Ltd.";
		break;
	case 0x00012300:
		ptr = "	DIGITAL ELECTRONICS CORP.";
		break;
	case 0x00012400:
		ptr = "	Acer Incorporated";
		break;
	case 0x00012500:
		ptr = "	YAESU MUSEN CO., LTD.";
		break;
	case 0x00012600:
		ptr = "	PAC Labs";
		break;
	case 0x00012700:
		ptr = "	The OPEN Group Limited";
		break;
	case 0x00012800:
		ptr = "	EnjoyWeb, Inc.";
		break;
	case 0x00012900:
		ptr = "	DFI Inc.";
		break;
	case 0x00012A00:
		ptr = "	Telematica Sistems Inteligente";
		break;
	case 0x00012B00:
		ptr = "	TELENET Co., Ltd.";
		break;
	case 0x00012C00:
		ptr = "	Aravox Technologies, Inc.";
		break;
	case 0x00012D00:
		ptr = "	Komodo Technology";
		break;
	case 0x00012E00:
		ptr = "	PC Partner Ltd.";
		break;
	case 0x00012F00:
		ptr = "	Twinhead International Corp";
		break;
	case 0x00013000:
		ptr = "	Extreme Networks";
		break;
	case 0x00013100:
		ptr = "	Detection Systems, Inc.";
		break;
	case 0x00013200:
		ptr = "	Dranetz - BMI";
		break;
	case 0x00013300:
		ptr = "	KYOWA Electronic Instruments C";
		break;
	case 0x00013400:
		ptr = "	SIG Positec Systems AG";
		break;
	case 0x00013500:
		ptr = "	KDC Corp.";
		break;
	case 0x00013600:
		ptr = "	CyberTAN Technology, Inc.";
		break;
	case 0x00013700:
		ptr = "	IT Farm Corporation";
		break;
	case 0x00013800:
		ptr = "	XAVi Technologies Corp.";
		break;
	case 0x00013900:
		ptr = "	Point Multimedia Systems";
		break;
	case 0x00013A00:
		ptr = "	SHELCAD COMMUNICATIONS, LTD.";
		break;
	case 0x00013B00:
		ptr = "	BNA SYSTEMS";
		break;
	case 0x00013C00:
		ptr = "	TIW SYSTEMS";
		break;
	case 0x00013D00:
		ptr = "	RiscStation Ltd.";
		break;
	case 0x00013E00:
		ptr = "	Ascom Tateco AB";
		break;
	case 0x00013F00:
		ptr = "	Neighbor World Co., Ltd.";
		break;
	case 0x00014000:
		ptr = "	Sendtek Corporation";
		break;
	case 0x00014100:
		ptr = "	CABLE PRINT";
		break;
	case 0x00014200:
	case 0x00014300:
		ptr = "	Cisco Systems, Inc.";
		break;
	case 0x00014400:
		ptr = "	Cereva Networks, Inc.";
		break;
	case 0x00014500:
		ptr = "	WINSYSTEMS, INC.";
		break;
	case 0x00014600:
		ptr = "	Tesco Controls, Inc.";
		break;
	case 0x00014700:
		ptr = "	Zhone Technologies";
		break;
	case 0x00014800:
		ptr = "	X-traWeb Inc.";
		break;
	case 0x00014900:
		ptr = "	T.D.T. Transfer Data Test GmbH";
		break;
	case 0x00014A00:
		ptr = "	SONY COMPUTER SCIENCE LABS., I";
		break;
	case 0x00014B00:
		ptr = "	Ennovate Networks, Inc.";
		break;
	case 0x00014C00:
		ptr = "	Berkeley Process Control";
		break;
	case 0x00014D00:
		ptr = "	Shin Kin Enterprises Co., Ltd";
		break;
	case 0x00014E00:
		ptr = "	WIN Enterprises, Inc.";
		break;
	case 0x00014F00:
		ptr = "	LUMINOUS Networks, Inc.";
		break;
	case 0x00015000:
		ptr = "	GILAT COMMUNICATIONS, LTD.";
		break;
	case 0x00015100:
		ptr = "	Ensemble Communications";
		break;
	case 0x00015200:
		ptr = "	CHROMATEK INC.";
		break;
	case 0x00015300:
		ptr = "	ARCHTEK TELECOM CORPORATION";
		break;
	case 0x00015400:
		ptr = "	G3M Corporation";
		break;
	case 0x00015500:
		ptr = "	Promise Technology, Inc.";
		break;
	case 0x00015600:
		ptr = "	FIREWIREDIRECT.COM, INC.";
		break;
	case 0x00015700:
		ptr = "	SYSWAVE CO., LTD";
		break;
	case 0x00015800:
		ptr = "	Electro Industries/Gauge Tech";
		break;
	case 0x00015900:
		ptr = "	S1 Corporation";
		break;
	case 0x00015A00:
		ptr = "	Digital Video Broadcasting";
		break;
	case 0x00015B00:
		ptr = "	ITALTEL S.p.A/RF-UP-I";
		break;
	case 0x00015C00:
		ptr = "	CADANT INC.";
		break;
	case 0x00015D00:
		ptr = "	Pirus Networks";
		break;
	case 0x00015E00:
		ptr = "	BEST TECHNOLOGY CO., LTD.";
		break;
	case 0x00015F00:
		ptr = "	DIGITAL DESIGN GmbH";
		break;
	case 0x00016000:
		ptr = "	ELMEX Co., LTD.";
		break;
	case 0x00016100:
		ptr = "	Meta Machine Technology";
		break;
	case 0x00016200:
		ptr = "	Cygnet Technologies, Inc.";
		break;
	case 0x00016300:
	case 0x00016400:
		ptr = "	Cisco Systems, Inc.";
		break;
	case 0x00016500:
		ptr = "	AirSwitch Corporation";
		break;
	case 0x00016600:
		ptr = "	TC GROUP A/S";
		break;
	case 0x00016700:
		ptr = "	HIOKI E.E. CORPORATION";
		break;
	case 0x00016800:
		ptr = "	VITANA CORPORATION";
		break;
	case 0x00016900:
		ptr = "	Celestix Networks Pte Ltd.";
		break;
	case 0x00016A00:
		ptr = "	ALITEC";
		break;
	case 0x00016B00:
		ptr = "	LightChip, Inc.";
		break;
	case 0x00016C00:
		ptr = "	FOXCONN";
		break;
	case 0x00016D00:
		ptr = "	Triton Network Systems";
		break;
	case 0x00016E00:
		ptr = "	Conklin Corporation";
		break;
	case 0x00016F00:
		ptr = "	HAITAI ELECTRONICS CO., LTD.";
		break;
	case 0x00017000:
		ptr = "	ESE Embedded System Engineer'g";
		break;
	case 0x00017100:
		ptr = "	Allied Data Technologies";
		break;
	case 0x00017200:
		ptr = "	TechnoLand Co., LTD.";
		break;
	case 0x00017300:
		ptr = "	JNI Corporation";
		break;
	case 0x00017400:
		ptr = "	CyberOptics Corporation";
		break;
	case 0x00017500:
		ptr = "	Radiant Communications Corp.";
		break;
	case 0x00017600:
		ptr = "	Orient Silver Enterprises";
		break;
	case 0x00017700:
		ptr = "	EDSL";
		break;
	case 0x00017800:
		ptr = "	MARGI Systems, Inc.";
		break;
	case 0x00017900:
		ptr = "	WIRELESS TECHNOLOGY, INC.";
		break;
	case 0x00017A00:
		ptr = "	Chengdu Maipu Electric Industrial Co., Ltd.";
		break;
	case 0x00017B00:
		ptr = "	Heidelberger Druckmaschinen AG";
		break;
	case 0x00017C00:
		ptr = "	AG-E GmbH";
		break;
	case 0x00017D00:
		ptr = "	ThermoQuest";
		break;
	case 0x00017E00:
		ptr = "	ADTEK System Science Co., Ltd.";
		break;
	case 0x00017F00:
		ptr = "	Experience Music Project";
		break;
	case 0x00018000:
		ptr = "	AOpen, Inc.";
		break;
	case 0x00018100:
		ptr = "	Nortel Networks";
		break;
	case 0x00018200:
		ptr = "	DICA TECHNOLOGIES AG";
		break;
	case 0x00018300:
		ptr = "	ANITE TELECOMS";
		break;
	case 0x00018400:
		ptr = "	SIEB & MEYER AG";
		break;
	case 0x00018500:
		ptr = "	Aloka Co., Ltd.";
		break;
	case 0x00018600:
		ptr = "	DISCH GmbH";
		break;
	case 0x00018700:
		ptr = "	i2SE GmbH";
		break;
	case 0x00018800:
		ptr = "	LXCO Technologies ag";
		break;
	case 0x00018900:
		ptr = "	Refraction Technology, Inc.";
		break;
	case 0x00018A00:
		ptr = "	ROI COMPUTER AG";
		break;
	case 0x00018B00:
		ptr = "	NetLinks Co., Ltd.";
		break;
	case 0x00018C00:
		ptr = "	Mega Vision";
		break;
	case 0x00018D00:
		ptr = "	AudeSi Technologies";
		break;
	case 0x00018E00:
		ptr = "	Logitec Corporation";
		break;
	case 0x00018F00:
		ptr = "	Kenetec, Inc.";
		break;
	case 0x00019000:
		ptr = "	SMK-M";
		break;
	case 0x00019100:
		ptr = "	SYRED Data Systems";
		break;
	case 0x00019200:
		ptr = "	Texas Digital Systems";
		break;
	case 0x00019300:
		ptr = "	Hanbyul Telecom Co., Ltd.";
		break;
	case 0x00019400:
		ptr = "	Capital Equipment Corporation";
		break;
	case 0x00019500:
		ptr = "	Sena Technologies, Inc.";
		break;
	case 0x00019600:
	case 0x00019700:
		ptr = "	Cisco Systems, Inc.";
		break;
	case 0x00019800:
		ptr = "	Darim Vision";
		break;
	case 0x00019900:
		ptr = "	HeiSei Electronics";
		break;
	case 0x00019A00:
		ptr = "	LEUNIG GmbH";
		break;
	case 0x00019B00:
		ptr = "	Kyoto Microcomputer Co., Ltd.";
		break;
	case 0x00019C00:
		ptr = "	JDS Uniphase Inc.";
		break;
	case 0x00019D00:
		ptr = "	E-Control Systems, Inc.";
		break;
	case 0x00019E00:
		ptr = "	ESS Technology, Inc.";
		break;
	case 0x00019F00:
		ptr = "	Phonex Broadband";
		break;
	case 0x0001A000:
		ptr = "	Infinilink Corporation";
		break;
	case 0x0001A100:
		ptr = "	Mag-Tek, Inc.";
		break;
	case 0x0001A200:
		ptr = "	Logical Co., Ltd.";
		break;
	case 0x0001A300:
		ptr = "	GENESYS LOGIC, INC.";
		break;
	case 0x0001A400:
		ptr = "	Microlink Corporation";
		break;
	case 0x0001A500:
		ptr = "	Nextcomm, Inc.";
		break;
	case 0x0001A600:
		ptr = "	Scientific-Atlanta Arcodan A/S";
		break;
	case 0x0001A700:
		ptr = "	UNEX TECHNOLOGY CORPORATION";
		break;
	case 0x0001A800:
		ptr = "	Welltech Computer Co., Ltd.";
		break;
	case 0x0001A900:
		ptr = "	BMW AG";
		break;
	case 0x0001AA00:
		ptr = "	Airspan Communications, Ltd.";
		break;
	case 0x0001AB00:
		ptr = "	Main Street Networks";
		break;
	case 0x0001AC00:
		ptr = "	Sitara Networks, Inc.";
		break;
	case 0x0001AD00:
		ptr = "	Coach Master International  d.b.a. CMI Worldwide, Inc.";
		break;
	case 0x0001AE00:
		ptr = "	Trex Enterprises";
		break;
	case 0x0001AF00:
		ptr = "	Motorola Computer Group";
		break;
	case 0x0001B000:
		ptr = "	Fulltek Technology Co., Ltd.";
		break;
	case 0x0001B100:
		ptr = "	General Bandwidth";
		break;
	case 0x0001B200:
		ptr = "	Digital Processing Systems, Inc.";
		break;
	case 0x0001B300:
		ptr = "	Precision Electronic Manufacturing";
		break;
	case 0x0001B400:
		ptr = "	Wayport, Inc.";
		break;
	case 0x0001B500:
		ptr = "	Turin Networks, Inc.";
		break;
	case 0x0001B600:
		ptr = "	SAEJIN T&M Co., Ltd.";
		break;
	case 0x0001B700:
		ptr = "	Centos, Inc.";
		break;
	case 0x0001B800:
		ptr = "	Netsensity, Inc.";
		break;
	case 0x0001B900:
		ptr = "	SKF Condition Monitoring";
		break;
	case 0x0001BA00:
		ptr = "	IC-Net, Inc.";
		break;
	case 0x0001BB00:
		ptr = "	Frequentis";
		break;
	case 0x0001BC00:
		ptr = "	Brains Corporation";
		break;
	case 0x0001BD00:
		ptr = "	Peterson Electro-Musical Products, Inc.";
		break;
	case 0x0001BE00:
		ptr = "	Gigalink Co., Ltd.";
		break;
	case 0x0001BF00:
		ptr = "	Teleforce Co., Ltd.";
		break;
	case 0x0001C000:
		ptr = "	CompuLab, Ltd.";
		break;
	case 0x0001C100:
		ptr = "	Exbit Technology";
		break;
	case 0x0001C200:
		ptr = "	ARK Research Corp.";
		break;
	case 0x0001C300:
		ptr = "	Acromag, Inc.";
		break;
	case 0x0001C400:
		ptr = "	NeoWave, Inc.";
		break;
	case 0x0001C500:
		ptr = "	Simpler Networks";
		break;
	case 0x0001C600:
		ptr = "	Quarry Technologies";
		break;
	case 0x0001C700:
		ptr = "	Cisco Systems, Inc.";
		break;
	case 0x0001C800:
		ptr = "	THOMAS CONRAD CORP.";
		break;
	case 0x0001C900:
		ptr = "	Cisco Systems, Inc.";
		break;
	case 0x0001CA00:
		ptr = "	Geocast Network Systems, Inc.";
		break;
	case 0x0001CB00:
		ptr = "	NetGame, Ltd.";
		break;
	case 0x0001CC00:
		ptr = "	Japan Total Design Communication Co., Ltd.";
		break;
	case 0x0001CD00:
		ptr = "	ARtem";
		break;
	case 0x0001CE00:
		ptr = "	Custom Micro Products, Ltd.";
		break;
	case 0x0001CF00:
		ptr = "	Alpha Data Parallel Systems, Ltd.";
		break;
	case 0x0001D000:
		ptr = "	VitalPoint, Inc.";
		break;
	case 0x0001D100:
		ptr = "	CoNet Communications, Inc.";
		break;
	case 0x0001D200:
		ptr = "	MacPower Peripherals, Ltd.";
		break;
	case 0x0001D300:
		ptr = "	PAXCOMM, Inc.";
		break;
	case 0x0001D400:
		ptr = "	Leisure Time, Inc.";
		break;
	case 0x0001D500:
		ptr = "	HAEDONG INFO & COMM CO., LTD";
		break;
	case 0x0001D600:
		ptr = "	MAN Roland Druckmaschinen AG";
		break;
	case 0x0001D700:
		ptr = "	F5 Networks, Inc.";
		break;
	case 0x0001D800:
		ptr = "	Teltronics, Inc.";
		break;
	case 0x0001D900:
		ptr = "	Sigma, Inc.";
		break;
	case 0x0001DA00:
		ptr = "	WINCOMM Corporation";
		break;
	case 0x0001DB00:
		ptr = "	Freecom Technologies GmbH";
		break;
	case 0x0001DC00:
		ptr = "	Activetelco";
		break;
	case 0x0001DD00:
		ptr = "	Avail Networks";
		break;
	case 0x0001DE00:
		ptr = "	Trango Systems, Inc.";
		break;
	case 0x0001DF00:
		ptr = "	ISDN Communications, Ltd.";
		break;
	case 0x0001E000:
		ptr = "	Fast Systems, Inc.";
		break;
	case 0x0001E100:
		ptr = "	Kinpo Electronics, Inc.";
		break;
	case 0x0001E200:
		ptr = "	Ando Electric Corporation";
		break;
	case 0x0001E300:
		ptr = "	Siemens AG";
		break;
	case 0x0001E400:
		ptr = "	Sitera, Inc.";
		break;
	case 0x0001E500:
		ptr = "	Supernet, Inc.";
		break;
	case 0x0001E600:
	case 0x0001E700:
		ptr = "	Hewlett-Packard Company";
		break;
	case 0x0001E800:
		ptr = "	Force10 Networks, Inc.";
		break;
	case 0x0001E900:
		ptr = "	Litton Marine Systems B.V.";
		break;
	case 0x0001EA00:
		ptr = "	Cirilium Corp.";
		break;
	case 0x0001EB00:
		ptr = "	C-COM Corporation";
		break;
	case 0x0001EC00:
		ptr = "	Ericsson Group";
		break;
	case 0x0001ED00:
		ptr = "	SETA Corp.";
		break;
	case 0x0001EE00:
		ptr = "	Comtrol Europe, Ltd.";
		break;
	case 0x0001EF00:
		ptr = "	Camtel Technology Corp.";
		break;
	case 0x0001F000:
		ptr = "	Tridium, Inc.";
		break;
	case 0x0001F100:
		ptr = "	Innovative Concepts, Inc.";
		break;
	case 0x0001F300:
		ptr = "	QPS, Inc.";
		break;
	case 0x0001F400:
		ptr = "	Enterasys Networks";
		break;
	case 0x0001F500:
		ptr = "	ERIM S.A.";
		break;
	case 0x0001F600:
		ptr = "	Association of Musical Electronics Industry";
		break;
	case 0x0001F700:
		ptr = "	Image Display Systems, Inc.";
		break;
	case 0x0001F800:
		ptr = "	Adherent Systems, Ltd.";
		break;
	case 0x0001F900:
		ptr = "	TeraGlobal Communications Corp.";
		break;
	case 0x0001FA00:
		ptr = "	HOROSCAS";
		break;
	case 0x0001FB00:
		ptr = "	DoTop Technology, Inc.";
		break;
	case 0x0001FC00:
		ptr = "	Keyence Corporation";
		break;
	case 0x0001FD00:
		ptr = "	Digital Voice Systems, Inc.";
		break;
	case 0x0001FE00:
		ptr = "	DIGITAL EQUIPMENT CORPORATION";
		break;
	case 0x0001FF00:
		ptr = "	Data Direct Networks, Inc.";
		break;
	case 0x00020000:
		ptr = "	Net & Sys Co., Ltd.";
		break;
	case 0x00020100:
		ptr = "	IFM Electronic gmbh";
		break;
	case 0x00020200:
		ptr = "	Amino Communications, Ltd.";
		break;
	case 0x00020300:
		ptr = "	Woonsang Telecom, Inc.";
		break;
	case 0x00020400:
		ptr = "	Bodmann Industries Elektronik GmbH";
		break;
	case 0x00020500:
		ptr = "	Hitachi Denshi, Ltd.";
		break;
	case 0x00020600:
		ptr = "	Telital R&D Denmark A/S";
		break;
	case 0x00020800:
		ptr = "	Unify Networks, Inc.";
		break;
	case 0x00020900:
		ptr = "	Shenzhen SED Information Technology Co., Ltd.";
		break;
	case 0x00020A00:
		ptr = "	Gefran Spa";
		break;
	case 0x00020B00:
		ptr = "	Native Networks, Inc.";
		break;
	case 0x00020C00:
		ptr = "	Metro-Optix";
		break;
	case 0x00020D00:
		ptr = "	Micronpc.com";
		break;
	case 0x00020E00:
		ptr = "	Laurel Networks, Inc.";
		break;
	case 0x00020F00:
		ptr = "	AATR";
		break;
	case 0x00021000:
		ptr = "	Fenecom";
		break;
	case 0x00021100:
		ptr = "	Nature Worldwide Technology Corp.";
		break;
	case 0x00021200:
		ptr = "	SierraCom";
		break;
	case 0x00021300:
		ptr = "	S.D.E.L.";
		break;
	case 0x00021400:
		ptr = "	DTVRO";
		break;
	case 0x00021500:
		ptr = "	Cotas Computer Technology A/B";
		break;
	case 0x00021600:
	case 0x00021700:
		ptr = "	Cisco Systems, Inc.";
		break;
	case 0x00021800:
		ptr = "	Advanced Scientific Corp";
		break;
	case 0x00021900:
		ptr = "	Paralon Technologies";
		break;
	case 0x00021A00:
		ptr = "	Zuma Networks";
		break;
	case 0x00021B00:
		ptr = "	Kollmorgen-Servotronix";
		break;
	case 0x00021C00:
		ptr = "	Network Elements, Inc.";
		break;
	case 0x00021D00:
		ptr = "	Data General Communication Ltd.";
		break;
	case 0x00021E00:
		ptr = "	SIMTEL S.R.L.";
		break;
	case 0x00021F00:
		ptr = "	Aculab PLC";
		break;
	case 0x00022000:
		ptr = "	Canon Aptex, Inc.";
		break;
	case 0x00022100:
		ptr = "	DSP Application, Ltd.";
		break;
	case 0x00022200:
		ptr = "	Chromisys, Inc.";
		break;
	case 0x00022300:
		ptr = "	ClickTV";
		break;
	case 0x00022400:
		ptr = "	Lantern Communications, Inc.";
		break;
	case 0x00022500:
		ptr = "	Certus Technology, Inc.";
		break;
	case 0x00022600:
		ptr = "	XESystems, Inc.";
		break;
	case 0x00022700:
		ptr = "	ESD GmbH";
		break;
	case 0x00022800:
		ptr = "	Necsom, Ltd.";
		break;
	case 0x00022900:
		ptr = "	Adtec Corporation";
		break;
	case 0x00022A00:
		ptr = "	Asound Electronic";
		break;
	case 0x00022B00:
		ptr = "	Tamura Electric Works, Ltd.";
		break;
	case 0x00022C00:
		ptr = "	ABB-BOMEM";
		break;
	case 0x00022D00:
		ptr = "	Lucent Technologies WCND";
		break;
	case 0x00022E00:
		ptr = "	TEAC Corp. R& D";
		break;
	case 0x00022F00:
		ptr = "	P-Cube, Ltd.";
		break;
	case 0x00023000:
		ptr = "	Intersoft Electronics";
		break;
	case 0x00023100:
		ptr = "	Ingersoll-Rand";
		break;
	case 0x00023200:
		ptr = "	Avision, Inc.";
		break;
	case 0x00023300:
		ptr = "	Mantra Communications, Inc.";
		break;
	case 0x00023400:
		ptr = "	Imperial Technology, Inc.";
		break;
	case 0x00023500:
		ptr = "	Paragon Networks International";
		break;
	case 0x00023600:
		ptr = "	INIT GmbH";
		break;
	case 0x00023700:
		ptr = "	Cosmo Research Corp.";
		break;
	case 0x00023800:
		ptr = "	Serome Technology, Inc.";
		break;
	case 0x00023900:
		ptr = "	Visicom";
		break;
	case 0x00023A00:
		ptr = "	ZSK Stickmaschinen GmbH";
		break;
	case 0x00023B00:
		ptr = "	Redback Networks";
		break;
	case 0x00023C00:
		ptr = "	Creative Technology, Ltd.";
		break;
	case 0x00023D00:
		ptr = "	NuSpeed, Inc.";
		break;
	case 0x00023E00:
		ptr = "	Selta Telematica S.p.a";
		break;
	case 0x00023F00:
		ptr = "	Compal Electronics, Inc.";
		break;
	case 0x00024000:
		ptr = "	Seedek Co., Ltd.";
		break;
	case 0x00024100:
		ptr = "	Amer.com";
		break;
	case 0x00024200:
		ptr = "	Videoframe Systems";
		break;
	case 0x00024300:
		ptr = "	Raysis Co., Ltd.";
		break;
	case 0x00024400:
		ptr = "	SURECOM Technology Co.";
		break;
	case 0x00024500:
		ptr = "	Lampus Co, Ltd.";
		break;
	case 0x00024600:
		ptr = "	All-Win Tech Co., Ltd.";
		break;
	case 0x00024700:
		ptr = "	Great Dragon Information Technology (Group) Co., Ltd.";
		break;
	case 0x00024800:
		ptr = "	Pila GmbH & Co.";
		break;
	case 0x00024900:
		ptr = "	Aviv Infocom Co, Ltd.";
		break;
	case 0x00024A00:
	case 0x00024B00:
		ptr = "	Cisco Systems, Inc.";
		break;
	case 0x00024C00:
		ptr = "	SiByte, Inc.";
		break;
	case 0x00024D00:
		ptr = "	Mannesman Dematic Colby Pty. Ltd.";
		break;
	case 0x00024E00:
		ptr = "	Datacard Group";
		break;
	case 0x00024F00:
		ptr = "	IPM Datacom S.R.L.";
		break;
	case 0x00025000:
		ptr = "	Geyser Networks, Inc.";
		break;
	case 0x00025100:
		ptr = "	Soma Networks";
		break;
	case 0x00025200:
		ptr = "	Carrier Corporation";
		break;
	case 0x00025300:
		ptr = "	Televideo, Inc.";
		break;
	case 0x00025400:
		ptr = "	WorldGate";
		break;
	case 0x00025500:
		ptr = "	IBM Corporation";
		break;
	case 0x00025600:
		ptr = "	Alpha Processor, Inc.";
		break;
	case 0x00025700:
		ptr = "	Microcom Corp.";
		break;
	case 0x00025800:
		ptr = "	Flying Packets Communications";
		break;
	case 0x00025900:
		ptr = "	Tsann Kuen China (Shanghai)Enterprise Co., Ltd. IT Group";
		break;
	case 0x00025A00:
		ptr = "	Catena Networks";
		break;
	case 0x00025B00:
		ptr = "	Cambridge Silicon Radio";
		break;
	case 0x00025C00:
		ptr = "	SCI Systems (Kunshan) Co., Ltd.";
		break;
	case 0x00025E00:
		ptr = "	High Technology Ltd";
		break;
	case 0x00025F00:
		ptr = "	Nortel Networks";
		break;
	case 0x00026000:
		ptr = "	Accordion Networks, Inc.";
		break;
	case 0x00026100:
		ptr = "	i3 Micro Technology AB";
		break;
	case 0x00026200:
		ptr = "	Soyo Group Soyo Com Tech Co., Ltd";
		break;
	case 0x00026300:
		ptr = "	UPS Manufacturing SRL";
		break;
	case 0x00026400:
		ptr = "	AudioRamp.com";
		break;
	case 0x00026500:
		ptr = "	Virditech Co. Ltd.";
		break;
	case 0x00026600:
		ptr = "	Thermalogic Corporation";
		break;
	case 0x00026700:
		ptr = "	NODE RUNNER, INC.";
		break;
	case 0x00026800:
		ptr = "	Harris Government Communications";
		break;
	case 0x00026900:
		ptr = "	Nadatel Co., Ltd";
		break;
	case 0x00026A00:
		ptr = "	Cocess Telecom Co., Ltd.";
		break;
	case 0x00026B00:
		ptr = "	BCM Computers Co., Ltd.";
		break;
	case 0x00026C00:
		ptr = "	Philips CFT";
		break;
	case 0x00026D00:
		ptr = "	Adept Telecom";
		break;
	case 0x00026E00:
		ptr = "	NeGeN Access, Inc.";
		break;
	case 0x00026F00:
		ptr = "	Senao International Co., Ltd.";
		break;
	case 0x00027000:
		ptr = "	Crewave Co., Ltd.";
		break;
	case 0x00027100:
		ptr = "	Vpacket Communications";
		break;
	case 0x00027200:
		ptr = "	CC&C Technologies, Inc.";
		break;
	case 0x00027300:
		ptr = "	Coriolis Networks";
		break;
	case 0x00027400:
		ptr = "	Tommy Technologies Corp.";
		break;
	case 0x00027500:
		ptr = "	SMART Technologies, Inc.";
		break;
	case 0x00027600:
		ptr = "	Primax Electronics Ltd.";
		break;
	case 0x00027700:
		ptr = "	Cash Systemes Industrie";
		break;
	case 0x00027800:
		ptr = "	Samsung Electro-Mechanics Co., Ltd.";
		break;
	case 0x00027900:
		ptr = "	Control Applications, Ltd.";
		break;
	case 0x00027A00:
		ptr = "	IOI Technology Corporation";
		break;
	case 0x00027B00:
		ptr = "	Amplify Net, Inc.";
		break;
	case 0x00027C00:
		ptr = "	Trilithic, Inc.";
		break;
	case 0x00028800:
		ptr = "	GLOBAL VILLAGE COMMUNICATION";
		break;
	case 0x00040000:
		ptr = "	LEXMARK INTERNATIONAL, INC.";
		break;
	case 0x0004AC00:
		ptr = "	IBM CORP.";
		break;
	case 0x00050200:
		ptr = "	APPLE COMPUTER";
		break;
	case 0x0005A800:
		ptr = "	WYLE ELECTRONICS";
		break;
	case 0x00062900:
		ptr = "	IBM CORPORATION";
		break;
	case 0x00062B00:
		ptr = "	INTRASERVER TECHNOLOGY";
		break;
	case 0x00067C00:
	case 0x0006C100:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00070100:
		ptr = "	RACAL-DATACOM";
		break;
	case 0x00080000:
		ptr = "	MULTITECH SYSTEMS, INC.";
		break;
	case 0x0008C700:
		ptr = "	COMPAQ COMPUTER CORPORATION";
		break;
	case 0x000A2700:
		ptr = "	Apple Computer, Inc.";
		break;
	case 0x00100000:
		ptr = "	CABLE TELEVISION";
		break;
	case 0x00100100:
		ptr = "	MCK COMMUNICATIONS";
		break;
	case 0x00100200:
		ptr = "	ACTIA";
		break;
	case 0x00100300:
		ptr = "	IMATRON, INC.";
		break;
	case 0x00100400:
		ptr = "	THE BRANTLEY COILE COMPANY,INC";
		break;
	case 0x00100500:
		ptr = "	UEC COMMERCIAL";
		break;
	case 0x00100600:
		ptr = "	RACAL RECORDERS LTD.";
		break;
	case 0x00100700:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00100800:
		ptr = "	VIENNA SYSTEMS CORPORATION";
		break;
	case 0x00100900:
		ptr = "	HORO QUARTZ";
		break;
	case 0x00100A00:
		ptr = "	WILLIAMS COMMUNICATIONS GROUP";
		break;
	case 0x00100B00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00100C00:
		ptr = "	ITO CO., LTD.";
		break;
	case 0x00100D00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00100E00:
		ptr = "	MICRO LINEAR COPORATION";
		break;
	case 0x00100F00:
		ptr = "	INDUSTRIAL CPU SYSTEMS";
		break;
	case 0x00101000:
		ptr = "	INITIO CORPORATION";
		break;
	case 0x00101100:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00101200:
		ptr = "	PROCESSOR SYSTEMS (I) PVT LTD";
		break;
	case 0x00101300:
		ptr = "	INDUSTRIAL COMPUTER SOURCE";
		break;
	case 0x00101400:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00101500:
		ptr = "	OOMON INC.";
		break;
	case 0x00101600:
		ptr = "	T.SQWARE";
		break;
	case 0x00101700:
		ptr = "	MICOS GMBH";
		break;
	case 0x00101800:
		ptr = "	BROADCOM CORPORATION";
		break;
	case 0x00101900:
		ptr = "	SIRONA DENTAL SYSTEMS";
		break;
	case 0x00101A00:
		ptr = "	PICTURETEL CORP.";
		break;
	case 0x00101B00:
		ptr = "	CORNET TECHNOLOGY, INC.";
		break;
	case 0x00101C00:
		ptr = "	OHM TECHNOLOGIES INTL, LLC";
		break;
	case 0x00101D00:
		ptr = "	WINBOND ELECTRONICS CORP.";
		break;
	case 0x00101E00:
		ptr = "	MATSUSHITA ELECTRONIC";
		break;
	case 0x00101F00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00102000:
		ptr = "	WELCH ALLYN, DATA COLLECTION";
		break;
	case 0x00102100:
		ptr = "	ENCANTO NETWORKS, INC.";
		break;
	case 0x00102200:
		ptr = "	SATCOM MEDIA CORPORATION";
		break;
	case 0x00102300:
		ptr = "	FLOWWISE NETWORKS, INC.";
		break;
	case 0x00102400:
		ptr = "	NAGOYA ELECTRIC WORKS CO., LTD";
		break;
	case 0x00102500:
		ptr = "	GRAYHILL INC.";
		break;
	case 0x00102600:
		ptr = "	ACCELERATED NETWORKS, INC.";
		break;
	case 0x00102700:
		ptr = "	L-3 COMMUNICATIONS EAST";
		break;
	case 0x00102800:
		ptr = "	COMPUTER TECHNICA, INC.";
		break;
	case 0x00102900:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00102A00:
		ptr = "	ZF MICROSYSTEMS, INC.";
		break;
	case 0x00102B00:
		ptr = "	UMAX DATA SYSTEMS, INC.";
		break;
	case 0x00102C00:
		ptr = "	PNP TECHNOLOGY A/S";
		break;
	case 0x00102D00:
		ptr = "	HITACHI SOFTWARE ENGINEERING";
		break;
	case 0x00102E00:
		ptr = "	NETWORK SYSTEMS & TECHNOLOGIES";
		break;
	case 0x00102F00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00103000:
		ptr = "	WI-LAN, INC.";
		break;
	case 0x00103100:
		ptr = "	OBJECTIVE COMMUNICATIONS, INC.";
		break;
	case 0x00103200:
		ptr = "	ALTA TECHNOLOGY";
		break;
	case 0x00103300:
		ptr = "	ACCESSLAN COMMUNICATIONS, INC.";
		break;
	case 0x00103400:
		ptr = "	GNP COMPUTERS";
		break;
	case 0x00103500:
		ptr = "	ELITEGROUP COMPUTER";
		break;
	case 0x00103600:
		ptr = "	INTER-TEL INTEGRATED SYSTEMS";
		break;
	case 0x00103700:
		ptr = "	CYQ'VE TECHNOLOGY CO., LTD.";
		break;
	case 0x00103800:
		ptr = "	MICRO RESEARCH INSTITUTE, INC.";
		break;
	case 0x00103900:
		ptr = "	VECTRON SYSTEMS GMBH";
		break;
	case 0x00103A00:
		ptr = "	DIAMOND NETWORK TECH";
		break;
	case 0x00103B00:
		ptr = "	HIPPI NETWORKING FORUM";
		break;
	case 0x00103C00:
		ptr = "	IC ENSEMBLE, INC.";
		break;
	case 0x00103D00:
		ptr = "	PHASECOM, LTD.";
		break;
	case 0x00103E00:
		ptr = "	NETSCHOOLS CORPORATION";
		break;
	case 0x00103F00:
		ptr = "	TOLLGRADE COMMUNICATIONS, INC.";
		break;
	case 0x00104000:
		ptr = "	INTERMEC CORPORATION";
		break;
	case 0x00104100:
		ptr = "	BRISTOL BABCOCK, INC.";
		break;
	case 0x00104200:
		ptr = "	ALACRITECH";
		break;
	case 0x00104300:
		ptr = "	A2 CORPORATION";
		break;
	case 0x00104400:
		ptr = "	INNOLABS CORPORATION";
		break;
	case 0x00104500:
		ptr = "	Nortel Networks";
		break;
	case 0x00104600:
		ptr = "	ALCORN MCBRIDE INC.";
		break;
	case 0x00104700:
		ptr = "	ECHO ELETRIC CO. LTD.";
		break;
	case 0x00104800:
		ptr = "	HTRC AUTOMATION, INC.";
		break;
	case 0x00104900:
		ptr = "	SHORELINE TELEWORKS, INC.";
		break;
	case 0x00104A00:
		ptr = "	THE PARVUC CORPORATION";
		break;
	case 0x00104B00:
		ptr = "	3COM CORPORATION";
		break;
	case 0x00104C00:
		ptr = "	COMPUTER ACCESS TECHNOLOGY";
		break;
	case 0x00104D00:
		ptr = "	SURTEC INDUSTRIES, INC.";
		break;
	case 0x00104E00:
		ptr = "	CEOLOGIC";
		break;
	case 0x00104F00:
		ptr = "	STORAGE TECHNOLOGY CORPORATION";
		break;
	case 0x00105000:
		ptr = "	RION CO., LTD.";
		break;
	case 0x00105100:
		ptr = "	CMICRO CORPORATION";
		break;
	case 0x00105200:
		ptr = "	METTLER-TOLEDO (ALBSTADT) GMBH";
		break;
	case 0x00105300:
		ptr = "	COMPUTER TECHNOLOGY CORP.";
		break;
	case 0x00105400:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00105500:
		ptr = "	FUJITSU MICROELECTRONICS, INC.";
		break;
	case 0x00105600:
		ptr = "	SODICK CO., LTD.";
		break;
	case 0x00105700:
		ptr = "	COREL COMPUTER CORPORATION";
		break;
	case 0x00105800:
		ptr = "	ARROWPOINT COMMUNICATIONS,INC.";
		break;
	case 0x00105900:
		ptr = "	DIABLO RESEARCH CO. LLC";
		break;
	case 0x00105A00:
		ptr = "	3COM CORPORATION";
		break;
	case 0x00105B00:
		ptr = "	NET INSIGHT AB";
		break;
	case 0x00105C00:
		ptr = "	QUANTUM DESIGNS (H.K.) LTD.";
		break;
	case 0x00105D00:
		ptr = "	DRAGER, BUSINESS UNIT";
		break;
	case 0x00105E00:
		ptr = "	HEKIMIAN LABORATORIES, INC.";
		break;
	case 0x00105F00:
		ptr = "	IN-SNEC";
		break;
	case 0x00106000:
		ptr = "	BILLIONTON SYSTEMS, INC.";
		break;
	case 0x00106100:
		ptr = "	HOSTLINK CORP.";
		break;
	case 0x00106200:
		ptr = "	NX SERVER, ILNC.";
		break;
	case 0x00106300:
		ptr = "	STARGUIDE DIGITAL NETWORKS";
		break;
	case 0x00106400:
		ptr = "	DIGITAL EQUIPMENT CORP.";
		break;
	case 0x00106500:
		ptr = "	RADYNE CORPORATION";
		break;
	case 0x00106600:
		ptr = "	ADVANCED CONTROL SYSTEMS, INC.";
		break;
	case 0x00106700:
		ptr = "	REDBACK NETWORKS, INC.";
		break;
	case 0x00106800:
		ptr = "	COMOS TELECOM";
		break;
	case 0x00106900:
		ptr = "	HELIOSS COMMUNICATIONS, INC.";
		break;
	case 0x00106A00:
		ptr = "	DIGITAL MICROWAVE CORPORATION";
		break;
	case 0x00106B00:
		ptr = "	SONUS NETWORKS, INC.";
		break;
	case 0x00106C00:
		ptr = "	INFRATEC PLUS GMBH";
		break;
	case 0x00106D00:
		ptr = "	INTEGRITY COMMUNICATIONS, INC.";
		break;
	case 0x00106E00:
		ptr = "	TADIRAN COM. LTD.";
		break;
	case 0x00106F00:
		ptr = "	TRENTON TECHNOLOGY INC.";
		break;
	case 0x00107000:
		ptr = "	CARADON TREND LTD.";
		break;
	case 0x00107100:
		ptr = "	ADVANET INC.";
		break;
	case 0x00107200:
		ptr = "	GVN TECHNOLOGIES, INC.";
		break;
	case 0x00107300:
		ptr = "	TECHNOBOX, INC.";
		break;
	case 0x00107400:
		ptr = "	ATEN INTERNATIONAL CO., LTD.";
		break;
	case 0x00107500:
		ptr = "	CREATIVE DESIGN SOLUTIONS,INC.";
		break;
	case 0x00107600:
		ptr = "	EUREM GMBH";
		break;
	case 0x00107700:
		ptr = "	SAF DRIVE SYSTEMS, LTD.";
		break;
	case 0x00107800:
		ptr = "	NUERA COMMUNICATIONS, INC.";
		break;
	case 0x00107900:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00107A00:
		ptr = "	AMBICOM, INC.";
		break;
	case 0x00107B00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00107C00:
		ptr = "	P-COM, INC.";
		break;
	case 0x00107D00:
		ptr = "	AURORA COMMUNICATIONS, LTD.";
		break;
	case 0x00107E00:
		ptr = "	BACHMANN ELECTRONIC GMBH";
		break;
	case 0x00107F00:
		ptr = "	CRESTRON ELECTRONICS, INC.";
		break;
	case 0x00108000:
		ptr = "	METAWAVE COMMUNICATIONS";
		break;
	case 0x00108100:
		ptr = "	DPS, INC.";
		break;
	case 0x00108200:
		ptr = "	JNA TELECOMMUNICATIONS LIMITED";
		break;
	case 0x00108300:
		ptr = "	HEWLETT-PACKARD COMPANY";
		break;
	case 0x00108400:
		ptr = "	K-BOT COMMUNICATIONS";
		break;
	case 0x00108500:
		ptr = "	POLARIS COMMUNICATIONS, INC.";
		break;
	case 0x00108600:
		ptr = "	ATTO TECHNOLOGY, INC.";
		break;
	case 0x00108700:
		ptr = "	Xstreamis PLC";
		break;
	case 0x00108800:
		ptr = "	AMERICAN NETWORKS INC.";
		break;
	case 0x00108900:
		ptr = "	WEBSONIC";
		break;
	case 0x00108A00:
		ptr = "	TERALOGIC, INC.";
		break;
	case 0x00108B00:
		ptr = "	LASERANIMATION SOLLINGER GMBH";
		break;
	case 0x00108C00:
		ptr = "	FUJITSU TELECOMMUNICATIONS";
		break;
	case 0x00108D00:
		ptr = "	JOHNSON CONTROLS, INC.";
		break;
	case 0x00108E00:
		ptr = "	HUGH SYMONS CONCEPT";
		break;
	case 0x00108F00:
		ptr = "	RAPTOR SYSTEMS";
		break;
	case 0x00109000:
		ptr = "	CIMETRICS, INC.";
		break;
	case 0x00109100:
		ptr = "	NO WIRES NEEDED BV";
		break;
	case 0x00109200:
		ptr = "	NETCORE INC.";
		break;
	case 0x00109300:
		ptr = "	CMS COMPUTERS, LTD.";
		break;
	case 0x00109400:
		ptr = "	ADTECH, INC.";
		break;
	case 0x00109500:
		ptr = "	THOMSON CONSUMER ELECTRONICS";
		break;
	case 0x00109600:
		ptr = "	TRACEWELL SYSTEMS, INC.";
		break;
	case 0x00109700:
		ptr = "	WINNET METROPOLITAN";
		break;
	case 0x00109800:
		ptr = "	STARNET TECHNOLOGIES, INC.";
		break;
	case 0x00109900:
		ptr = "	INNOMEDIA, INC.";
		break;
	case 0x00109A00:
		ptr = "	NETLINE";
		break;
	case 0x00109B00:
		ptr = "	VIXEL CORPORATION";
		break;
	case 0x00109C00:
		ptr = "	M-SYSTEM CO., LTD.";
		break;
	case 0x00109D00:
		ptr = "	CLARINET SYSTEMS, INC.";
		break;
	case 0x00109E00:
		ptr = "	AWARE, INC.";
		break;
	case 0x00109F00:
		ptr = "	PAVO, INC.";
		break;
	case 0x0010A000:
		ptr = "	INNOVEX TECHNOLOGIES, INC.";
		break;
	case 0x0010A100:
		ptr = "	KENDIN SEMICONDUCTOR, INC.";
		break;
	case 0x0010A200:
		ptr = "	TNS";
		break;
	case 0x0010A300:
		ptr = "	OMNITRONIX, INC.";
		break;
	case 0x0010A400:
		ptr = "	XIRCOM";
		break;
	case 0x0010A500:
		ptr = "	OXFORD INSTRUMENTS";
		break;
	case 0x0010A600:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x0010A700:
		ptr = "	UNEX TECHNOLOGY CORPORATION";
		break;
	case 0x0010A800:
		ptr = "	RELIANCE COMPUTER CORP.";
		break;
	case 0x0010A900:
		ptr = "	ADHOC TECHNOLOGIES";
		break;
	case 0x0010AA00:
		ptr = "	MEDIA4, INC.";
		break;
	case 0x0010AB00:
		ptr = "	KOITO INDUSTRIES, LTD.";
		break;
	case 0x0010AC00:
		ptr = "	IMCI TECHNOLOGIES";
		break;
	case 0x0010AD00:
		ptr = "	SOFTRONICS USB, INC.";
		break;
	case 0x0010AE00:
		ptr = "	SHINKO ELECTRIC INDUSTRIES CO.";
		break;
	case 0x0010AF00:
		ptr = "	TAC SYSTEMS, INC.";
		break;
	case 0x0010B000:
		ptr = "	MERIDIAN TECHNOLOGY CORP.";
		break;
	case 0x0010B100:
		ptr = "	FOR-A CO., LTD.";
		break;
	case 0x0010B200:
		ptr = "	COACTIVE AESTHETICS";
		break;
	case 0x0010B300:
		ptr = "	NOKIA MULTIMEDIA TERMINALS";
		break;
	case 0x0010B400:
		ptr = "	ATMOSPHERE NETWORKS";
		break;
	case 0x0010B500:
		ptr = "	ACCTON TECHNOLOGY CORPORATION";
		break;
	case 0x0010B600:
		ptr = "	ENTRATA COMMUNICATIONS CORP.";
		break;
	case 0x0010B700:
		ptr = "	COYOTE TECHNOLOGIES, LLC";
		break;
	case 0x0010B800:
		ptr = "	ISHIGAKI COMPUTER SYSTEM CO.";
		break;
	case 0x0010B900:
		ptr = "	MAXTOR CORP.";
		break;
	case 0x0010BA00:
		ptr = "	MARTINHO-DAVIS SYSTEMS, INC.";
		break;
	case 0x0010BB00:
		ptr = "	DATA & INFORMATION TECHNOLOGY";
		break;
	case 0x0010BC00:
		ptr = "	APTIS COMMUNICATIONS, INC.";
		break;
	case 0x0010BD00:
		ptr = "	THE TELECOMMUNICATION";
		break;
	case 0x0010BE00:
		ptr = "	TELEXIS CORP.";
		break;
	case 0x0010BF00:
		ptr = "	INTER AIR WIRELESS";
		break;
	case 0x0010C000:
		ptr = "	ARMA, INC.";
		break;
	case 0x0010C100:
		ptr = "	OI ELECTRIC CO., LTD.";
		break;
	case 0x0010C200:
		ptr = "	WILLNET, INC.";
		break;
	case 0x0010C300:
		ptr = "	CSI-CONTROL SYSTEMS";
		break;
	case 0x0010C400:
		ptr = "	MEDIA LINKS CO., LTD.";
		break;
	case 0x0010C500:
		ptr = "	PROTOCOL TECHNOLOGIES, INC.";
		break;
	case 0x0010C600:
		ptr = "	USI";
		break;
	case 0x0010C700:
		ptr = "	DATA TRANSMISSION NETWORK";
		break;
	case 0x0010C800:
		ptr = "	COMMUNICATIONS ELECTRONICS";
		break;
	case 0x0010C900:
		ptr = "	MITSUBISHI ELECTRONICS";
		break;
	case 0x0010CA00:
		ptr = "	INTEGRAL ACCESS";
		break;
	case 0x0010CB00:
		ptr = "	FACIT K.K.";
		break;
	case 0x0010CC00:
		ptr = "	CLP COMPUTER LOGISTIK";
		break;
	case 0x0010CD00:
		ptr = "	INTERFACE CONCEPT";
		break;
	case 0x0010CE00:
		ptr = "	VOLAMP, LTD.";
		break;
	case 0x0010CF00:
		ptr = "	FIBERLANE COMMUNICATIONS";
		break;
	case 0x0010D000:
		ptr = "	WITCOM, LTD.";
		break;
	case 0x0010D100:
		ptr = "	BLAZENET, INC.";
		break;
	case 0x0010D200:
		ptr = "	NITTO TSUSHINKI CO., LTD";
		break;
	case 0x0010D300:
		ptr = "	GRIPS ELECTRONIC GMBH";
		break;
	case 0x0010D400:
		ptr = "	STORAGE COMPUTER CORPORATION";
		break;
	case 0x0010D500:
		ptr = "	IMASDE CANARIAS, S.A.";
		break;
	case 0x0010D600:
		ptr = "	ITT A/CD";
		break;
	case 0x0010D700:
		ptr = "	ARGOSY RESEARCH INC.";
		break;
	case 0x0010D800:
		ptr = "	CALISTA";
		break;
	case 0x0010D900:
		ptr = "	IBM JAPAN, FUJISAWA MT+D";
		break;
	case 0x0010DA00:
		ptr = "	MOTION ENGINEERING, INC.";
		break;
	case 0x0010DB00:
		ptr = "	NETSCREEN TECHNOLOGIES, INC.";
		break;
	case 0x0010DC00:
		ptr = "	MICRO-STAR INTERNATIONAL";
		break;
	case 0x0010DD00:
		ptr = "	ENABLE SEMICONDUCTOR, INC.";
		break;
	case 0x0010DE00:
		ptr = "	INTERNATIONAL DATACASTING";
		break;
	case 0x0010DF00:
		ptr = "	RISE COMPUTER INC.";
		break;
	case 0x0010E000:
		ptr = "	COBALT MICROSERVER, INC.";
		break;
	case 0x0010E100:
		ptr = "	S.I. TECH, INC.";
		break;
	case 0x0010E200:
		ptr = "	ARRAYCOMM, INC.";
		break;
	case 0x0010E300:
		ptr = "	COMPAQ COMPUTER CORPORATION";
		break;
	case 0x0010E400:
		ptr = "	NSI CORPORATION";
		break;
	case 0x0010E500:
		ptr = "	SOLECTRON TEXAS";
		break;
	case 0x0010E600:
		ptr = "	APPLIED INTELLIGENT";
		break;
	case 0x0010E700:
		ptr = "	BREEZECOM";
		break;
	case 0x0010E800:
		ptr = "	TELOCITY, INCORPORATED";
		break;
	case 0x0010E900:
		ptr = "	RAIDTEC LTD.";
		break;
	case 0x0010EA00:
		ptr = "	ADEPT TECHNOLOGY";
		break;
	case 0x0010EB00:
		ptr = "	SELSIUS SYSTEMS, ILNC.";
		break;
	case 0x0010EC00:
		ptr = "	RPCG, LLC";
		break;
	case 0x0010ED00:
		ptr = "	SUNDANCE TECHNOLOGY, INC.";
		break;
	case 0x0010EE00:
		ptr = "	CTI PRODUCTS, INC.";
		break;
	case 0x0010EF00:
		ptr = "	DB NETWORKS, INC.";
		break;
	case 0x0010F000:
		ptr = "	RITTAL-WERK RUDOLF LOH";
		break;
	case 0x0010F100:
		ptr = "	I-O CORPORATION";
		break;
	case 0x0010F200:
		ptr = "	ANTEC";
		break;
	case 0x0010F300:
		ptr = "	NEXCOM INTERNATIONAL CO., LTD.";
		break;
	case 0x0010F400:
		ptr = "	VERTICAL NETWORKS, INC.";
		break;
	case 0x0010F500:
		ptr = "	AMHERST SYSTEMS, INC.";
		break;
	case 0x0010F600:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x0010F700:
		ptr = "	IRIICHI TECHNOLOGIES";
		break;
	case 0x0010F800:
		ptr = "	KENWOOD TMI CORPORATION";
		break;
	case 0x0010F900:
		ptr = "	UNIQUE SYSTEMS, INC.";
		break;
	case 0x0010FA00:
		ptr = "	ZAYANTE, INC.";
		break;
	case 0x0010FB00:
		ptr = "	ZIDA TECHNOLOGIES LIMITED";
		break;
	case 0x0010FC00:
		ptr = "	BROADBAND NETWORKS, INC.";
		break;
	case 0x0010FD00:
		ptr = "	COCOM A/S";
		break;
	case 0x0010FE00:
		ptr = "	DIGITAL EQUIPMENT CORPORATION";
		break;
	case 0x0010FF00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x001C7C00:
		ptr = "	PERQ SYSTEMS CORPORATION";
		break;
	case 0x00200000:
		ptr = "	LEXMARK INTERNATIONAL, INC.";
		break;
	case 0x00200100:
		ptr = "	DSP SOLUTIONS, INC.";
		break;
	case 0x00200200:
		ptr = "	SERITECH ENTERPRISE CO., LTD.";
		break;
	case 0x00200300:
		ptr = "	PIXEL POWER LTD.";
		break;
	case 0x00200400:
		ptr = "	YAMATAKE-HONEYWELL CO., LTD.";
		break;
	case 0x00200500:
		ptr = "	SIMPLE TECHNOLOGY";
		break;
	case 0x00200600:
		ptr = "	GARRETT COMMUNICATIONS, INC.";
		break;
	case 0x00200700:
		ptr = "	SFA, INC.";
		break;
	case 0x00200800:
		ptr = "	CABLE & COMPUTER TECHNOLOGY";
		break;
	case 0x00200900:
		ptr = "	PACKARD BELL ELEC., INC.";
		break;
	case 0x00200A00:
		ptr = "	SOURCE-COMM CORP.";
		break;
	case 0x00200B00:
		ptr = "	OCTAGON SYSTEMS CORP.";
		break;
	case 0x00200C00:
		ptr = "	ADASTRA SYSTEMS CORP.";
		break;
	case 0x00200D00:
		ptr = "	CARL ZEISS";
		break;
	case 0x00200E00:
		ptr = "	SATELLITE TECHNOLOGY MGMT, INC";
		break;
	case 0x00200F00:
		ptr = "	TANBAC CO., LTD.";
		break;
	case 0x00201000:
		ptr = "	JEOL SYSTEM TECHNOLOGY CO. LTD";
		break;
	case 0x00201100:
		ptr = "	CANOPUS CO., LTD.";
		break;
	case 0x00201200:
		ptr = "	CAMTRONICS MEDICAL SYSTEMS";
		break;
	case 0x00201300:
		ptr = "	DIVERSIFIED TECHNOLOGY, INC.";
		break;
	case 0x00201400:
		ptr = "	GLOBAL VIEW CO., LTD.";
		break;
	case 0x00201500:
		ptr = "	ACTIS COMPUTER SA";
		break;
	case 0x00201600:
		ptr = "	SHOWA ELECTRIC WIRE & CABLE CO";
		break;
	case 0x00201700:
		ptr = "	ORBOTECH";
		break;
	case 0x00201800:
		ptr = "	CIS TECHNOLOGY INC.";
		break;
	case 0x00201900:
		ptr = "	OHLER GMBH";
		break;
	case 0x00201A00:
		ptr = "	N-BASE SWITCH COMMUNICATIONS";
		break;
	case 0x00201B00:
		ptr = "	NORTHERN TELECOM/NETWORK";
		break;
	case 0x00201C00:
		ptr = "	EXCEL, INC.";
		break;
	case 0x00201D00:
		ptr = "	KATANA PRODUCTS";
		break;
	case 0x00201E00:
		ptr = "	NETQUEST CORPORATION";
		break;
	case 0x00201F00:
		ptr = "	BEST POWER TECHNOLOGY, INC.";
		break;
	case 0x00202000:
		ptr = "	MEGATRON COMPUTER INDUSTRIES";
		break;
	case 0x00202100:
		ptr = "	ALGORITHMS SOFTWARE PVT. LTD.";
		break;
	case 0x00202200:
		ptr = "	TEKNIQUE, INC.";
		break;
	case 0x00202300:
		ptr = "	T.C. TECHNOLOGIES PTY. LTD";
		break;
	case 0x00202400:
		ptr = "	PACIFIC COMMUNICATION SCIENCES";
		break;
	case 0x00202500:
		ptr = "	CONTROL TECHNOLOGY, INC.";
		break;
	case 0x00202600:
		ptr = "	AMKLY SYSTEMS, INC.";
		break;
	case 0x00202700:
		ptr = "	MING FORTUNE INDUSTRY CO., LTD";
		break;
	case 0x00202800:
		ptr = "	WEST EGG SYSTEMS, INC.";
		break;
	case 0x00202900:
		ptr = "	TELEPROCESSING PRODUCTS, INC.";
		break;
	case 0x00202A00:
		ptr = "	N.V. DZINE";
		break;
	case 0x00202B00:
		ptr = "	ADVANCED TELECOMMUNICATIONS";
		break;
	case 0x00202C00:
		ptr = "	WELLTRONIX CO., LTD.";
		break;
	case 0x00202D00:
		ptr = "	TAIYO CORPORATION";
		break;
	case 0x00202E00:
		ptr = "	DAYSTAR DIGITAL";
		break;
	case 0x00202F00:
		ptr = "	ZETA COMMUNICATIONS, LTD.";
		break;
	case 0x00203000:
		ptr = "	ANALOG & DIGITAL SYSTEMS";
		break;
	case 0x00203100:
		ptr = "	ERTEC GMBH";
		break;
	case 0x00203200:
		ptr = "	ALCATEL TAISEL";
		break;
	case 0x00203300:
		ptr = "	SYNAPSE TECHNOLOGIES, INC.";
		break;
	case 0x00203400:
		ptr = "	ROTEC INDUSTRIEAUTOMATION GMBH";
		break;
	case 0x00203500:
		ptr = "	IBM CORPORATION";
		break;
	case 0x00203600:
		ptr = "	BMC SOFTWARE";
		break;
	case 0x00203700:
		ptr = "	SEAGATE TECHNOLOGY";
		break;
	case 0x00203800:
		ptr = "	VME MICROSYSTEMS INTERNATIONAL";
		break;
	case 0x00203900:
		ptr = "	SCINETS";
		break;
	case 0x00203A00:
		ptr = "	DIGITAL BI0METRICS INC.";
		break;
	case 0x00203B00:
		ptr = "	WISDM LTD.";
		break;
	case 0x00203C00:
		ptr = "	EUROTIME AB";
		break;
	case 0x00203D00:
		ptr = "	NOVAR ELECTRONICS CORPORATION";
		break;
	case 0x00203E00:
		ptr = "	LOGICAN TECHNOLOGIES, INC.";
		break;
	case 0x00203F00:
		ptr = "	JUKI CORPORATION";
		break;
	case 0x00204000:
		ptr = "	GENERAL INSTRUMENT CORPORATION";
		break;
	case 0x00204100:
		ptr = "	DATA NET";
		break;
	case 0x00204200:
		ptr = "	DATAMETRICS CORP.";
		break;
	case 0x00204300:
		ptr = "	NEURON COMPANY LIMITED";
		break;
	case 0x00204400:
		ptr = "	GENITECH PTY LTD";
		break;
	case 0x00204500:
		ptr = "	SOLCOM SYSTEMS, LTD.";
		break;
	case 0x00204600:
		ptr = "	CIPRICO, INC.";
		break;
	case 0x00204700:
		ptr = "	STEINBRECHER CORP.";
		break;
	case 0x00204800:
		ptr = "	FORE SYSTEMS, INC.";
		break;
	case 0x00204900:
		ptr = "	COMTRON, INC.";
		break;
	case 0x00204A00:
		ptr = "	PRONET GMBH";
		break;
	case 0x00204B00:
		ptr = "	AUTOCOMPUTER CO., LTD.";
		break;
	case 0x00204C00:
		ptr = "	MITRON COMPUTER PTE LTD.";
		break;
	case 0x00204D00:
		ptr = "	INOVIS GMBH";
		break;
	case 0x00204E00:
		ptr = "	NETWORK SECURITY SYSTEMS, INC.";
		break;
	case 0x00204F00:
		ptr = "	DEUTSCHE AEROSPACE AG";
		break;
	case 0x00205000:
		ptr = "	KOREA COMPUTER INC.";
		break;
	case 0x00205100:
		ptr = "	PHOENIX DATA COMMUNUNICATIONS";
		break;
	case 0x00205200:
		ptr = "	RAGULA SYSTEMS";
		break;
	case 0x00205300:
		ptr = "	HUNTSVILLE MICROSYSTEMS, INC.";
		break;
	case 0x00205400:
		ptr = "	EASTERN RESEARCH, INC.";
		break;
	case 0x00205500:
		ptr = "	ALTECH CO., LTD.";
		break;
	case 0x00205600:
		ptr = "	NEOPRODUCTS";
		break;
	case 0x00205700:
		ptr = "	TITZE DATENTECHNIK GMBH";
		break;
	case 0x00205800:
		ptr = "	ALLIED SIGNAL INC.";
		break;
	case 0x00205900:
		ptr = "	MIRO COMPUTER PRODUCTS AG";
		break;
	case 0x00205A00:
		ptr = "	COMPUTER IDENTICS";
		break;
	case 0x00205B00:
		ptr = "	SKYLINE TECHNOLOGY";
		break;
	case 0x00205C00:
		ptr = "	INTERNET SYSTEMS/ FLORIDA INC.";
		break;
	case 0x00205D00:
		ptr = "	NANOMATIC OY";
		break;
	case 0x00205E00:
		ptr = "	CASTLE ROCK, INC.";
		break;
	case 0x00205F00:
		ptr = "	GAMMADATA COMPUTER GMBH";
		break;
	case 0x00206000:
		ptr = "	ALCATEL ITALIA S.P.A.";
		break;
	case 0x00206100:
		ptr = "	DYNATECH COMMUNICATIONS, INC.";
		break;
	case 0x00206200:
		ptr = "	SCORPION LOGIC, LTD.";
		break;
	case 0x00206300:
		ptr = "	WIPRO INFOTECH LTD.";
		break;
	case 0x00206400:
		ptr = "	PROTEC MICROSYSTEMS, INC.";
		break;
	case 0x00206500:
		ptr = "	SUPERNET NETWORKING INC.";
		break;
	case 0x00206600:
		ptr = "	GENERAL MAGIC, INC.";
		break;
	case 0x00206800:
		ptr = "	ISDYNE";
		break;
	case 0x00206900:
		ptr = "	ISDN SYSTEMS CORPORATION";
		break;
	case 0x00206A00:
		ptr = "	OSAKA COMPUTER CORP.";
		break;
	case 0x00206B00:
		ptr = "	MINOLTA CO., LTD.";
		break;
	case 0x00206C00:
		ptr = "	EVERGREEN TECHNOLOGY CORP.";
		break;
	case 0x00206D00:
		ptr = "	DATA RACE, INC.";
		break;
	case 0x00206E00:
		ptr = "	XACT, INC.";
		break;
	case 0x00206F00:
		ptr = "	FLOWPOINT CORPORATION";
		break;
	case 0x00207000:
		ptr = "	HYNET, LTD.";
		break;
	case 0x00207100:
		ptr = "	IBR GMBH";
		break;
	case 0x00207200:
		ptr = "	WORKLINK INNOVATIONS";
		break;
	case 0x00207300:
		ptr = "	FUSION SYSTEMS CORPORATION";
		break;
	case 0x00207400:
		ptr = "	SUNGWOON SYSTEMS";
		break;
	case 0x00207500:
		ptr = "	MOTOROLA COMMUNICATION ISRAEL";
		break;
	case 0x00207600:
		ptr = "	REUDO CORPORATION";
		break;
	case 0x00207700:
		ptr = "	KARDIOS SYSTEMS CORP.";
		break;
	case 0x00207800:
		ptr = "	RUNTOP, INC.";
		break;
	case 0x00207900:
		ptr = "	MIKRON GMBH";
		break;
	case 0x00207A00:
		ptr = "	WISE COMMUNICATIONS, INC.";
		break;
	case 0x00207B00:
		ptr = "	LEVEL ONE COMMUNICATIONS";
		break;
	case 0x00207C00:
		ptr = "	AUTEC GMBH";
		break;
	case 0x00207D00:
		ptr = "	ADVANCED COMPUTER APPLICATIONS";
		break;
	case 0x00207E00:
		ptr = "	FINECOM CO., LTD.";
		break;
	case 0x00207F00:
		ptr = "	KYOEI SANGYO CO., LTD.";
		break;
	case 0x00208000:
		ptr = "	SYNERGY (UK) LTD.";
		break;
	case 0x00208100:
		ptr = "	TITAN ELECTRONICS";
		break;
	case 0x00208200:
		ptr = "	ONEAC CORPORATION";
		break;
	case 0x00208300:
		ptr = "	PRESTICOM INCORPORATED";
		break;
	case 0x00208400:
		ptr = "	OCE PRINTING SYSTEMS, GMBH";
		break;
	case 0x00208500:
		ptr = "	EXIDE ELECTRONICS";
		break;
	case 0x00208600:
		ptr = "	MICROTECH ELECTRONICS LIMITED";
		break;
	case 0x00208700:
		ptr = "	MEMOTEC COMMUNICATIONS CORP.";
		break;
	case 0x00208800:
		ptr = "	GLOBAL VILLAGE COMMUNICATION";
		break;
	case 0x00208900:
		ptr = "	T3PLUS NETWORKING, INC.";
		break;
	case 0x00208A00:
		ptr = "	SONIX COMMUNICATIONS, LTD.";
		break;
	case 0x00208B00:
		ptr = "	LAPIS TECHNOLOGIES, INC.";
		break;
	case 0x00208C00:
		ptr = "	GALAXY NETWORKS, INC.";
		break;
	case 0x00208D00:
		ptr = "	CMD TECHNOLOGY";
		break;
	case 0x00208E00:
		ptr = "	CHEVIN SOFTWARE ENG. LTD.";
		break;
	case 0x00208F00:
		ptr = "	ECI TELECOM LTD.";
		break;
	case 0x00209000:
		ptr = "	ADVANCED COMPRESSION";
		break;
	case 0x00209100:
		ptr = "	J125, NATIONAL SECURITY AGENCY";
		break;
	case 0x00209200:
		ptr = "	CHESS ENGINEERING B.V.";
		break;
	case 0x00209300:
		ptr = "	LANDINGS TECHNOLOGY CORP.";
		break;
	case 0x00209400:
		ptr = "	CUBIX CORPORATION";
		break;
	case 0x00209500:
		ptr = "	RIVA ELECTRONICS";
		break;
	case 0x00209600:
		ptr = "	SIEBE ENVIRONMENTAL CONTROLS";
		break;
	case 0x00209700:
		ptr = "	APPLIED SIGNAL TECHNOLOGY";
		break;
	case 0x00209800:
		ptr = "	HECTRONIC AB";
		break;
	case 0x00209900:
		ptr = "	BON ELECTRIC CO., LTD.";
		break;
	case 0x00209A00:
		ptr = "	THE 3DO COMPANY";
		break;
	case 0x00209B00:
		ptr = "	ERSAT ELECTRONIC GMBH";
		break;
	case 0x00209C00:
		ptr = "	PRIMARY ACCESS CORP.";
		break;
	case 0x00209D00:
		ptr = "	LIPPERT AUTOMATIONSTECHNIK";
		break;
	case 0x00209E00:
		ptr = "	BROWN'S OPERATING SYSTEM";
		break;
	case 0x00209F00:
		ptr = "	MERCURY COMPUTER SYSTEMS, INC.";
		break;
	case 0x0020A000:
		ptr = "	OA LABORATORY CO., LTD.";
		break;
	case 0x0020A100:
		ptr = "	DOVATRON";
		break;
	case 0x0020A200:
		ptr = "	GALCOM NETWORKING LTD.";
		break;
	case 0x0020A300:
		ptr = "	DIVICOM INC.";
		break;
	case 0x0020A400:
		ptr = "	MULTIPOINT NETWORKS";
		break;
	case 0x0020A500:
		ptr = "	API ENGINEERING";
		break;
	case 0x0020A600:
		ptr = "	PROXIM, INC.";
		break;
	case 0x0020A700:
		ptr = "	PAIRGAIN TECHNOLOGIES, INC.";
		break;
	case 0x0020A800:
		ptr = "	SAST TECHNOLOGY CORP.";
		break;
	case 0x0020A900:
		ptr = "	WHITE HORSE INDUSTRIAL";
		break;
	case 0x0020AA00:
		ptr = "	DIGIMEDIA VISION LTD.";
		break;
	case 0x0020AB00:
		ptr = "	MICRO INDUSTRIES CORP.";
		break;
	case 0x0020AC00:
		ptr = "	INTERFLEX DATENSYSTEME GMBH";
		break;
	case 0x0020AD00:
		ptr = "	LINQ SYSTEMS";
		break;
	case 0x0020AE00:
		ptr = "	ORNET DATA COMMUNICATION TECH.";
		break;
	case 0x0020AF00:
		ptr = "	3COM CORPORATION";
		break;
	case 0x0020B000:
		ptr = "	GATEWAY DEVICES, INC.";
		break;
	case 0x0020B100:
		ptr = "	COMTECH RESEARCH INC.";
		break;
	case 0x0020B200:
		ptr = "	GKD GESELLSCHAFT FUR";
		break;
	case 0x0020B300:
		ptr = "	SCLTEC COMMUNICATIONS SYSTEMS";
		break;
	case 0x0020B400:
		ptr = "	TERMA ELEKTRONIK AS";
		break;
	case 0x0020B500:
		ptr = "	YASKAWA ELECTRIC CORPORATION";
		break;
	case 0x0020B600:
		ptr = "	AGILE NETWORKS, INC.";
		break;
	case 0x0020B700:
		ptr = "	NAMAQUA COMPUTERWARE";
		break;
	case 0x0020B800:
		ptr = "	PRIME OPTION, INC.";
		break;
	case 0x0020B900:
		ptr = "	METRICOM, INC.";
		break;
	case 0x0020BA00:
		ptr = "	CENTER FOR HIGH PERFORMANCE";
		break;
	case 0x0020BB00:
		ptr = "	ZAX CORPORATION";
		break;
	case 0x0020BC00:
		ptr = "	JTEC PTY LTD.";
		break;
	case 0x0020BD00:
		ptr = "	NIOBRARA R & D CORPORATION";
		break;
	case 0x0020BE00:
		ptr = "	LAN ACCESS CORP.";
		break;
	case 0x0020BF00:
		ptr = "	AEHR TEST SYSTEMS";
		break;
	case 0x0020C000:
		ptr = "	PULSE ELECTRONICS, INC.";
		break;
	case 0x0020C100:
		ptr = "	TAIKO ELECTRIC WORKS, LTD.";
		break;
	case 0x0020C200:
		ptr = "	TEXAS MEMORY SYSTEMS, INC.";
		break;
	case 0x0020C300:
		ptr = "	COUNTER SOLUTIONS LTD.";
		break;
	case 0x0020C400:
		ptr = "	INET,INC.";
		break;
	case 0x0020C500:
		ptr = "	EAGLE TECHNOLOGY";
		break;
	case 0x0020C600:
		ptr = "	NECTEC";
		break;
	case 0x0020C700:
		ptr = "	AKAI Professional M.I. Corp.";
		break;
	case 0x0020C800:
		ptr = "	LARSCOM INCORPORATED";
		break;
	case 0x0020C900:
		ptr = "	VICTRON BV";
		break;
	case 0x0020CA00:
		ptr = "	DIGITAL OCEAN";
		break;
	case 0x0020CB00:
		ptr = "	PRETEC ELECTRONICS CORP.";
		break;
	case 0x0020CC00:
		ptr = "	DIGITAL SERVICES, LTD.";
		break;
	case 0x0020CD00:
		ptr = "	HYBRID NETWORKS, INC.";
		break;
	case 0x0020CE00:
		ptr = "	LOGICAL DESIGN GROUP, INC.";
		break;
	case 0x0020CF00:
		ptr = "	TEST & MEASUREMENT SYSTEMS INC";
		break;
	case 0x0020D000:
		ptr = "	VERSALYNX CORPORATION";
		break;
	case 0x0020D100:
		ptr = "	MICROCOMPUTER SYSTEMS (M) SDN.";
		break;
	case 0x0020D200:
		ptr = "	RAD DATA COMMUNICATIONS, LTD.";
		break;
	case 0x0020D300:
		ptr = "	OST (OUEST STANDARD TELEMATIQU";
		break;
	case 0x0020D400:
		ptr = "	CABLETRON - ZEITTNET INC.";
		break;
	case 0x0020D500:
		ptr = "	VIPA GMBH";
		break;
	case 0x0020D600:
		ptr = "	BREEZECOM";
		break;
	case 0x0020D700:
		ptr = "	JAPAN MINICOMPUTER SYSTEMS CO.";
		break;
	case 0x0020D800:
		ptr = "	NETWAVE TECHNOLOGIES, INC.";
		break;
	case 0x0020D900:
		ptr = "	PANASONIC TECHNOLOGIES, INC./";
		break;
	case 0x0020DA00:
		ptr = "	XYLAN CORPORATION";
		break;
	case 0x0020DB00:
		ptr = "	XNET TECHNOLOGY, INC.";
		break;
	case 0x0020DC00:
		ptr = "	DENSITRON TAIWAN LTD.";
		break;
	case 0x0020DD00:
		ptr = "	AWA LTD.";
		break;
	case 0x0020DE00:
		ptr = "	JAPAN DIGITAL LABORAT'Y CO.LTD";
		break;
	case 0x0020DF00:
		ptr = "	KYOSAN ELECTRIC MFG. CO., LTD.";
		break;
	case 0x0020E000:
		ptr = "	PREMAX ELECTRONICS, INC.";
		break;
	case 0x0020E100:
		ptr = "	ALAMAR ELECTRONICS";
		break;
	case 0x0020E200:
		ptr = "	INFORMATION RESOURCE";
		break;
	case 0x0020E300:
		ptr = "	MCD KENCOM CORPORATION";
		break;
	case 0x0020E400:
		ptr = "	HSING TECH ENTERPRISE CO., LTD";
		break;
	case 0x0020E500:
		ptr = "	APEX DATA, INC.";
		break;
	case 0x0020E600:
		ptr = "	LIDKOPING MACHINE TOOLS AB";
		break;
	case 0x0020E700:
		ptr = "	B&W NUCLEAR SERVICE COMPANY";
		break;
	case 0x0020E800:
		ptr = "	DATATREK CORPORATION";
		break;
	case 0x0020E900:
		ptr = "	DANTEL";
		break;
	case 0x0020EA00:
		ptr = "	EFFICIENT NETWORKS, INC.";
		break;
	case 0x0020EB00:
		ptr = "	CINCINNATI MICROWAVE, INC.";
		break;
	case 0x0020EC00:
		ptr = "	TECHWARE SYSTEMS CORP.";
		break;
	case 0x0020ED00:
		ptr = "	GIGA-BYTE TECHNOLOGY CO., LTD.";
		break;
	case 0x0020EE00:
		ptr = "	GTECH CORPORATION";
		break;
	case 0x0020EF00:
		ptr = "	USC CORPORATION";
		break;
	case 0x0020F000:
		ptr = "	UNIVERSAL MICROELECTRONICS CO.";
		break;
	case 0x0020F100:
		ptr = "	ALTOS INDIA LIMITED";
		break;
	case 0x0020F200:
		ptr = "	SUN MICROSYSTEMS, INC.";
		break;
	case 0x0020F300:
		ptr = "	RAYNET CORPORATION";
		break;
	case 0x0020F400:
		ptr = "	SPECTRIX CORPORATION";
		break;
	case 0x0020F500:
		ptr = "	PANDATEL AG";
		break;
	case 0x0020F600:
		ptr = "	NET TEK  AND KARLNET, INC.";
		break;
	case 0x0020F700:
		ptr = "	CYBERDATA";
		break;
	case 0x0020F800:
		ptr = "	CARRERA COMPUTERS, INC.";
		break;
	case 0x0020F900:
		ptr = "	PARALINK NETWORKS, INC.";
		break;
	case 0x0020FA00:
		ptr = "	GDE SYSTEMS, INC.";
		break;
	case 0x0020FB00:
		ptr = "	OCTEL COMMUNICATIONS CORP.";
		break;
	case 0x0020FC00:
		ptr = "	MATROX";
		break;
	case 0x0020FD00:
		ptr = "	ITV TECHNOLOGIES, INC.";
		break;
	case 0x0020FE00:
		ptr = "	TOPWARE INC. / GRAND COMPUTER";
		break;
	case 0x0020FF00:
		ptr = "	SYMMETRICAL TECHNOLOGIES";
		break;
	case 0x00300000:
		ptr = "	ALLWELL TECHNOLOGY CORP.";
		break;
	case 0x00300100:
		ptr = "	SMP";
		break;
	case 0x00300200:
		ptr = "	Expand Networks";
		break;
	case 0x00300300:
		ptr = "	Phasys Ltd.";
		break;
	case 0x00300400:
		ptr = "	LEADTEK RESEARCH INC.";
		break;
	case 0x00300500:
		ptr = "	Fujitsu Siemens Computers";
		break;
	case 0x00300600:
		ptr = "	SUPERPOWER COMPUTER";
		break;
	case 0x00300700:
		ptr = "	OPTI, INC.";
		break;
	case 0x00300800:
		ptr = "	AVIO DIGITAL, INC.";
		break;
	case 0x00300900:
		ptr = "	Tachion Networks, Inc.";
		break;
	case 0x00300A00:
		ptr = "	AZTECH SYSTEMS LTD.";
		break;
	case 0x00300B00:
		ptr = "	mPHASE Technologies, Inc.";
		break;
	case 0x00300C00:
		ptr = "	CONGRUENCY, LTD.";
		break;
	case 0x00300D00:
		ptr = "	MMC Technology, Inc.";
		break;
	case 0x00300E00:
		ptr = "	Klotz Digital AG";
		break;
	case 0x00300F00:
		ptr = "	IMT - Information Management T";
		break;
	case 0x00301000:
		ptr = "	VISIONETICS INTERNATIONAL";
		break;
	case 0x00301100:
		ptr = "	HMS FIELDBUS SYSTEMS AB";
		break;
	case 0x00301200:
		ptr = "	DIGITAL ENGINEERING LTD.";
		break;
	case 0x00301300:
		ptr = "	NEC Corporation";
		break;
	case 0x00301400:
		ptr = "	DIVIO, INC.";
		break;
	case 0x00301500:
		ptr = "	CP CLARE CORP.";
		break;
	case 0x00301600:
		ptr = "	ISHIDA CO., LTD.";
		break;
	case 0x00301700:
		ptr = "	TERASTACK LTD.";
		break;
	case 0x00301800:
		ptr = "	Jetway Information Co., Ltd.";
		break;
	case 0x00301900:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00301A00:
		ptr = "	SMARTBRIDGES PTE. LTD.";
		break;
	case 0x00301B00:
		ptr = "	SHUTTLE, INC.";
		break;
	case 0x00301C00:
		ptr = "	ALTVATER AIRDATA SYSTEMS";
		break;
	case 0x00301D00:
		ptr = "	SKYSTREAM, INC.";
		break;
	case 0x00301E00:
		ptr = "	3COM Europe Ltd.";
		break;
	case 0x00301F00:
		ptr = "	OPTICAL NETWORKS, INC.";
		break;
	case 0x00302000:
		ptr = "	TSI, Inc..";
		break;
	case 0x00302100:
		ptr = "	HSING TECH. ENTERPRISE CO.,LTD";
		break;
	case 0x00302200:
		ptr = "	Fong Kai Industrial Co., Ltd.";
		break;
	case 0x00302300:
		ptr = "	COGENT COMPUTER SYSTEMS, INC.";
		break;
	case 0x00302400:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00302500:
		ptr = "	CHECKOUT COMPUTER SYSTEMS, LTD";
		break;
	case 0x00302600:
		ptr = "	HEITEL";
		break;
	case 0x00302700:
		ptr = "	KERBANGO, INC.";
		break;
	case 0x00302800:
		ptr = "	FASE Saldatura srl";
		break;
	case 0x00302900:
		ptr = "	OPICOM";
		break;
	case 0x00302A00:
		ptr = "	SOUTHERN INFORMATION";
		break;
	case 0x00302B00:
		ptr = "	INALP NETWORKS, INC.";
		break;
	case 0x00302C00:
		ptr = "	SYLANTRO SYSTEMS CORPORATION";
		break;
	case 0x00302D00:
		ptr = "	QUANTUM BRIDGE COMMUNICATIONS";
		break;
	case 0x00302E00:
		ptr = "	Hoft & Wessel AG";
		break;
	case 0x00302F00:
		ptr = "	Smiths Industries";
		break;
	case 0x00303000:
		ptr = "	HARMONIX CORPORATION";
		break;
	case 0x00303100:
		ptr = "	LIGHTWAVE COMMUNICATIONS, INC.";
		break;
	case 0x00303200:
		ptr = "	MAGICRAM, INC.";
		break;
	case 0x00303300:
		ptr = "	ORIENT TELECOM CO., LTD.";
		break;
	case 0x00303600:
		ptr = "	RMP ELEKTRONIKSYSTEME GMBH";
		break;
	case 0x00303700:
		ptr = "	Packard Bell Nec Services";
		break;
	case 0x00303800:
		ptr = "	XCP, INC.";
		break;
	case 0x00303900:
		ptr = "	SOFTBOOK PRESS";
		break;
	case 0x00303A00:
		ptr = "	MAATEL";
		break;
	case 0x00303B00:
		ptr = "	PowerCom Technology";
		break;
	case 0x00303C00:
		ptr = "	ONNTO CORP.";
		break;
	case 0x00303D00:
		ptr = "	IVA CORPORATION";
		break;
	case 0x00303E00:
		ptr = "	Radcom Ltd.";
		break;
	case 0x00303F00:
		ptr = "	TurboComm Tech Inc.";
		break;
	case 0x00304000:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00304100:
		ptr = "	SAEJIN T & M CO., LTD.";
		break;
	case 0x00304200:
		ptr = "	DeTeWe-Deutsche Telephonwerke";
		break;
	case 0x00304300:
		ptr = "	IDREAM TECHNOLOGIES, PTE. LTD.";
		break;
	case 0x00304400:
		ptr = "	Portsmith LLC";
		break;
	case 0x00304500:
		ptr = "	Village Networks, Inc. (VNI)";
		break;
	case 0x00304600:
		ptr = "	Controlled Electronic Manageme";
		break;
	case 0x00304700:
		ptr = "	NISSEI ELECTRIC CO., LTD.";
		break;
	case 0x00304800:
		ptr = "	Supermicro Computer, Inc.";
		break;
	case 0x00304900:
		ptr = "	BRYANT TECHNOLOGY, LTD.";
		break;
	case 0x00304A00:
		ptr = "	FRAUNHOFER INSTITUTE IMS";
		break;
	case 0x00304B00:
		ptr = "	ORBACOM SYSTEMS, INC.";
		break;
	case 0x00304C00:
		ptr = "	APPIAN COMMUNICATIONS, INC.";
		break;
	case 0x00304D00:
		ptr = "	ESI";
		break;
	case 0x00304E00:
		ptr = "	BUSTEC PRODUCTION LTD.";
		break;
	case 0x00304F00:
		ptr = "	PLANET Technology Corporation";
		break;
	case 0x00305000:
		ptr = "	Versa Technology";
		break;
	case 0x00305100:
		ptr = "	ORBIT AVIONIC & COMMUNICATION";
		break;
	case 0x00305200:
		ptr = "	ELASTIC NETWORKS";
		break;
	case 0x00305300:
		ptr = "	Basler AG";
		break;
	case 0x00305400:
		ptr = "	CASTLENET TECHNOLOGY, INC.";
		break;
	case 0x00305500:
		ptr = "	Hitachi Semiconductor America,";
		break;
	case 0x00305600:
		ptr = "	Beck IPC GmbH";
		break;
	case 0x00305700:
		ptr = "	E-Tel Corporation";
		break;
	case 0x00305800:
		ptr = "	API MOTION";
		break;
	case 0x00305900:
		ptr = "	DIGITAL-LOGIC AG";
		break;
	case 0x00305A00:
		ptr = "	TELGEN CORPORATION";
		break;
	case 0x00305B00:
		ptr = "	MODULE DEPARTMENT";
		break;
	case 0x00305C00:
		ptr = "	SMAR Laboratories Corp.";
		break;
	case 0x00305D00:
		ptr = "	DIGITRA SYSTEMS, INC.";
		break;
	case 0x00305E00:
		ptr = "	Abelko Innovation";
		break;
	case 0x00305F00:
		ptr = "	IMACON APS";
		break;
	case 0x00306000:
		ptr = "	STARMATIX, INC.";
		break;
	case 0x00306100:
		ptr = "	MobyTEL";
		break;
	case 0x00306200:
		ptr = "	PATH 1 NETWORK TECHNOL'S INC.";
		break;
	case 0x00306300:
		ptr = "	SANTERA SYSTEMS, INC.";
		break;
	case 0x00306400:
		ptr = "	ADLINK TECHNOLOGY, INC.";
		break;
	case 0x00306500:
		ptr = "	APPLE COMPUTER, INC.";
		break;
	case 0x00306600:
		ptr = "	DIGITAL WIRELESS CORPORATION";
		break;
	case 0x00306700:
		ptr = "	BIOSTAR MICROTECH INT'L CORP.";
		break;
	case 0x00306800:
		ptr = "	CYBERNETICS TECH. CO., LTD.";
		break;
	case 0x00306900:
		ptr = "	IMPACCT TECHNOLOGY CORP.";
		break;
	case 0x00306A00:
		ptr = "	PENTA MEDIA CO., LTD.";
		break;
	case 0x00306B00:
		ptr = "	CMOS SYSTEMS, INC.";
		break;
	case 0x00306C00:
		ptr = "	Hitex Holding GmbH";
		break;
	case 0x00306D00:
		ptr = "	LUCENT TECHNOLOGIES";
		break;
	case 0x00306E00:
		ptr = "	HEWLETT PACKARD";
		break;
	case 0x00306F00:
		ptr = "	SEYEON TECH. CO., LTD.";
		break;
	case 0x00307000:
		ptr = "	1Net Corporation";
		break;
	case 0x00307100:
		ptr = "	Cisco Systems, Inc.";
		break;
	case 0x00307200:
		ptr = "	INTELLIBYTE INC.";
		break;
	case 0x00307300:
		ptr = "	International Microsystems, In";
		break;
	case 0x00307400:
		ptr = "	EQUIINET LTD.";
		break;
	case 0x00307500:
		ptr = "	ADTECH";
		break;
	case 0x00307600:
		ptr = "	N-CUBED.NET";
		break;
	case 0x00307700:
		ptr = "	ONPREM NETWORKS";
		break;
	case 0x00307800:
		ptr = "	Cisco Systems, Inc.";
		break;
	case 0x00307900:
		ptr = "	CQOS, INC.";
		break;
	case 0x00307A00:
		ptr = "	Advanced Technology & Systems";
		break;
	case 0x00307B00:
		ptr = "	Cisco Systems, Inc.";
		break;
	case 0x00307C00:
		ptr = "	ADID SA";
		break;
	case 0x00307D00:
		ptr = "	GRE AMERICA, INC.";
		break;
	case 0x00307E00:
		ptr = "	Redflex Communication Systems";
		break;
	case 0x00307F00:
		ptr = "	IRLAN LTD.";
		break;
	case 0x00308000:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00308100:
		ptr = "	ALTOS C&C";
		break;
	case 0x00308200:
		ptr = "	TAIHAN ELECTRIC WIRE CO., LTD.";
		break;
	case 0x00308300:
		ptr = "	VEDIA TECHNOLOGY, LTD.";
		break;
	case 0x00308400:
		ptr = "	ALLIED TELESYN INTERNAIONAL";
		break;
	case 0x00308500:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00308600:
		ptr = "	Transistor Devices, Inc.";
		break;
	case 0x00308700:
		ptr = "	VEGA GRIESHABER KG";
		break;
	case 0x00308800:
		ptr = "	Siara Systems, Inc.";
		break;
	case 0x00308900:
		ptr = "	Spectrapoint Wireless, LLC";
		break;
	case 0x00308A00:
		ptr = "	NICOTRA SISTEMI S.P.A";
		break;
	case 0x00308B00:
		ptr = "	Brix Networks";
		break;
	case 0x00308C00:
		ptr = "	ADVANCED DIGITAL INFORMATION";
		break;
	case 0x00308D00:
		ptr = "	PINNACLE SYSTEMS, INC.";
		break;
	case 0x00308E00:
		ptr = "	CROSS MATCH TECHNOLOGIES, INC.";
		break;
	case 0x00308F00:
		ptr = "	MICRILOR, Inc.";
		break;
	case 0x00309000:
		ptr = "	CYRA TECHNOLOGIES, INC.";
		break;
	case 0x00309100:
		ptr = "	TAIWAN FIRST LINE ELEC. CORP.";
		break;
	case 0x00309200:
		ptr = "	ModuNORM GmbH";
		break;
	case 0x00309300:
		ptr = "	SONNET TECHNOLOGIES, INC.";
		break;
	case 0x00309400:
		ptr = "	Cisco Systems, Inc.";
		break;
	case 0x00309500:
		ptr = "	Procomp Informatics, Ltd.";
		break;
	case 0x00309600:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00309700:
		ptr = "	EXOMATIC AB";
		break;
	case 0x00309800:
		ptr = "	Global Converging Technologies";
		break;
	case 0x00309900:
		ptr = "	BOENIG UND KALLENBACH OHG";
		break;
	case 0x00309A00:
		ptr = "	ASTRO TERRA CORP.";
		break;
	case 0x00309B00:
		ptr = "	Smartware";
		break;
	case 0x00309C00:
		ptr = "	Timing Applications, Inc.";
		break;
	case 0x00309D00:
		ptr = "	Nimble Microsystems, Inc.";
		break;
	case 0x00309E00:
		ptr = "	WORKBIT CORPORATION.";
		break;
	case 0x00309F00:
		ptr = "	AMBER NETWORKS";
		break;
	case 0x0030A000:
		ptr = "	TYCO SUBMARINE SYSTEMS, LTD.";
		break;
	case 0x0030A100:
		ptr = "	OPTI TECH CO., LTD.";
		break;
	case 0x0030A200:
		ptr = "	Lightner Engineering";
		break;
	case 0x0030A300:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x0030A400:
		ptr = "	Woodwind Communications System";
		break;
	case 0x0030A500:
		ptr = "	ACTIVE POWER";
		break;
	case 0x0030A600:
		ptr = "	VIANET TECHNOLOGIES, LTD.";
		break;
	case 0x0030A700:
		ptr = "	SCHWEITZER ENGINEERING";
		break;
	case 0x0030A800:
		ptr = "	OL'E COMMUNICATIONS, INC.";
		break;
	case 0x0030A900:
		ptr = "	Netiverse, Inc.";
		break;
	case 0x0030AA00:
		ptr = "	AXUS MICROSYSTEMS, INC.";
		break;
	case 0x0030AB00:
		ptr = "	DELTA NETWORKS, INC.";
		break;
	case 0x0030AC00:
		ptr = "	Systeme Lauer GmbH & Co., Ltd.";
		break;
	case 0x0030AD00:
		ptr = "	SHANGHAI COMMUNICATION";
		break;
	case 0x0030AE00:
		ptr = "	Times N System, Inc.";
		break;
	case 0x0030AF00:
		ptr = "	Honeywell Reqelsysteme GmbH";
		break;
	case 0x0030B000:
		ptr = "	Convergenet Technologies";
		break;
	case 0x0030B100:
		ptr = "	GOC GESELLSCHAFT FUR OPTISCHE";
		break;
	case 0x0030B200:
		ptr = "	WESCAM - HEALDSBURG";
		break;
	case 0x0030B300:
		ptr = "	San Valley Systems, Inc.";
		break;
	case 0x0030B400:
		ptr = "	INTERSIL CORP.";
		break;
	case 0x0030B500:
		ptr = "	Tadiran Microwave Networks";
		break;
	case 0x0030B600:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x0030B700:
		ptr = "	Teletrol Systems, Inc.";
		break;
	case 0x0030B800:
		ptr = "	RiverDelta Networks";
		break;
	case 0x0030B900:
		ptr = "	ECTEL";
		break;
	case 0x0030BA00:
		ptr = "	AC&T SYSTEM CO., LTD.";
		break;
	case 0x0030BB00:
		ptr = "	CacheFlow, Inc.";
		break;
	case 0x0030BC00:
		ptr = "	Optronic AG";
		break;
	case 0x0030BD00:
		ptr = "	BELKIN COMPONENTS";
		break;
	case 0x0030BE00:
		ptr = "	City-Net Technology, Inc.";
		break;
	case 0x0030BF00:
		ptr = "	MULTIDATA GMBH";
		break;
	case 0x0030C000:
		ptr = "	Lara Technology, Inc.";
		break;
	case 0x0030C100:
		ptr = "	HEWLETT-PACKARD";
		break;
	case 0x0030C200:
		ptr = "	COMONE";
		break;
	case 0x0030C300:
		ptr = "	FLUECKIGER ELEKTRONIK AG";
		break;
	case 0x0030C400:
		ptr = "	Niigata Canotec Co., Inc.";
		break;
	case 0x0030C500:
		ptr = "	CADENCE DESIGN SYSTEMS";
		break;
	case 0x0030C600:
		ptr = "	CONTROL SOLUTIONS, INC.";
		break;
	case 0x0030C700:
		ptr = "	MACROMATE CORP.";
		break;
	case 0x0030C800:
		ptr = "	GAD LINE, LTD.";
		break;
	case 0x0030C900:
		ptr = "	LuxN, N";
		break;
	case 0x0030CA00:
		ptr = "	Discovery Com";
		break;
	case 0x0030CB00:
		ptr = "	OMNI FLOW COMPUTERS, INC.";
		break;
	case 0x0030CC00:
		ptr = "	Tenor Networks, Inc.";
		break;
	case 0x0030CD00:
		ptr = "	CONEXANT SYSTEMS, INC.";
		break;
	case 0x0030CE00:
		ptr = "	Zaffire";
		break;
	case 0x0030CF00:
		ptr = "	TWO TECHNOLOGIES, INC.";
		break;
	case 0x0030D100:
		ptr = "	INOVA CORPORATION";
		break;
	case 0x0030D200:
		ptr = "	WIN TECHNOLOGIES, CO., LTD.";
		break;
	case 0x0030D300:
		ptr = "	Agilent Technologies";
		break;
	case 0x0030D400:
		ptr = "	COMTIER";
		break;
	case 0x0030D500:
		ptr = "	DResearch GmbH";
		break;
	case 0x0030D600:
		ptr = "	MSC VERTRIEBS GMBH";
		break;
	case 0x0030D700:
		ptr = "	Innovative Systems, L.L.C.";
		break;
	case 0x0030D800:
		ptr = "	SITEK";
		break;
	case 0x0030D900:
		ptr = "	DATACORE SOFTWARE CORP.";
		break;
	case 0x0030DA00:
		ptr = "	COMTREND CO.";
		break;
	case 0x0030DB00:
		ptr = "	SEDERTA INC.";
		break;
	case 0x0030DC00:
		ptr = "	RIGHTECH CORPORATION";
		break;
	case 0x0030DD00:
		ptr = "	INDIGITA CORPORATION";
		break;
	case 0x0030DE00:
		ptr = "	WAGO Kontakttechnik GmbH";
		break;
	case 0x0030DF00:
		ptr = "	KB/TEL TELECOMUNICACIONES";
		break;
	case 0x0030E000:
		ptr = "	OXFORD SEMICONDUCTOR LTD.";
		break;
	case 0x0030E100:
		ptr = "	ACROTRON SYSTEMS, INC.";
		break;
	case 0x0030E200:
		ptr = "	GARNET SYSTEMS CO., LTD.";
		break;
	case 0x0030E300:
		ptr = "	SEDONA NETWORKS CORP.";
		break;
	case 0x0030E400:
		ptr = "	CHIYODA SYSTEM RIKEN";
		break;
	case 0x0030E500:
		ptr = "	Amper Datos S.A.";
		break;
	case 0x0030E600:
		ptr = "	SIEMENS MEDICAL SYSTEMS";
		break;
	case 0x0030E700:
		ptr = "	CNF MOBILE SOLUTIONS, INC.";
		break;
	case 0x0030E800:
		ptr = "	ENSIM CORP.";
		break;
	case 0x0030E900:
		ptr = "	GMA COMMUNICATION MANUFACT'G";
		break;
	case 0x0030EA00:
		ptr = "	INTELECT COMMUNICTIONS, INC.";
		break;
	case 0x0030EB00:
		ptr = "	TURBONET COMMUNICATIONS, INC.";
		break;
	case 0x0030EC00:
		ptr = "	BORGARDT";
		break;
	case 0x0030ED00:
		ptr = "	Expert Magnetics Corp.";
		break;
	case 0x0030EE00:
		ptr = "	DSG Technology, Inc.";
		break;
	case 0x0030EF00:
		ptr = "	NEON TECHNOLOGY, INC.";
		break;
	case 0x0030F000:
		ptr = "	Uniform Industrial Corp.";
		break;
	case 0x0030F100:
		ptr = "	Accton Technology Corp.";
		break;
	case 0x0030F200:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x0030F300:
		ptr = "	At Work Computers";
		break;
	case 0x0030F400:
		ptr = "	STARDOT TECHNOLOGIES";
		break;
	case 0x0030F500:
		ptr = "	Wild Lab. Ltd.";
		break;
	case 0x0030F600:
		ptr = "	SECURELOGIX CORPORATION";
		break;
	case 0x0030F700:
		ptr = "	RAMIX INC.";
		break;
	case 0x0030F800:
		ptr = "	Dynapro Systems, Inc.";
		break;
	case 0x0030F900:
		ptr = "	Sollae Systems Co., Ltd.";
		break;
	case 0x0030FA00:
		ptr = "	TELICA, INC.";
		break;
	case 0x0030FB00:
		ptr = "	AZS Technology AG";
		break;
	case 0x0030FC00:
		ptr = "	Terawave Communications, Inc.";
		break;
	case 0x0030FD00:
		ptr = "	INTEGRATED SYSTEMS DESIGN";
		break;
	case 0x0030FE00:
		ptr = "	DSA GmbH";
		break;
	case 0x0030FF00:
		ptr = "	DATAFAB SYSTEMS, INC.";
		break;
	case 0x00400000:
		ptr = "	PCI COMPONENTES DA AMZONIA LTD";
		break;
	case 0x00400100:
		ptr = "	ZYXEL COMMUNICATIONS, INC.";
		break;
	case 0x00400200:
		ptr = "	PERLE SYSTEMS LIMITED";
		break;
	case 0x00400300:
		ptr = "	WESTINGHOUSE PROCESS CONTROL";
		break;
	case 0x00400400:
		ptr = "	ICM CO. LTD.";
		break;
	case 0x00400500:
		ptr = "	ANI COMMUNICATIONS INC.";
		break;
	case 0x00400600:
		ptr = "	SAMPO TECHNOLOGY CORPORATION";
		break;
	case 0x00400700:
		ptr = "	TELMAT INFORMATIQUE";
		break;
	case 0x00400800:
		ptr = "	A PLUS INFO CORPORATION";
		break;
	case 0x00400900:
		ptr = "	TACHIBANA TECTRON CO., LTD.";
		break;
	case 0x00400A00:
		ptr = "	PIVOTAL TECHNOLOGIES, INC.";
		break;
	case 0x00400B00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00400C00:
		ptr = "	GENERAL MICRO SYSTEMS, INC.";
		break;
	case 0x00400D00:
		ptr = "	LANNET DATA COMMUNICATIONS,LTD";
		break;
	case 0x00400E00:
		ptr = "	MEMOTEC COMMUNICATIONS, INC.";
		break;
	case 0x00400F00:
		ptr = "	DATACOM TECHNOLOGIES";
		break;
	case 0x00401000:
		ptr = "	SONIC SYSTEMS, INC.";
		break;
	case 0x00401100:
		ptr = "	ANDOVER CONTROLS CORPORATION";
		break;
	case 0x00401200:
		ptr = "	WINDATA, INC.";
		break;
	case 0x00401300:
		ptr = "	NTT DATA COMM. SYSTEMS CORP.";
		break;
	case 0x00401400:
		ptr = "	COMSOFT GMBH";
		break;
	case 0x00401500:
		ptr = "	ASCOM INFRASYS AG";
		break;
	case 0x00401600:
		ptr = "	HADAX ELECTRONICS, INC.";
		break;
	case 0x00401700:
		ptr = "	XCD INC.";
		break;
	case 0x00401800:
		ptr = "	ADOBE SYSTEMS, INC.";
		break;
	case 0x00401900:
		ptr = "	AEON SYSTEMS, INC.";
		break;
	case 0x00401A00:
		ptr = "	FUJI ELECTRIC CO., LTD.";
		break;
	case 0x00401B00:
		ptr = "	PRINTER SYSTEMS CORP.";
		break;
	case 0x00401C00:
		ptr = "	AST RESEARCH, INC.";
		break;
	case 0x00401D00:
		ptr = "	INVISIBLE SOFTWARE, INC.";
		break;
	case 0x00401E00:
		ptr = "	ICC";
		break;
	case 0x00401F00:
		ptr = "	COLORGRAPH LTD";
		break;
	case 0x00402000:
		ptr = "	PINACL COMMUNICATION";
		break;
	case 0x00402100:
		ptr = "	RASTER GRAPHICS";
		break;
	case 0x00402200:
		ptr = "	KLEVER COMPUTERS, INC.";
		break;
	case 0x00402300:
		ptr = "	LOGIC CORPORATION";
		break;
	case 0x00402400:
		ptr = "	COMPAC INC.";
		break;
	case 0x00402500:
		ptr = "	MOLECULAR DYNAMICS";
		break;
	case 0x00402600:
		ptr = "	MELCO, INC.";
		break;
	case 0x00402700:
		ptr = "	SMC MASSACHUSETTS, INC.";
		break;
	case 0x00402800:
		ptr = "	NETCOMM LIMITED";
		break;
	case 0x00402900:
		ptr = "	COMPEX";
		break;
	case 0x00402A00:
		ptr = "	CANOGA-PERKINS";
		break;
	case 0x00402B00:
		ptr = "	TRIGEM COMPUTER, INC.";
		break;
	case 0x00402C00:
		ptr = "	ISIS DISTRIBUTED SYSTEMS, INC.";
		break;
	case 0x00402D00:
		ptr = "	HARRIS ADACOM CORPORATION";
		break;
	case 0x00402E00:
		ptr = "	PRECISION SOFTWARE, INC.";
		break;
	case 0x00402F00:
		ptr = "	XLNT DESIGNS INC.";
		break;
	case 0x00403000:
		ptr = "	GK COMPUTER";
		break;
	case 0x00403100:
		ptr = "	KOKUSAI ELECTRIC CO., LTD";
		break;
	case 0x00403200:
		ptr = "	DIGITAL COMMUNICATIONS";
		break;
	case 0x00403300:
		ptr = "	ADDTRON TECHNOLOGY CO., LTD.";
		break;
	case 0x00403400:
		ptr = "	BUSTEK CORPORATION";
		break;
	case 0x00403500:
		ptr = "	OPCOM";
		break;
	case 0x00403600:
		ptr = "	TRIBE COMPUTER WORKS, INC.";
		break;
	case 0x00403700:
		ptr = "	SEA-ILAN, INC.";
		break;
	case 0x00403800:
		ptr = "	TALENT ELECTRIC INCORPORATED";
		break;
	case 0x00403900:
		ptr = "	OPTEC DAIICHI DENKO CO., LTD.";
		break;
	case 0x00403A00:
		ptr = "	IMPACT TECHNOLOGIES";
		break;
	case 0x00403B00:
		ptr = "	SYNERJET INTERNATIONAL CORP.";
		break;
	case 0x00403C00:
		ptr = "	FORKS, INC.";
		break;
	case 0x00403D00:
		ptr = "	TERADATA";
		break;
	case 0x00403E00:
		ptr = "	RASTER OPS CORPORATION";
		break;
	case 0x00403F00:
		ptr = "	SSANGYONG COMPUTER SYSTEMS";
		break;
	case 0x00404000:
		ptr = "	RING ACCESS, INC.";
		break;
	case 0x00404100:
		ptr = "	FUJIKURA LTD.";
		break;
	case 0x00404200:
		ptr = "	N.A.T. GMBH";
		break;
	case 0x00404300:
		ptr = "	NOKIA TELECOMMUNICATIONS";
		break;
	case 0x00404400:
		ptr = "	QNIX COMPUTER CO., LTD.";
		break;
	case 0x00404500:
		ptr = "	TWINHEAD CORPORATION";
		break;
	case 0x00404600:
		ptr = "	UDC RESEARCH LIMITED";
		break;
	case 0x00404700:
		ptr = "	WIND RIVER SYSTEMS";
		break;
	case 0x00404800:
		ptr = "	SMD INFORMATICA S.A.";
		break;
	case 0x00404900:
		ptr = "	TEGIMENTA AG";
		break;
	case 0x00404A00:
		ptr = "	WEST AUSTRALIAN DEPARTMENT";
		break;
	case 0x00404B00:
		ptr = "	MAPLE COMPUTER SYSTEMS";
		break;
	case 0x00404C00:
		ptr = "	HYPERTEC PTY LTD.";
		break;
	case 0x00404D00:
		ptr = "	TELECOMMUNICATIONS TECHNIQUES";
		break;
	case 0x00404E00:
		ptr = "	FLUENT, INC.";
		break;
	case 0x00404F00:
		ptr = "	SPACE & NAVAL WARFARE SYSTEMS";
		break;
	case 0x00405000:
		ptr = "	IRONICS, INCORPORATED";
		break;
	case 0x00405100:
		ptr = "	GRACILIS, INC.";
		break;
	case 0x00405200:
		ptr = "	STAR TECHNOLOGIES, INC.";
		break;
	case 0x00405300:
		ptr = "	AMPRO COMPUTERS";
		break;
	case 0x00405400:
		ptr = "	CONNECTION MACHINES SERVICES";
		break;
	case 0x00405500:
		ptr = "	METRONIX GMBH";
		break;
	case 0x00405600:
		ptr = "	MCM JAPAN LTD.";
		break;
	case 0x00405700:
		ptr = "	LOCKHEED - SANDERS";
		break;
	case 0x00405800:
		ptr = "	KRONOS, INC.";
		break;
	case 0x00405900:
		ptr = "	YOSHIDA KOGYO K. K.";
		break;
	case 0x00405A00:
		ptr = "	GOLDSTAR INFORMATION & COMM.";
		break;
	case 0x00405B00:
		ptr = "	FUNASSET LIMITED";
		break;
	case 0x00405C00:
		ptr = "	FUTURE SYSTEMS, INC.";
		break;
	case 0x00405D00:
		ptr = "	STAR-TEK, INC.";
		break;
	case 0x00405E00:
		ptr = "	NORTH HILLS ISRAEL";
		break;
	case 0x00405F00:
		ptr = "	AFE COMPUTERS LTD.";
		break;
	case 0x00406000:
		ptr = "	COMENDEC LTD";
		break;
	case 0x00406100:
		ptr = "	DATATECH ENTERPRISES CO., LTD.";
		break;
	case 0x00406200:
		ptr = "	E-SYSTEMS, INC./GARLAND DIV.";
		break;
	case 0x00406300:
		ptr = "	VIA TECHNOLOGIES, INC.";
		break;
	case 0x00406400:
		ptr = "	KLA INSTRUMENTS CORPORATION";
		break;
	case 0x00406500:
		ptr = "	GTE SPACENET";
		break;
	case 0x00406600:
		ptr = "	HITACHI CABLE, LTD.";
		break;
	case 0x00406700:
		ptr = "	OMNIBYTE CORPORATION";
		break;
	case 0x00406800:
		ptr = "	EXTENDED SYSTEMS";
		break;
	case 0x00406900:
		ptr = "	LEMCOM SYSTEMS, INC.";
		break;
	case 0x00406A00:
		ptr = "	KENTEK INFORMATION SYSTEMS,INC";
		break;
	case 0x00406B00:
		ptr = "	SYSGEN";
		break;
	case 0x00406C00:
		ptr = "	COPERNIQUE";
		break;
	case 0x00406D00:
		ptr = "	LANCO, INC.";
		break;
	case 0x00406E00:
		ptr = "	COROLLARY, INC.";
		break;
	case 0x00406F00:
		ptr = "	SYNC RESEARCH INC.";
		break;
	case 0x00407000:
		ptr = "	INTERWARE CO., LTD.";
		break;
	case 0x00407100:
		ptr = "	ATM COMPUTER GMBH";
		break;
	case 0x00407200:
		ptr = "	APPLIED INNOVATION, INC.";
		break;
	case 0x00407300:
		ptr = "	BASS ASSOCIATES";
		break;
	case 0x00407400:
		ptr = "	CABLE AND WIRELESS";
		break;
	case 0x00407500:
		ptr = "	M-TRADE (UK) LTD";
		break;
	case 0x00407600:
		ptr = "	AMP INCORPORATED";
		break;
	case 0x00407700:
		ptr = "	MAXTON TECHNOLOGY CORPORATION";
		break;
	case 0x00407800:
		ptr = "	WEARNES AUTOMATION PTE LTD";
		break;
	case 0x00407900:
		ptr = "	JUKO MANUFACTURE COMPANY, LTD.";
		break;
	case 0x00407A00:
		ptr = "	SOCIETE D'EXPLOITATION DU CNIT";
		break;
	case 0x00407B00:
		ptr = "	SCIENTIFIC ATLANTA";
		break;
	case 0x00407C00:
		ptr = "	QUME CORPORATION";
		break;
	case 0x00407D00:
		ptr = "	EXTENSION TECHNOLOGY CORP.";
		break;
	case 0x00407E00:
		ptr = "	EVERGREEN SYSTEMS, INC.";
		break;
	case 0x00407F00:
		ptr = "	AGEMA INFRARED SYSTEMS AB";
		break;
	case 0x00408000:
		ptr = "	ATHENIX CORPORATION";
		break;
	case 0x00408100:
		ptr = "	MANNESMANN SCANGRAPHIC GMBH";
		break;
	case 0x00408200:
		ptr = "	LABORATORY EQUIPMENT CORP.";
		break;
	case 0x00408300:
		ptr = "	TDA INDUSTRIA DE PRODUTOS";
		break;
	case 0x00408400:
		ptr = "	HONEYWELL INC.";
		break;
	case 0x00408500:
		ptr = "	SAAB INSTRUMENTS AB";
		break;
	case 0x00408600:
		ptr = "	MICHELS & KLEBERHOFF COMPUTER";
		break;
	case 0x00408700:
		ptr = "	UBITREX CORPORATION";
		break;
	case 0x00408800:
		ptr = "	MOBIUS TECHNOLOGIES, INC.";
		break;
	case 0x00408900:
		ptr = "	MEIDENSHA CORPORATION";
		break;
	case 0x00408A00:
		ptr = "	TPS TELEPROCESSING SYS. GMBH";
		break;
	case 0x00408B00:
		ptr = "	RAYLAN CORPORATION";
		break;
	case 0x00408C00:
		ptr = "	AXIS COMMUNICATIONS AB";
		break;
	case 0x00408D00:
		ptr = "	THE GOODYEAR TIRE & RUBBER CO.";
		break;
	case 0x00408E00:
		ptr = "	DIGILOG, INC.";
		break;
	case 0x00408F00:
		ptr = "	WM-DATA MINFO AB";
		break;
	case 0x00409000:
		ptr = "	ANSEL COMMUNICATIONS";
		break;
	case 0x00409100:
		ptr = "	PROCOMP INDUSTRIA ELETRONICA";
		break;
	case 0x00409200:
		ptr = "	ASP COMPUTER PRODUCTS, INC.";
		break;
	case 0x00409300:
		ptr = "	PAXDATA NETWORKS LTD.";
		break;
	case 0x00409400:
		ptr = "	SHOGRAPHICS, INC.";
		break;
	case 0x00409500:
		ptr = "	R.P.T. INTERGROUPS INT'L LTD.";
		break;
	case 0x00409600:
		ptr = "	Aironet Wireless Communication";
		break;
	case 0x00409700:
		ptr = "	DATEX DIVISION OF";
		break;
	case 0x00409800:
		ptr = "	DRESSLER GMBH & CO.";
		break;
	case 0x00409900:
		ptr = "	NEWGEN SYSTEMS CORP.";
		break;
	case 0x00409A00:
		ptr = "	NETWORK EXPRESS, INC.";
		break;
	case 0x00409B00:
		ptr = "	HAL COMPUTER SYSTEMS INC.";
		break;
	case 0x00409C00:
		ptr = "	TRANSWARE";
		break;
	case 0x00409D00:
		ptr = "	DIGIBOARD, INC.";
		break;
	case 0x00409E00:
		ptr = "	CONCURRENT TECHNOLOGIES  LTD.";
		break;
	case 0x00409F00:
		ptr = "	LANCAST/CASAT TECHNOLOGY, INC.";
		break;
	case 0x0040A000:
		ptr = "	GOLDSTAR CO., LTD.";
		break;
	case 0x0040A100:
		ptr = "	ERGO COMPUTING";
		break;
	case 0x0040A200:
		ptr = "	KINGSTAR TECHNOLOGY INC.";
		break;
	case 0x0040A300:
		ptr = "	MICROUNITY SYSTEMS ENGINEERING";
		break;
	case 0x0040A400:
		ptr = "	ROSE ELECTRONICS";
		break;
	case 0x0040A500:
		ptr = "	CLINICOMP INTL.";
		break;
	case 0x0040A600:
		ptr = "	CRAY RESEARCH INC.";
		break;
	case 0x0040A700:
		ptr = "	ITAUTEC PHILCO S.A.";
		break;
	case 0x0040A800:
		ptr = "	IMF INTERNATIONAL LTD.";
		break;
	case 0x0040A900:
		ptr = "	DATACOM INC.";
		break;
	case 0x0040AA00:
		ptr = "	VALMET AUTOMATION INC.";
		break;
	case 0x0040AB00:
		ptr = "	ROLAND DG CORPORATION";
		break;
	case 0x0040AC00:
		ptr = "	SUPER WORKSTATION, INC.";
		break;
	case 0x0040AD00:
		ptr = "	SMA REGELSYSTEME GMBH";
		break;
	case 0x0040AE00:
		ptr = "	DELTA CONTROLS, INC.";
		break;
	case 0x0040AF00:
		ptr = "	DIGITAL PRODUCTS, INC.";
		break;
	case 0x0040B000:
		ptr = "	BYTEX CORPORATION, ENGINEERING";
		break;
	case 0x0040B100:
		ptr = "	CODONICS INC.";
		break;
	case 0x0040B200:
		ptr = "	SYSTEMFORSCHUNG";
		break;
	case 0x0040B300:
		ptr = "	PAR MICROSYSTEMS CORPORATION";
		break;
	case 0x0040B400:
		ptr = "	NEXTCOM K.K.";
		break;
	case 0x0040B500:
		ptr = "	VIDEO TECHNOLOGY COMPUTERS LTD";
		break;
	case 0x0040B600:
		ptr = "	COMPUTERM  CORPORATION";
		break;
	case 0x0040B700:
		ptr = "	STEALTH COMPUTER SYSTEMS";
		break;
	case 0x0040B800:
		ptr = "	IDEA ASSOCIATES";
		break;
	case 0x0040B900:
		ptr = "	MACQ ELECTRONIQUE SA";
		break;
	case 0x0040BA00:
		ptr = "	ALLIANT COMPUTER SYSTEMS CORP.";
		break;
	case 0x0040BB00:
		ptr = "	GOLDSTAR CABLE CO., LTD.";
		break;
	case 0x0040BC00:
		ptr = "	ALGORITHMICS LTD.";
		break;
	case 0x0040BD00:
		ptr = "	STARLIGHT NETWORKS, INC.";
		break;
	case 0x0040BE00:
		ptr = "	BOEING DEFENSE & SPACE";
		break;
	case 0x0040BF00:
		ptr = "	CHANNEL SYSTEMS INTERN'L INC.";
		break;
	case 0x0040C000:
		ptr = "	VISTA CONTROLS CORPORATION";
		break;
	case 0x0040C100:
		ptr = "	BIZERBA-WERKE WILHEIM KRAUT";
		break;
	case 0x0040C200:
		ptr = "	APPLIED COMPUTING DEVICES";
		break;
	case 0x0040C300:
		ptr = "	FISCHER AND PORTER CO.";
		break;
	case 0x0040C400:
		ptr = "	KINKEI SYSTEM CORPORATION";
		break;
	case 0x0040C500:
		ptr = "	MICOM COMMUNICATIONS INC.";
		break;
	case 0x0040C600:
		ptr = "	FIBERNET RESEARCH, INC.";
		break;
	case 0x0040C700:
		ptr = "	RUBY TECH CORPORATION";
		break;
	case 0x0040C800:
		ptr = "	MILAN TECHNOLOGY CORPORATION";
		break;
	case 0x0040C900:
		ptr = "	NCUBE";
		break;
	case 0x0040CA00:
		ptr = "	FIRST INTERNAT'L COMPUTER, INC";
		break;
	case 0x0040CB00:
		ptr = "	LANWAN TECHNOLOGIES";
		break;
	case 0x0040CC00:
		ptr = "	SILCOM MANUF'G TECHNOLOGY INC.";
		break;
	case 0x0040CD00:
		ptr = "	TERA MICROSYSTEMS, INC.";
		break;
	case 0x0040CE00:
		ptr = "	NET-SOURCE, INC.";
		break;
	case 0x0040CF00:
		ptr = "	STRAWBERRY TREE, INC.";
		break;
	case 0x0040D000:
		ptr = "	MITAC INTERNATIONAL CORP.";
		break;
	case 0x0040D100:
		ptr = "	FUKUDA DENSHI CO., LTD.";
		break;
	case 0x0040D200:
		ptr = "	PAGINE CORPORATION";
		break;
	case 0x0040D300:
		ptr = "	KIMPSION INTERNATIONAL CORP.";
		break;
	case 0x0040D400:
		ptr = "	GAGE TALKER CORP.";
		break;
	case 0x0040D500:
		ptr = "	SARTORIUS AG";
		break;
	case 0x0040D600:
		ptr = "	LOCAMATION B.V.";
		break;
	case 0x0040D700:
		ptr = "	STUDIO GEN INC.";
		break;
	case 0x0040D800:
		ptr = "	OCEAN OFFICE AUTOMATION LTD.";
		break;
	case 0x0040D900:
		ptr = "	AMERICAN MEGATRENDS INC.";
		break;
	case 0x0040DA00:
		ptr = "	TELSPEC LTD";
		break;
	case 0x0040DB00:
		ptr = "	ADVANCED TECHNICAL SOLUTIONS";
		break;
	case 0x0040DC00:
		ptr = "	TRITEC ELECTRONIC GMBH";
		break;
	case 0x0040DD00:
		ptr = "	HONG TECHNOLOGIES";
		break;
	case 0x0040DE00:
		ptr = "	ELETTRONICA SAN GIORGIO";
		break;
	case 0x0040DF00:
		ptr = "	DIGALOG SYSTEMS, INC.";
		break;
	case 0x0040E000:
		ptr = "	ATOMWIDE LTD.";
		break;
	case 0x0040E100:
		ptr = "	MARNER INTERNATIONAL, INC.";
		break;
	case 0x0040E200:
		ptr = "	MESA RIDGE TECHNOLOGIES, INC.";
		break;
	case 0x0040E300:
		ptr = "	QUIN SYSTEMS LTD";
		break;
	case 0x0040E400:
		ptr = "	E-M TECHNOLOGY, INC.";
		break;
	case 0x0040E500:
		ptr = "	SYBUS CORPORATION";
		break;
	case 0x0040E600:
		ptr = "	C.A.E.N.";
		break;
	case 0x0040E700:
		ptr = "	ARNOS INSTRUMENTS & COMPUTER";
		break;
	case 0x0040E800:
		ptr = "	CHARLES RIVER DATA SYSTEMS,INC";
		break;
	case 0x0040E900:
		ptr = "	ACCORD SYSTEMS, INC.";
		break;
	case 0x0040EA00:
		ptr = "	PLAIN TREE SYSTEMS INC";
		break;
	case 0x0040EB00:
		ptr = "	MARTIN MARIETTA CORPORATION";
		break;
	case 0x0040EC00:
		ptr = "	MIKASA SYSTEM ENGINEERING";
		break;
	case 0x0040ED00:
		ptr = "	NETWORK CONTROLS INT'NATL INC.";
		break;
	case 0x0040EE00:
		ptr = "	OPTIMEM";
		break;
	case 0x0040EF00:
		ptr = "	HYPERCOM, INC.";
		break;
	case 0x0040F000:
		ptr = "	MICRO SYSTEMS, INC.";
		break;
	case 0x0040F100:
		ptr = "	CHUO ELECTRONICS CO., LTD.";
		break;
	case 0x0040F200:
		ptr = "	JANICH & KLASS COMPUTERTECHNIK";
		break;
	case 0x0040F300:
		ptr = "	NETCOR";
		break;
	case 0x0040F400:
		ptr = "	CAMEO COMMUNICATIONS, INC.";
		break;
	case 0x0040F500:
		ptr = "	OEM ENGINES";
		break;
	case 0x0040F600:
		ptr = "	KATRON COMPUTERS INC.";
		break;
	case 0x0040F700:
		ptr = "	POLAROID MEDICAL IMAGING SYS.";
		break;
	case 0x0040F800:
		ptr = "	SYSTEMHAUS DISCOM";
		break;
	case 0x0040F900:
		ptr = "	COMBINET";
		break;
	case 0x0040FA00:
		ptr = "	MICROBOARDS, INC.";
		break;
	case 0x0040FB00:
		ptr = "	CASCADE COMMUNICATIONS CORP.";
		break;
	case 0x0040FC00:
		ptr = "	IBR COMPUTER TECHNIK GMBH";
		break;
	case 0x0040FD00:
		ptr = "	LXE";
		break;
	case 0x0040FE00:
		ptr = "	SYMPLEX COMMUNICATIONS";
		break;
	case 0x0040FF00:
		ptr = "	TELEBIT CORPORATION";
		break;
	case 0x00500000:
		ptr = "	NEXO COMMUNICATIONS, INC.";
		break;
	case 0x00500100:
		ptr = "	YAMASHITA SYSTEMS CORP.";
		break;
	case 0x00500200:
		ptr = "	OMNISEC AG";
		break;
	case 0x00500300:
		ptr = "	GRETAG MACBETH AG";
		break;
	case 0x00500400:
		ptr = "	3COM CORPORATION";
		break;
	case 0x00500600:
		ptr = "	TAC AB";
		break;
	case 0x00500700:
		ptr = "	SIEMENS TELECOMMUNICATION";
		break;
	case 0x00500800:
		ptr = "	TIVA MICROCOMPUTER CORP. (TMC)";
		break;
	case 0x00500900:
		ptr = "	PHILIPS BROADBAND NETWORKS";
		break;
	case 0x00500A00:
		ptr = "	IRIS TECHNOLOGIES, INC.";
		break;
	case 0x00500C00:
		ptr = "	ETEK LABS, INC.";
		break;
	case 0x00500D00:
		ptr = "	SATORI ELECTORIC CO., LTD.";
		break;
	case 0x00500E00:
		ptr = "	CHROMATIS NETWORKS,INC.";
		break;
	case 0x00500F00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00501000:
		ptr = "	NOVANET LEARNING, INC.";
		break;
	case 0x00501200:
		ptr = "	CBL - GMBH";
		break;
	case 0x00501300:
		ptr = "	CHAPARRAL TECHNOLOGIES, INC.";
		break;
	case 0x00501400:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00501500:
		ptr = "	BRIGHT STAR ENGINEERING";
		break;
	case 0x00501600:
		ptr = "	SST/WOODHEAD INDUSTRIES";
		break;
	case 0x00501700:
		ptr = "	RSR S.R.L.";
		break;
	case 0x00501800:
		ptr = "	ADVANCED MULTIMEDIA INTERNET";
		break;
	case 0x00501900:
		ptr = "	SPRING TIDE NETWORKS, INC.";
		break;
	case 0x00501A00:
		ptr = "	UISIQN";
		break;
	case 0x00501B00:
		ptr = "	ABL CANADA, INC.";
		break;
	case 0x00501C00:
		ptr = "	JATOM SYSTEMS, INC.";
		break;
	case 0x00501E00:
		ptr = "	MIRANDA TECHNOLOGIES, INC.";
		break;
	case 0x00501F00:
		ptr = "	MRG SYSTEMS, LTD.";
		break;
	case 0x00502000:
		ptr = "	MEDIASTAR CO., LTD.";
		break;
	case 0x00502100:
		ptr = "	EIS INTERNATIONAL, INC.";
		break;
	case 0x00502200:
		ptr = "	ZONET TECHNOLOGY, INC.";
		break;
	case 0x00502300:
		ptr = "	PG DESIGN ELECTRONICS, INC.";
		break;
	case 0x00502400:
		ptr = "	NAVIC SYSTEMS, INC.";
		break;
	case 0x00502600:
		ptr = "	COSYSTEMS, INC.";
		break;
	case 0x00502700:
		ptr = "	GENICOM CORPORATION";
		break;
	case 0x00502800:
		ptr = "	AVAL COMMUNICATIONS";
		break;
	case 0x00502900:
		ptr = "	1394 PRINTER WORKING GROUP";
		break;
	case 0x00502A00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00502B00:
		ptr = "	GENRAD LTD.";
		break;
	case 0x00502C00:
		ptr = "	SOYO COMPUTER, INC.";
		break;
	case 0x00502D00:
		ptr = "	ACCEL, INC.";
		break;
	case 0x00502E00:
		ptr = "	CAMBEX CORPORATION";
		break;
	case 0x00502F00:
		ptr = "	TOLLBRIDGE TECHNOLOGIES, INC.";
		break;
	case 0x00503000:
		ptr = "	FUTURE PLUS SYSTEMS";
		break;
	case 0x00503100:
		ptr = "	AEROFLEX LABORATORIES, INC.";
		break;
	case 0x00503200:
		ptr = "	PICAZO COMMUNICATIONS, INC.";
		break;
	case 0x00503300:
		ptr = "	MAYAN NETWORKS";
		break;
	case 0x00503600:
		ptr = "	NETCAM, LTD.";
		break;
	case 0x00503700:
		ptr = "	KOGA ELECTRONICS CO.";
		break;
	case 0x00503800:
		ptr = "	DAIN TELECOM CO., LTD.";
		break;
	case 0x00503900:
		ptr = "	MARINER NETWORKS";
		break;
	case 0x00503A00:
		ptr = "	DATONG ELECTRONICS LTD.";
		break;
	case 0x00503B00:
		ptr = "	MEDIAFIRE CORPORATION";
		break;
	case 0x00503C00:
		ptr = "	TSINGHUA NOVEL ELECTRONICS";
		break;
	case 0x00503E00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00503F00:
		ptr = "	ANCHOR GAMES";
		break;
	case 0x00504000:
		ptr = "	EMWARE, INC.";
		break;
	case 0x00504100:
		ptr = "	CTX OPTO ELECTRONIC CORP.";
		break;
	case 0x00504200:
		ptr = "	SCI MANUFACTURING";
		break;
	case 0x00504300:
		ptr = "	MARVELL SEMICONDUCTOR, INC.";
		break;
	case 0x00504400:
		ptr = "	ASACA CORPORATION";
		break;
	case 0x00504500:
		ptr = "	RIOWORKS SOLUTIONS, INC.";
		break;
	case 0x00504600:
		ptr = "	MENICX INTERNATIONAL CO., LTD.";
		break;
	case 0x00504800:
		ptr = "	INFOLIBRIA";
		break;
	case 0x00504900:
		ptr = "	ELLACOYA NETWORKS, INC.";
		break;
	case 0x00504A00:
		ptr = "	ELTECO A.S.";
		break;
	case 0x00504B00:
		ptr = "	BARCO N.V. BCS";
		break;
	case 0x00504C00:
		ptr = "	GALIL MOTION CONTROL, INC.";
		break;
	case 0x00504D00:
		ptr = "	TOKYO ELECTRON DEVICE LTD.";
		break;
	case 0x00504E00:
		ptr = "	SIERRA MONITOR CORP.";
		break;
	case 0x00504F00:
		ptr = "	OLENCOM ELECTRONICS";
		break;
	case 0x00505000:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00505100:
		ptr = "	IWATSU ELECTRIC CO., LTD.";
		break;
	case 0x00505200:
		ptr = "	TIARA NETWORKS, INC.";
		break;
	case 0x00505300:
	case 0x00505400:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00505500:
		ptr = "	DOMS A/S";
		break;
	case 0x00505600:
		ptr = "	VMWARE, INC.";
		break;
	case 0x00505700:
		ptr = "	BROADBAND ACCESS SYSTEMS";
		break;
	case 0x00505800:
		ptr = "	VEGASTREAM LIMITED";
		break;
	case 0x00505900:
		ptr = "	SUITE TECHNOLOGY SYSTEMS";
		break;
	case 0x00505A00:
		ptr = "	NETWORK ALCHEMY, INC.";
		break;
	case 0x00505B00:
		ptr = "	KAWASAKI LSI U.S.A., INC.";
		break;
	case 0x00505C00:
		ptr = "	TUNDO CORPORATION";
		break;
	case 0x00505E00:
		ptr = "	DIGITEK MICROLOGIC S.A.";
		break;
	case 0x00505F00:
		ptr = "	BRAND INNOVATORS";
		break;
	case 0x00506000:
		ptr = "	TANDBERG TELECOM AS";
		break;
	case 0x00506200:
		ptr = "	KOUWELL ELECTRONICS CORP.  **";
		break;
	case 0x00506300:
		ptr = "	OY COMSEL SYSTEM AB";
		break;
	case 0x00506400:
		ptr = "	CAE ELECTRONICS";
		break;
	case 0x00506500:
		ptr = "	DENSEI-LAMBAD Co., Ltd.";
		break;
	case 0x00506600:
		ptr = "	ATECOM GMBH ADVANCED";
		break;
	case 0x00506700:
		ptr = "	AEROCOMM, INC.";
		break;
	case 0x00506800:
		ptr = "	ELECTRONIC INDUSTRIES";
		break;
	case 0x00506900:
		ptr = "	PIXSTREAM INCORPORATED";
		break;
	case 0x00506A00:
		ptr = "	EDEVA, INC.";
		break;
	case 0x00506B00:
		ptr = "	SPX-ATEG";
		break;
	case 0x00506C00:
		ptr = "	G & L BEIJER ELECTRONICS AB";
		break;
	case 0x00506D00:
		ptr = "	VIDEOJET SYSTEMS";
		break;
	case 0x00506E00:
		ptr = "	CORDER ENGINEERING CORPORATION";
		break;
	case 0x00506F00:
		ptr = "	G-CONNECT";
		break;
	case 0x00507000:
		ptr = "	CHAINTECH COMPUTER CO., LTD.";
		break;
	case 0x00507100:
		ptr = "	AIWA CO., LTD.";
		break;
	case 0x00507200:
		ptr = "	CORVIS CORPORATION";
		break;
	case 0x00507300:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00507400:
		ptr = "	ADVANCED HI-TECH CORP.";
		break;
	case 0x00507500:
		ptr = "	KESTREL SOLUTIONS";
		break;
	case 0x00507600:
		ptr = "	IBM";
		break;
	case 0x00507700:
		ptr = "	PROLIFIC TECHNOLOGY, INC.";
		break;
	case 0x00507800:
		ptr = "	MEGATON HOUSE, LTD.";
		break;
	case 0x00507A00:
		ptr = "	XPEED, INC.";
		break;
	case 0x00507B00:
		ptr = "	MERLOT COMMUNICATIONS";
		break;
	case 0x00507C00:
		ptr = "	VIDEOCON AG";
		break;
	case 0x00507D00:
		ptr = "	IFP";
		break;
	case 0x00507E00:
		ptr = "	NEWER TECHNOLOGY";
		break;
	case 0x00507F00:
		ptr = "	DRAYTEK CORP.";
		break;
	case 0x00508000:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00508100:
		ptr = "	MURATA MACHINERY, LTD.";
		break;
	case 0x00508200:
		ptr = "	FORESSON CORPORATION";
		break;
	case 0x00508300:
		ptr = "	GILBARCO, INC.";
		break;
	case 0x00508400:
		ptr = "	ATL PRODUCTS";
		break;
	case 0x00508600:
		ptr = "	TELKOM SA, LTD.";
		break;
	case 0x00508700:
		ptr = "	TERASAKI ELECTRIC CO., LTD.";
		break;
	case 0x00508800:
		ptr = "	AMANO CORPORATION";
		break;
	case 0x00508900:
		ptr = "	SAFETY MANAGEMENT SYSTEMS";
		break;
	case 0x00508B00:
		ptr = "	COMPAQ COMPUTER CORPORATION";
		break;
	case 0x00508C00:
		ptr = "	RSI SYSTEMS";
		break;
	case 0x00508D00:
		ptr = "	ABIT COMPUTER CORPORATION";
		break;
	case 0x00508E00:
		ptr = "	OPTIMATION, INC.";
		break;
	case 0x00508F00:
		ptr = "	ASITA TECHNOLOGIES INT'L LTD.";
		break;
	case 0x00509000:
		ptr = "	DCTRI";
		break;
	case 0x00509100:
		ptr = "	NETACCESS, INC.";
		break;
	case 0x00509200:
		ptr = "	RIGAKU INDUSTRIAL CORPORATION";
		break;
	case 0x00509300:
		ptr = "	BOEING";
		break;
	case 0x00509400:
		ptr = "	PACE MICRO TECHNOLOGY PLC";
		break;
	case 0x00509500:
		ptr = "	PERACOM NETWORKS";
		break;
	case 0x00509600:
		ptr = "	SALIX TECHNOLOGIES, INC.";
		break;
	case 0x00509700:
		ptr = "	MMC-EMBEDDED";
		break;
	case 0x00509800:
		ptr = "	GLOBALOOP, LTD.";
		break;
	case 0x00509900:
		ptr = "	3COM EUROPE, LTD.";
		break;
	case 0x00509A00:
		ptr = "	TAG ELECTRONIC SYSTEMS";
		break;
	case 0x00509B00:
		ptr = "	SWITCHCORE AB";
		break;
	case 0x00509C00:
		ptr = "	BETA RESEARCH";
		break;
	case 0x00509D00:
		ptr = "	THE INDUSTREE B.V.";
		break;
	case 0x00509E00:
		ptr = "	LES TECHNOLOGIES";
		break;
	case 0x00509F00:
		ptr = "	HORIZON COMPUTER";
		break;
	case 0x0050A000:
		ptr = "	DELTA COMPUTER SYSTEMS, INC.";
		break;
	case 0x0050A100:
		ptr = "	CARLO GAVAZZI, INC.";
		break;
	case 0x0050A200:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x0050A300:
		ptr = "	TRANSMEDIA COMMUNICATIONS, INC";
		break;
	case 0x0050A400:
		ptr = "	IO TECH, INC.";
		break;
	case 0x0050A500:
		ptr = "	CAPITOL BUSINESS SYSTEMS, LTD.";
		break;
	case 0x0050A600:
		ptr = "	OPTRONICS";
		break;
	case 0x0050A700:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x0050A800:
		ptr = "	OPENCON SYSTEMS, INC.";
		break;
	case 0x0050A900:
		ptr = "	MOLDAT WIRELESS TECHNOLGIES";
		break;
	case 0x0050AA00:
		ptr = "	KONICA CORPORATION";
		break;
	case 0x0050AB00:
		ptr = "	NALTEC, INC.";
		break;
	case 0x0050AC00:
		ptr = "	MAPLE COMPUTER CORPORATION";
		break;
	case 0x0050AD00:
		ptr = "	COMMUNIQUE WIRELESS CORP.";
		break;
	case 0x0050AE00:
		ptr = "	IWAKI ELECTRONICS CO., LTD.";
		break;
	case 0x0050AF00:
		ptr = "	INTERGON, INC.";
		break;
	case 0x0050B000:
		ptr = "	TECHNOLOGY ATLANTA CORPORATION";
		break;
	case 0x0050B100:
		ptr = "	GIDDINGS & LEWIS";
		break;
	case 0x0050B200:
		ptr = "	BRODEL AUTOMATION";
		break;
	case 0x0050B300:
		ptr = "	VOICEBOARD CORPORATION";
		break;
	case 0x0050B400:
		ptr = "	SATCHWELL CONTROL SYSTEMS, LTD";
		break;
	case 0x0050B500:
		ptr = "	FICHET-BAUCHE";
		break;
	case 0x0050B600:
		ptr = "	GOOD WAY IND. CO., LTD.";
		break;
	case 0x0050B700:
		ptr = "	BOSER TECHNOLOGY CO., LTD.";
		break;
	case 0x0050B800:
		ptr = "	INOVA COMPUTERS GMBH & CO. KG";
		break;
	case 0x0050B900:
		ptr = "	XITRON TECHNOLOGIES, INC.";
		break;
	case 0x0050BA00:
		ptr = "	D-LINK";
		break;
	case 0x0050BB00:
		ptr = "	CMS TECHNOLOGIES";
		break;
	case 0x0050BC00:
		ptr = "	HAMMER STORAGE SOLUTIONS";
		break;
	case 0x0050BD00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x0050BE00:
		ptr = "	FAST MULTIMEDIA AG";
		break;
	case 0x0050BF00:
		ptr = "	MOTOTECH INC.";
		break;
	case 0x0050C000:
		ptr = "	GATAN, INC.";
		break;
	case 0x0050C100:
		ptr = "	GEMFLEX NETWORKS, LTD.";
		break;
	case 0x0050C200:
		ptr = "	IEEE REGISTRATION AUTHORITY";
		break;
	case 0x0050C400:
		ptr = "	IMD";
		break;
	case 0x0050C500:
		ptr = "	ADS TECHNOLOGIES, INC.";
		break;
	case 0x0050C600:
		ptr = "	LOOP TELECOMMUNICATION";
		break;
	case 0x0050C800:
		ptr = "	ADDONICS COMMUNICATIONS, INC.";
		break;
	case 0x0050C900:
		ptr = "	MASPRO DENKOH CORP.";
		break;
	case 0x0050CA00:
		ptr = "	NET TO NET TECHNOLOGIES";
		break;
	case 0x0050CB00:
		ptr = "	JETTER";
		break;
	case 0x0050CC00:
		ptr = "	XYRATEX";
		break;
	case 0x0050CD00:
		ptr = "	DIGIANSWER A/S";
		break;
	case 0x0050CE00:
		ptr = "	LG INTERNATIONAL CORP.";
		break;
	case 0x0050CF00:
		ptr = "	VANLINK COMMUNICATION";
		break;
	case 0x0050D000:
		ptr = "	MINERVA SYSTEMS";
		break;
	case 0x0050D200:
		ptr = "	CANADIAN MARCONI COMPANY";
		break;
	case 0x0050D300:
		ptr = "	DIGITAL AUDIO";
		break;
	case 0x0050D400:
		ptr = "	JOOHONG INFORMATION &";
		break;
	case 0x0050D500:
		ptr = "	AD SYSTEMS CORP.";
		break;
	case 0x0050D600:
		ptr = "	ATLAS COPCO TOOLS AB";
		break;
	case 0x0050D700:
		ptr = "	TELSTRAT";
		break;
	case 0x0050D800:
		ptr = "	UNICORN COMPUTER CORP.";
		break;
	case 0x0050D900:
		ptr = "	ENGETRON-ENGENHARIA ELETRONICA";
		break;
	case 0x0050DA00:
		ptr = "	3COM CORPORATION";
		break;
	case 0x0050DB00:
		ptr = "	CONTEMPORARY CONTROL";
		break;
	case 0x0050DC00:
		ptr = "	TAS TELEFONBAU A. SCHWABE";
		break;
	case 0x0050DD00:
		ptr = "	SERRA SOLDADURA, S.A.";
		break;
	case 0x0050DE00:
		ptr = "	SIGNUM SYSTEMS CORP.";
		break;
	case 0x0050DF00:
		ptr = "	AIRFIBER, INC.";
		break;
	case 0x0050E100:
		ptr = "	NS TECH ELECTRONICS SDN BHD";
		break;
	case 0x0050E200:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x0050E300:
		ptr = "	TELEGATE";
		break;
	case 0x0050E400:
		ptr = "	APPLE COMPUTER, INC.";
		break;
	case 0x0050E600:
		ptr = "	HAKUSAN CORPORATION";
		break;
	case 0x0050E700:
		ptr = "	PARADISE INNOVATIONS (ASIA)";
		break;
	case 0x0050E800:
		ptr = "	NOMADIX INC.";
		break;
	case 0x0050EA00:
		ptr = "	XEL COMMUNICTIONS, INC.";
		break;
	case 0x0050EB00:
		ptr = "	ALPHA-TOP CORPORATION";
		break;
	case 0x0050EC00:
		ptr = "	OLICOM A/S";
		break;
	case 0x0050ED00:
		ptr = "	ANDA NETWORKS";
		break;
	case 0x0050EE00:
		ptr = "	TEK DIGITEL CORPORATION";
		break;
	case 0x0050EF00:
		ptr = "	SPE SYSTEMHAUS GMBH";
		break;
	case 0x0050F100:
		ptr = "	LIBIT SIGNAL PROCESSING, LTD.";
		break;
	case 0x0050F200:
		ptr = "	MICROSOFT CORP.";
		break;
	case 0x0050F300:
		ptr = "	GLOBAL NET INFORMATION CO.,LTD";
		break;
	case 0x0050F400:
		ptr = "	SIGMATEK GMBH & CO. KG";
		break;
	case 0x0050F600:
		ptr = "	PAN-INTERNATIONAL";
		break;
	case 0x0050F700:
		ptr = "	VENTURE MANUFACTURING";
		break;
	case 0x0050F800:
		ptr = "	ENTREGA TECHNOLOGIES, INC.";
		break;
	case 0x0050FA00:
		ptr = "	OXTEL, LTD.";
		break;
	case 0x0050FB00:
		ptr = "	VSK ELECTRONICS";
		break;
	case 0x0050FC00:
		ptr = "	EDIMAX TECHNOLOGY CO., LTD.";
		break;
	case 0x0050FD00:
		ptr = "	 ISIONCOMM CO., LTD.";
		break;
	case 0x0050FE00:
		ptr = "	PCTVNET ASA";
		break;
	case 0x0050FF00:
		ptr = "	HAKKO ELECTRONICS CO., LTD.";
		break;
	case 0x00600000:
		ptr = "	XYCOM INC.";
		break;
	case 0x00600100:
		ptr = "	INNOSYS, INC.";
		break;
	case 0x00600200:
		ptr = "	SCREEN SUBTITLING SYSTEMS, LTD";
		break;
	case 0x00600300:
		ptr = "	TERAOKA WEIGH SYSTEM PTE, LTD.";
		break;
	case 0x00600400:
		ptr = "	COMPUTADORES MODULARES SA";
		break;
	case 0x00600500:
		ptr = "	FEEDBACK DATA LTD.";
		break;
	case 0x00600600:
		ptr = "	SOTEC CO., LTD";
		break;
	case 0x00600700:
		ptr = "	ACRES GAMING, INC.";
		break;
	case 0x00600800:
		ptr = "	3COM CORPORATION";
		break;
	case 0x00600900:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00600A00:
		ptr = "	SORD COMPUTER CORPORATION";
		break;
	case 0x00600B00:
		ptr = "	LOGWARE GMBH";
		break;
	case 0x00600C00:
		ptr = "	APPLIED DATA SYSTEMS, INC.";
		break;
	case 0x00600D00:
		ptr = "	MICRODESIGN GMBH";
		break;
	case 0x00600E00:
		ptr = "	WAVENET INTERNATIONAL, INC.";
		break;
	case 0x00600F00:
		ptr = "	WESTELL, INC.";
		break;
	case 0x00601000:
		ptr = "	NETWORK MACHINES, INC.";
		break;
	case 0x00601100:
		ptr = "	CRYSTAL SEMICONDUCTOR CORP.";
		break;
	case 0x00601200:
		ptr = "	POWER COMPUTING CORPORATION";
		break;
	case 0x00601300:
		ptr = "	NETSTAL MASCHINEN AG";
		break;
	case 0x00601400:
		ptr = "	EDEC CO., LTD.";
		break;
	case 0x00601500:
		ptr = "	NET2NET CORPORATION";
		break;
	case 0x00601600:
		ptr = "	CLARIION";
		break;
	case 0x00601700:
		ptr = "	TOKIMEC INC.";
		break;
	case 0x00601800:
		ptr = "	STELLAR ONE CORPORATION";
		break;
	case 0x00601900:
		ptr = "	BOEHRINGER MANNHEIM CORP.";
		break;
	case 0x00601A00:
		ptr = "	KEITHLEY INSTRUMENTS";
		break;
	case 0x00601B00:
		ptr = "	MESA ELECTRONICS";
		break;
	case 0x00601C00:
		ptr = "	TELXON CORPORATION";
		break;
	case 0x00601D00:
		ptr = "	LUCENT TECHNOLOGIES";
		break;
	case 0x00601E00:
		ptr = "	SOFTLAB, INC.";
		break;
	case 0x00601F00:
		ptr = "	STALLION TECHNOLOGIES";
		break;
	case 0x00602000:
		ptr = "	PIVOTAL NETWORKING, INC.";
		break;
	case 0x00602100:
		ptr = "	DSC CORPORATION";
		break;
	case 0x00602200:
		ptr = "	VICOM SYSTEMS, INC.";
		break;
	case 0x00602300:
		ptr = "	PERICOM SEMICONDUCTOR CORP.";
		break;
	case 0x00602400:
		ptr = "	GRADIENT TECHNOLOGIES, INC.";
		break;
	case 0x00602500:
		ptr = "	ACTIVE IMAGING PLC";
		break;
	case 0x00602600:
		ptr = "	VIKING COMPONENTS, INC.";
		break;
	case 0x00602700:
		ptr = "	Superior Modular Products";
		break;
	case 0x00602800:
		ptr = "	MACROVISION CORPORATION";
		break;
	case 0x00602900:
		ptr = "	CARY PERIPHERALS INC.";
		break;
	case 0x00602A00:
		ptr = "	SYMICRON COMPUTER";
		break;
	case 0x00602B00:
		ptr = "	PEAK AUDIO";
		break;
	case 0x00602C00:
		ptr = "	LINX DATA TERMINALS, INC.";
		break;
	case 0x00602D00:
		ptr = "	ALERTON TECHNOLOGIES, INC.";
		break;
	case 0x00602E00:
		ptr = "	CYCLADES CORPORATION";
		break;
	case 0x00602F00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00603000:
		ptr = "	VILLAGE TRONIC";
		break;
	case 0x00603100:
		ptr = "	HRK SYSTEMS";
		break;
	case 0x00603200:
		ptr = "	I-CUBE, INC.";
		break;
	case 0x00603300:
		ptr = "	ACUITY IMAGING, INC.";
		break;
	case 0x00603400:
		ptr = "	ROBERT BOSCH GMBH";
		break;
	case 0x00603500:
		ptr = "	DALLAS SEMICONDUCTOR, INC.";
		break;
	case 0x00603600:
		ptr = "	AUSTRIAN RESEARCH CENTER";
		break;
	case 0x00603700:
		ptr = "	PHILIPS SEMICONDUCTORS";
		break;
	case 0x00603800:
		ptr = "	NORTEL";
		break;
	case 0x00603900:
		ptr = "	SANCOM TECHNOLOGY, INC.";
		break;
	case 0x00603A00:
		ptr = "	QUICK CONTROLS LTD.";
		break;
	case 0x00603B00:
		ptr = "	AMTEC SPA";
		break;
	case 0x00603C00:
		ptr = "	HAGIWARA SYS-COM CO., LTD.";
		break;
	case 0x00603D00:
		ptr = "	3CX";
		break;
	case 0x00603E00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00603F00:
		ptr = "	PATAPSCO DESIGNS";
		break;
	case 0x00604000:
		ptr = "	NETRO CORP.";
		break;
	case 0x00604100:
		ptr = "	3A INTERNATIONAL, INC.";
		break;
	case 0x00604200:
		ptr = "	TKS (USA), INC.";
		break;
	case 0x00604300:
		ptr = "	COMSOFT SYSTEMS, INC.";
		break;
	case 0x00604400:
		ptr = "	LITTON/POLY-SCIENTIFIC";
		break;
	case 0x00604500:
		ptr = "	PATHLIGHT TECHNOLOGIES";
		break;
	case 0x00604600:
		ptr = "	VMETRO, INC.";
		break;
	case 0x00604700:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00604800:
		ptr = "	EMC CORPORATION";
		break;
	case 0x00604900:
		ptr = "	VINA TECHNOLOGIES";
		break;
	case 0x00604A00:
		ptr = "	SAIC IDEAS GROUP";
		break;
	case 0x00604B00:
		ptr = "	BIODATA GMBH";
		break;
	case 0x00604C00:
		ptr = "	SAT";
		break;
	case 0x00604D00:
		ptr = "	MMC NETWORKS, INC.";
		break;
	case 0x00604E00:
		ptr = "	CYCLE COMPUTER CORPORATION";
		break;
	case 0x00604F00:
		ptr = "	SUZUKI MFG. CO., LTD.";
		break;
	case 0x00605000:
		ptr = "	INTERNIX INC.";
		break;
	case 0x00605100:
		ptr = "	QUALITY SEMICONDUCTOR";
		break;
	case 0x00605200:
		ptr = "	PERIPHERALS ENTERPRISE CO., L.";
		break;
	case 0x00605300:
		ptr = "	TOYODA MACHINE WORKS, LTD.";
		break;
	case 0x00605400:
		ptr = "	CONTROLWARE GMBH";
		break;
	case 0x00605500:
		ptr = "	CORNELL UNIVERSITY";
		break;
	case 0x00605600:
		ptr = "	NETWORK TOOLS, INC.";
		break;
	case 0x00605700:
		ptr = "	MURATA MANUFACTURING CO., LTD.";
		break;
	case 0x00605800:
		ptr = "	COPPER MOUNTAIN";
		break;
	case 0x00605900:
		ptr = "	TECHNICAL COMMUNICATIONS CORP.";
		break;
	case 0x00605A00:
		ptr = "	CELCORE, INC.";
		break;
	case 0x00605B00:
		ptr = "	INTRASERVER TECHNOLOGY INC.";
		break;
	case 0x00605C00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00605D00:
		ptr = "	SCANIVALVE CORP.";
		break;
	case 0x00605E00:
		ptr = "	LIBERTY TECHNOLOGY NETWORKING";
		break;
	case 0x00605F00:
		ptr = "	NIPPON UNISOFT CORPORATION";
		break;
	case 0x00606000:
		ptr = "	DAWNING TECHNOLOGIES, INC.";
		break;
	case 0x00606100:
		ptr = "	WHISTLE COMMUNICATIONS CORP.";
		break;
	case 0x00606200:
		ptr = "	TELESYNC, INC.";
		break;
	case 0x00606300:
		ptr = "	PSION DACOM PLC.";
		break;
	case 0x00606400:
		ptr = "	NETCOMM LIMITED";
		break;
	case 0x00606500:
		ptr = "	BERNECKER & RAINER";
		break;
	case 0x00606600:
		ptr = "	LACROIX TECHNOLGIE";
		break;
	case 0x00606700:
		ptr = "	ACER NETXUS INC.";
		break;
	case 0x00606800:
		ptr = "	EICON TECHNOLOGY CORPORATION";
		break;
	case 0x00606900:
		ptr = "	BROCADE COMMUNICATIONS SYSTEMS";
		break;
	case 0x00606A00:
		ptr = "	MITSUBISHI WIRELESS COMM. INC.";
		break;
	case 0x00606B00:
		ptr = "	AICHI ELECTRONICS CO.,LTD.";
		break;
	case 0x00606C00:
		ptr = "	ARESCOM";
		break;
	case 0x00606D00:
		ptr = "	DIGITAL EQUIPMENT CORP.";
		break;
	case 0x00606E00:
		ptr = "	DAVICOM SEMICONDUCTOR, INC.";
		break;
	case 0x00606F00:
		ptr = "	CLARION CORPORATION OF AMERICA";
		break;
	case 0x00607000:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00607100:
		ptr = "	MIDAS LAB, INC.";
		break;
	case 0x00607200:
		ptr = "	VXL INSTRUMENTS, LIMITED";
		break;
	case 0x00607300:
		ptr = "	REDCREEK COMMUNICATIONS, INC.";
		break;
	case 0x00607400:
		ptr = "	QSC AUDIO PRODUCTS";
		break;
	case 0x00607500:
		ptr = "	PENTEK, INC.";
		break;
	case 0x00607600:
		ptr = "	SCHLUMBERGER TECHNOLOGIES";
		break;
	case 0x00607700:
		ptr = "	PRISA NETWORKS";
		break;
	case 0x00607800:
		ptr = "	POWER MEASUREMENT LTD.";
		break;
	case 0x00607900:
		ptr = "	WAVEPHORE NETWORKS, INC.";
		break;
	case 0x00607A00:
		ptr = "	DVS GMBH";
		break;
	case 0x00607B00:
		ptr = "	FORE SYSTEMS, INC.";
		break;
	case 0x00607C00:
		ptr = "	WAVEACCESS, LTD.";
		break;
	case 0x00607D00:
		ptr = "	SENTIENT NETWORKS INC.";
		break;
	case 0x00607E00:
		ptr = "	GIGALABS, INC.";
		break;
	case 0x00607F00:
		ptr = "	AURORA TECHNOLOGIES, INC.";
		break;
	case 0x00608000:
		ptr = "	MICROTRONIX DATACOM LTD.";
		break;
	case 0x00608100:
		ptr = "	TV/COM INTERNATIONAL";
		break;
	case 0x00608200:
		ptr = "	NOVALINK TECHNOLOGIES, INC.";
		break;
	case 0x00608300:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00608400:
		ptr = "	DIGITAL VIDEO";
		break;
	case 0x00608500:
		ptr = "	STORAGE CONCEPTS";
		break;
	case 0x00608600:
		ptr = "	LOGIC REPLACEMENT TECH. LTD.";
		break;
	case 0x00608700:
		ptr = "	KANSAI ELECTRIC CO., LTD.";
		break;
	case 0x00608800:
		ptr = "	WHITE MOUNTAIN DSP, INC.";
		break;
	case 0x00608900:
		ptr = "	XATA";
		break;
	case 0x00608A00:
		ptr = "	CITADEL COMPUTER";
		break;
	case 0x00608B00:
		ptr = "	CONFERTECH INTERNATIONAL";
		break;
	case 0x00608C00:
		ptr = "	3COM CORPORATION";
		break;
	case 0x00608D00:
		ptr = "	UNIPULSE CORP.";
		break;
	case 0x00608E00:
		ptr = "	HE ELECTRONICS, TECHNOLOGIE &";
		break;
	case 0x00608F00:
		ptr = "	TEKRAM TECHNOLOGY CO., LTD.";
		break;
	case 0x00609000:
		ptr = "	ABLE COMMUNICATIONS, INC.";
		break;
	case 0x00609100:
		ptr = "	FIRST PACIFIC NETWORKS, INC.";
		break;
	case 0x00609200:
		ptr = "	MICRO/SYS, INC.";
		break;
	case 0x00609300:
		ptr = "	VARIAN";
		break;
	case 0x00609400:
		ptr = "	IBM CORP.";
		break;
	case 0x00609500:
		ptr = "	ACCU-TIME SYSTEMS, INC.";
		break;
	case 0x00609600:
		ptr = "	T.S. MICROTECH INC.";
		break;
	case 0x00609700:
		ptr = "	3COM CORPORATION";
		break;
	case 0x00609800:
		ptr = "	HT COMMUNICATIONS";
		break;
	case 0x00609900:
		ptr = "	LAN MEDIA CORPORATION";
		break;
	case 0x00609A00:
		ptr = "	NJK TECHNO CO.";
		break;
	case 0x00609B00:
		ptr = "	ASTRO-MED, INC.";
		break;
	case 0x00609C00:
		ptr = "	PERKIN-ELMER CORPORATION";
		break;
	case 0x00609D00:
		ptr = "	PMI FOOD EQUIPMENT GROUP";
		break;
	case 0x00609E00:
		ptr = "	X3 - INFORMATION TECHNOLOGY";
		break;
	case 0x00609F00:
		ptr = "	PHAST CORPORATION";
		break;
	case 0x0060A000:
		ptr = "	SWITCHED NETWORK";
		break;
	case 0x0060A100:
		ptr = "	VPNET";
		break;
	case 0x0060A200:
		ptr = "	NIHON UNISYS LIMITED CO.";
		break;
	case 0x0060A300:
		ptr = "	CONTINUUM TECHNOLOGY CORP.";
		break;
	case 0x0060A400:
		ptr = "	GRINAKER SYSTEM TECHNOLOGIES";
		break;
	case 0x0060A500:
		ptr = "	PERFORMANCE TELECOM CORP.";
		break;
	case 0x0060A600:
		ptr = "	PARTICLE MEASURING SYSTEMS";
		break;
	case 0x0060A700:
		ptr = "	MICROSENS GMBH & CO. KG";
		break;
	case 0x0060A800:
		ptr = "	TIDOMAT AB";
		break;
	case 0x0060A900:
		ptr = "	GESYTEC MBH";
		break;
	case 0x0060AA00:
		ptr = "	INTELLIGENT DEVICES INC. (IDI)";
		break;
	case 0x0060AB00:
		ptr = "	LARSCOM INCORPORATED";
		break;
	case 0x0060AC00:
		ptr = "	RESILIENCE CORPORATION";
		break;
	case 0x0060AD00:
		ptr = "	MEGACHIPS CORPORATION";
		break;
	case 0x0060AE00:
		ptr = "	TRIO INFORMATION SYSTEMS AB";
		break;
	case 0x0060AF00:
		ptr = "	PACIFIC MICRO DATA, INC.";
		break;
	case 0x0060B000:
		ptr = "	HEWLETT-PACKARD CO.";
		break;
	case 0x0060B100:
		ptr = "	INPUT/OUTPUT, INC.";
		break;
	case 0x0060B200:
		ptr = "	PROCESS CONTROL CORP.";
		break;
	case 0x0060B300:
		ptr = "	Z-COM, INC.";
		break;
	case 0x0060B400:
		ptr = "	GLENAYRE R&D INC.";
		break;
	case 0x0060B500:
		ptr = "	KEBA GMBH";
		break;
	case 0x0060B600:
		ptr = "	LAND COMPUTER CO., LTD.";
		break;
	case 0x0060B700:
		ptr = "	CHANNELMATIC, INC.";
		break;
	case 0x0060B800:
		ptr = "	CORELIS INC.";
		break;
	case 0x0060B900:
		ptr = "	NITSUKO CORPORATION";
		break;
	case 0x0060BA00:
		ptr = "	SAHARA NETWORKS, INC.";
		break;
	case 0x0060BB00:
		ptr = "	CABLETRON - NETLINK, INC.";
		break;
	case 0x0060BC00:
		ptr = "	KEUNYOUNG ELECTRONICS &";
		break;
	case 0x0060BD00:
		ptr = "	HUBBELL-PULSECOM";
		break;
	case 0x0060BE00:
		ptr = "	WEBTRONICS";
		break;
	case 0x0060BF00:
		ptr = "	MACRAIGOR SYSTEMS, INC.";
		break;
	case 0x0060C000:
		ptr = "	NERA AS";
		break;
	case 0x0060C100:
		ptr = "	WAVESPAN CORPORATION";
		break;
	case 0x0060C200:
		ptr = "	MPL AG";
		break;
	case 0x0060C300:
		ptr = "	NETVISION CORPORATION";
		break;
	case 0x0060C400:
		ptr = "	SOLITON SYSTEMS K.K.";
		break;
	case 0x0060C500:
		ptr = "	ANCOT CORP.";
		break;
	case 0x0060C600:
		ptr = "	DCS AG";
		break;
	case 0x0060C700:
		ptr = "	AMATI COMMUNICATIONS CORP.";
		break;
	case 0x0060C800:
		ptr = "	KUKA WELDING SYSTEMS & ROBOTS";
		break;
	case 0x0060C900:
		ptr = "	CONTROLNET, INC.";
		break;
	case 0x0060CA00:
		ptr = "	HARMONIC SYSTEMS INCORPORATED";
		break;
	case 0x0060CB00:
		ptr = "	HITACHI ZOSEN CORPORATION";
		break;
	case 0x0060CC00:
		ptr = "	EMTRAK, INCORPORATED";
		break;
	case 0x0060CD00:
		ptr = "	VIDEOSERVER, INC.";
		break;
	case 0x0060CE00:
		ptr = "	ACCLAIM COMMUNICATIONS";
		break;
	case 0x0060CF00:
		ptr = "	ALTEON NETWORKS, INC.";
		break;
	case 0x0060D000:
		ptr = "	SNMP RESEARCH INCORPORATED";
		break;
	case 0x0060D100:
		ptr = "	CASCADE COMMUNICATIONS";
		break;
	case 0x0060D200:
		ptr = "	LUCENT TECHNOLOGIES TAIWAN";
		break;
	case 0x0060D300:
		ptr = "	AT&T";
		break;
	case 0x0060D400:
		ptr = "	ELDAT COMMUNICATION LTD.";
		break;
	case 0x0060D500:
		ptr = "	MIYACHI TECHNOS CORP.";
		break;
	case 0x0060D600:
		ptr = "	NOVATEL WIRELESS TECHNOLOGIES";
		break;
	case 0x0060D700:
		ptr = "	ECOLE POLYTECHNIQUE FEDERALE";
		break;
	case 0x0060D800:
		ptr = "	ELMIC SYSTEMS, INC.";
		break;
	case 0x0060D900:
		ptr = "	TRANSYS NETWORKS INC.";
		break;
	case 0x0060DA00:
		ptr = "	JBM ELECTRONICS CO.";
		break;
	case 0x0060DB00:
		ptr = "	NTP ELEKTRONIK A/S";
		break;
	case 0x0060DC00:
		ptr = "	TOYO COMMUNICATION EQUIPMENT";
		break;
	case 0x0060DD00:
		ptr = "	MYRICOM, INC.";
		break;
	case 0x0060DE00:
		ptr = "	KAYSER-THREDE GMBH";
		break;
	case 0x0060DF00:
		ptr = "	INRANGE TECHNOLOGIES CORP.";
		break;
	case 0x0060E000:
		ptr = "	AXIOM TECHNOLOGY CO., LTD.";
		break;
	case 0x0060E100:
		ptr = "	ORCKIT COMMUNICATIONS LTD.";
		break;
	case 0x0060E200:
		ptr = "	QUEST ENGINEERING & DEV.";
		break;
	case 0x0060E300:
		ptr = "	ARBIN INSTRUMENTS";
		break;
	case 0x0060E400:
		ptr = "	COMPUSERVE, INC.";
		break;
	case 0x0060E500:
		ptr = "	FUJI AUTOMATION CO., LTD.";
		break;
	case 0x0060E600:
		ptr = "	SHOMITI SYSTEMS INCORPORATED";
		break;
	case 0x0060E700:
		ptr = "	RANDATA";
		break;
	case 0x0060E800:
		ptr = "	HITACHI COMPUTER PRODUCTS";
		break;
	case 0x0060E900:
		ptr = "	ATOP TECHNOLOGIES, INC.";
		break;
	case 0x0060EA00:
		ptr = "	STREAMLOGIC";
		break;
	case 0x0060EB00:
		ptr = "	FOURTHTRACK SYSTEMS";
		break;
	case 0x0060EC00:
		ptr = "	HERMARY OPTO ELECTRONICS INC.";
		break;
	case 0x0060ED00:
		ptr = "	RICARDO TEST AUTOMATION LTD.";
		break;
	case 0x0060EE00:
		ptr = "	APOLLO";
		break;
	case 0x0060EF00:
		ptr = "	FLYTECH TECHNOLOGY CO., LTD.";
		break;
	case 0x0060F000:
		ptr = "	JOHNSON & JOHNSON MEDICAL, INC";
		break;
	case 0x0060F100:
		ptr = "	EXP COMPUTER, INC.";
		break;
	case 0x0060F200:
		ptr = "	LASERGRAPHICS, INC.";
		break;
	case 0x0060F300:
		ptr = "	NETCOM SYSTEMS, INC.";
		break;
	case 0x0060F400:
		ptr = "	ADVANCED COMPUTER SOLUTIONS,";
		break;
	case 0x0060F500:
		ptr = "	ICON WEST, INC.";
		break;
	case 0x0060F600:
		ptr = "	NEXTEST COMMUNICATION";
		break;
	case 0x0060F700:
		ptr = "	DATAFUSION SYSTEMS";
		break;
	case 0x0060F800:
		ptr = "	LORAN INTERNATIONAL TECHN. INC";
		break;
	case 0x0060F900:
		ptr = "	DIAMOND LANE COMMUNICATIONS";
		break;
	case 0x0060FA00:
		ptr = "	EDUCATIONAL TECHNOLOGY";
		break;
	case 0x0060FB00:
		ptr = "	PACKETEER, INC.";
		break;
	case 0x0060FC00:
		ptr = "	CONSERVATION THROUGH";
		break;
	case 0x0060FD00:
		ptr = "	NETICS, INC.";
		break;
	case 0x0060FE00:
		ptr = "	LYNX SYSTEM DEVELOPERS, INC.";
		break;
	case 0x0060FF00:
		ptr = "	QUVIS, INC.";
		break;
	case 0x0070B000:
		ptr = "	M/A-COM INC. COMPANIES";
		break;
	case 0x0070B300:
		ptr = "	DATA RECALL LTD.";
		break;
	case 0x00800000:
		ptr = "	MULTITECH SYSTEMS, INC.";
		break;
	case 0x00800100:
		ptr = "	PERIPHONICS CORPORATION";
		break;
	case 0x00800200:
		ptr = "	SATELCOM (UK) LTD";
		break;
	case 0x00800300:
		ptr = "	HYTEC ELECTRONICS LTD.";
		break;
	case 0x00800400:
		ptr = "	ANTLOW COMMUNICATIONS, LTD.";
		break;
	case 0x00800500:
		ptr = "	CACTUS COMPUTER INC.";
		break;
	case 0x00800600:
		ptr = "	COMPUADD CORPORATION";
		break;
	case 0x00800700:
		ptr = "	DLOG NC-SYSTEME";
		break;
	case 0x00800800:
		ptr = "	DYNATECH COMPUTER SYSTEMS";
		break;
	case 0x00800900:
		ptr = "	JUPITER SYSTEMS, INC.";
		break;
	case 0x00800A00:
		ptr = "	JAPAN COMPUTER CORP.";
		break;
	case 0x00800B00:
		ptr = "	CSK CORPORATION";
		break;
	case 0x00800C00:
		ptr = "	VIDECOM LIMITED";
		break;
	case 0x00800D00:
		ptr = "	VOSSWINKEL F.U.";
		break;
	case 0x00800E00:
		ptr = "	ATLANTIX CORPORATION";
		break;
	case 0x00800F00:
		ptr = "	STANDARD MICROSYSTEMS";
		break;
	case 0x00801000:
		ptr = "	COMMODORE INTERNATIONAL";
		break;
	case 0x00801100:
		ptr = "	DIGITAL SYSTEMS INT'L. INC.";
		break;
	case 0x00801200:
		ptr = "	INTEGRATED MEASUREMENT SYSTEMS";
		break;
	case 0x00801300:
		ptr = "	THOMAS-CONRAD CORPORATION";
		break;
	case 0x00801400:
		ptr = "	ESPRIT SYSTEMS";
		break;
	case 0x00801500:
		ptr = "	SEIKO SYSTEMS, INC.";
		break;
	case 0x00801600:
		ptr = "	WANDEL AND GOLTERMANN";
		break;
	case 0x00801700:
		ptr = "	PFU LIMITED";
		break;
	case 0x00801800:
		ptr = "	KOBE STEEL, LTD.";
		break;
	case 0x00801900:
		ptr = "	DAYNA COMMUNICATIONS, INC.";
		break;
	case 0x00801A00:
		ptr = "	BELL ATLANTIC";
		break;
	case 0x00801B00:
		ptr = "	KODIAK TECHNOLOGY";
		break;
	case 0x00801C00:
		ptr = "	NEWPORT SYSTEMS SOLUTIONS";
		break;
	case 0x00801D00:
		ptr = "	INTEGRATED INFERENCE MACHINES";
		break;
	case 0x00801E00:
		ptr = "	XINETRON, INC.";
		break;
	case 0x00801F00:
		ptr = "	KRUPP ATLAS ELECTRONIK GMBH";
		break;
	case 0x00802000:
		ptr = "	NETWORK PRODUCTS";
		break;
	case 0x00802100:
		ptr = "	NEWBRIDGE RESEARCH CORP.";
		break;
	case 0x00802200:
		ptr = "	SCAN-OPTICS";
		break;
	case 0x00802300:
		ptr = "	INTEGRATED BUSINESS NETWORKS";
		break;
	case 0x00802400:
		ptr = "	KALPANA, INC.";
		break;
	case 0x00802500:
		ptr = "	STOLLMANN GMBH";
		break;
	case 0x00802600:
		ptr = "	NETWORK PRODUCTS CORPORATION";
		break;
	case 0x00802700:
		ptr = "	ADAPTIVE SYSTEMS, INC.";
		break;
	case 0x00802800:
		ptr = "	TRADPOST (HK) LTD";
		break;
	case 0x00802900:
		ptr = "	EAGLE TECHNOLOGY, INC.";
		break;
	case 0x00802A00:
		ptr = "	TEST SYSTEMS & SIMULATIONS INC";
		break;
	case 0x00802B00:
		ptr = "	INTEGRATED MARKETING CO";
		break;
	case 0x00802C00:
		ptr = "	THE SAGE GROUP PLC";
		break;
	case 0x00802D00:
		ptr = "	XYLOGICS INC";
		break;
	case 0x00802E00:
		ptr = "	CASTLE ROCK COMPUTING";
		break;
	case 0x00802F00:
		ptr = "	NATIONAL INSTRUMENTS CORP.";
		break;
	case 0x00803000:
		ptr = "	NEXUS ELECTRONICS";
		break;
	case 0x00803100:
		ptr = "	BASYS, CORP.";
		break;
	case 0x00803200:
		ptr = "	ACCESS CO., LTD.";
		break;
	case 0x00803300:
		ptr = "	FORMATION, INC.";
		break;
	case 0x00803400:
		ptr = "	SMT GOUPIL";
		break;
	case 0x00803500:
		ptr = "	TECHNOLOGY WORKS, INC.";
		break;
	case 0x00803600:
		ptr = "	REFLEX MANUFACTURING SYSTEMS";
		break;
	case 0x00803700:
		ptr = "	Ericsson Group";
		break;
	case 0x00803800:
		ptr = "	DATA RESEARCH & APPLICATIONS";
		break;
	case 0x00803900:
		ptr = "	ALCATEL STC AUSTRALIA";
		break;
	case 0x00803A00:
		ptr = "	VARITYPER, INC.";
		break;
	case 0x00803B00:
		ptr = "	APT COMMUNICATIONS, INC.";
		break;
	case 0x00803C00:
		ptr = "	TVS ELECTRONICS LTD";
		break;
	case 0x00803D00:
		ptr = "	SURIGIKEN CO.,  LTD.";
		break;
	case 0x00803E00:
		ptr = "	SYNERNETICS";
		break;
	case 0x00803F00:
		ptr = "	TATUNG COMPANY";
		break;
	case 0x00804000:
		ptr = "	JOHN FLUKE MANUFACTURING CO.";
		break;
	case 0x00804100:
		ptr = "	VEB KOMBINAT ROBOTRON";
		break;
	case 0x00804200:
		ptr = "	FORCE COMPUTERS";
		break;
	case 0x00804300:
		ptr = "	NETWORLD, INC.";
		break;
	case 0x00804400:
		ptr = "	SYSTECH COMPUTER CORP.";
		break;
	case 0x00804500:
		ptr = "	MATSUSHITA ELECTRIC IND. CO";
		break;
	case 0x00804600:
		ptr = "	UNIVERSITY OF TORONTO";
		break;
	case 0x00804700:
		ptr = "	IN-NET CORP.";
		break;
	case 0x00804800:
		ptr = "	COMPEX INCORPORATED";
		break;
	case 0x00804900:
		ptr = "	NISSIN ELECTRIC CO., LTD.";
		break;
	case 0x00804A00:
		ptr = "	PRO-LOG";
		break;
	case 0x00804B00:
		ptr = "	EAGLE TECHNOLOGIES PTY.LTD.";
		break;
	case 0x00804C00:
		ptr = "	CONTEC CO., LTD.";
		break;
	case 0x00804D00:
		ptr = "	CYCLONE MICROSYSTEMS, INC.";
		break;
	case 0x00804E00:
		ptr = "	APEX COMPUTER COMPANY";
		break;
	case 0x00804F00:
		ptr = "	DAIKIN INDUSTRIES, LTD.";
		break;
	case 0x00805000:
		ptr = "	ZIATECH CORPORATION";
		break;
	case 0x00805100:
		ptr = "	FIBERMUX";
		break;
	case 0x00805200:
		ptr = "	TECHNICALLY ELITE CONCEPTS";
		break;
	case 0x00805300:
		ptr = "	INTELLICOM, INC.";
		break;
	case 0x00805400:
		ptr = "	FRONTIER TECHNOLOGIES CORP.";
		break;
	case 0x00805500:
		ptr = "	FERMILAB";
		break;
	case 0x00805600:
		ptr = "	SPHINX ELEKTRONIK GMBH";
		break;
	case 0x00805700:
		ptr = "	ADSOFT, LTD.";
		break;
	case 0x00805800:
		ptr = "	PRINTER SYSTEMS CORPORATION";
		break;
	case 0x00805900:
		ptr = "	STANLEY ELECTRIC CO., LTD";
		break;
	case 0x00805A00:
		ptr = "	TULIP COMPUTERS INTERNAT'L B.V";
		break;
	case 0x00805B00:
		ptr = "	CONDOR SYSTEMS, INC.";
		break;
	case 0x00805C00:
		ptr = "	AGILIS CORPORATION";
		break;
	case 0x00805D00:
		ptr = "	CANSTAR";
		break;
	case 0x00805E00:
		ptr = "	LSI LOGIC CORPORATION";
		break;
	case 0x00805F00:
		ptr = "	COMPAQ COMPUTER CORPORATION";
		break;
	case 0x00806000:
		ptr = "	NETWORK INTERFACE CORPORATION";
		break;
	case 0x00806100:
		ptr = "	LITTON SYSTEMS, INC.";
		break;
	case 0x00806200:
		ptr = "	INTERFACE  CO.";
		break;
	case 0x00806300:
		ptr = "	RICHARD HIRSCHMANN GMBH & CO.";
		break;
	case 0x00806400:
		ptr = "	WYSE TECHNOLOGY";
		break;
	case 0x00806500:
		ptr = "	CYBERGRAPHIC SYSTEMS PTY LTD.";
		break;
	case 0x00806600:
		ptr = "	ARCOM CONTROL SYSTEMS, LTD.";
		break;
	case 0x00806700:
		ptr = "	SQUARE D COMPANY";
		break;
	case 0x00806800:
		ptr = "	YAMATECH SCIENTIFIC LTD.";
		break;
	case 0x00806900:
		ptr = "	COMPUTONE SYSTEMS";
		break;
	case 0x00806A00:
		ptr = "	ERI (EMPAC RESEARCH INC.)";
		break;
	case 0x00806B00:
		ptr = "	SCHMID TELECOMMUNICATION";
		break;
	case 0x00806C00:
		ptr = "	CEGELEC PROJECTS LTD";
		break;
	case 0x00806D00:
		ptr = "	CENTURY SYSTEMS CORP.";
		break;
	case 0x00806E00:
		ptr = "	NIPPON STEEL CORPORATION";
		break;
	case 0x00806F00:
		ptr = "	ONELAN LTD.";
		break;
	case 0x00807000:
		ptr = "	COMPUTADORAS MICRON";
		break;
	case 0x00807100:
		ptr = "	SAI TECHNOLOGY";
		break;
	case 0x00807200:
		ptr = "	MICROPLEX SYSTEMS LTD.";
		break;
	case 0x00807300:
		ptr = "	DWB ASSOCIATES";
		break;
	case 0x00807400:
		ptr = "	FISHER CONTROLS";
		break;
	case 0x00807500:
		ptr = "	PARSYTEC GMBH";
		break;
	case 0x00807600:
		ptr = "	MCNC";
		break;
	case 0x00807700:
		ptr = "	BROTHER INDUSTRIES, LTD.";
		break;
	case 0x00807800:
		ptr = "	PRACTICAL PERIPHERALS, INC.";
		break;
	case 0x00807900:
		ptr = "	MICROBUS DESIGNS LTD.";
		break;
	case 0x00807A00:
		ptr = "	AITECH SYSTEMS LTD.";
		break;
	case 0x00807B00:
		ptr = "	ARTEL COMMUNICATIONS CORP.";
		break;
	case 0x00807C00:
		ptr = "	FIBERCOM, INC.";
		break;
	case 0x00807D00:
		ptr = "	EQUINOX SYSTEMS INC.";
		break;
	case 0x00807E00:
		ptr = "	SOUTHERN PACIFIC LTD.";
		break;
	case 0x00807F00:
		ptr = "	DY-4 INCORPORATED";
		break;
	case 0x00808000:
		ptr = "	DATAMEDIA CORPORATION";
		break;
	case 0x00808100:
		ptr = "	KENDALL SQUARE RESEARCH CORP.";
		break;
	case 0x00808200:
		ptr = "	PEP MODULAR COMPUTERS GMBH";
		break;
	case 0x00808300:
		ptr = "	AMDAHL";
		break;
	case 0x00808400:
		ptr = "	THE CLOUD INC.";
		break;
	case 0x00808500:
		ptr = "	H-THREE SYSTEMS CORPORATION";
		break;
	case 0x00808600:
		ptr = "	COMPUTER GENERATION INC.";
		break;
	case 0x00808700:
		ptr = "	OKI ELECTRIC INDUSTRY CO., LTD";
		break;
	case 0x00808800:
		ptr = "	VICTOR COMPANY OF JAPAN, LTD.";
		break;
	case 0x00808900:
		ptr = "	TECNETICS (PTY) LTD.";
		break;
	case 0x00808A00:
		ptr = "	SUMMIT MICROSYSTEMS CORP.";
		break;
	case 0x00808B00:
		ptr = "	DACOLL LIMITED";
		break;
	case 0x00808C00:
		ptr = "	FRONTIER SOFTWARE DEVELOPMENT";
		break;
	case 0x00808D00:
		ptr = "	WESTCOAST TECHNOLOGY B.V.";
		break;
	case 0x00808E00:
		ptr = "	RADSTONE TECHNOLOGY";
		break;
	case 0x00808F00:
		ptr = "	C. ITOH ELECTRONICS, INC.";
		break;
	case 0x00809000:
		ptr = "	MICROTEK INTERNATIONAL, INC.";
		break;
	case 0x00809100:
		ptr = "	TOKYO ELECTRIC CO.,LTD";
		break;
	case 0x00809200:
		ptr = "	JAPAN COMPUTER INDUSTRY, INC.";
		break;
	case 0x00809300:
		ptr = "	XYRON CORPORATION";
		break;
	case 0x00809400:
		ptr = "	ALFA LAVAL AUTOMATION AB";
		break;
	case 0x00809500:
		ptr = "	BASIC MERTON HANDELSGES.M.B.H.";
		break;
	case 0x00809600:
		ptr = "	HUMAN DESIGNED SYSTEMS, INC.";
		break;
	case 0x00809700:
		ptr = "	CENTRALP AUTOMATISMES";
		break;
	case 0x00809800:
		ptr = "	TDK CORPORATION";
		break;
	case 0x00809900:
		ptr = "	KLOCKNER MOELLER IPC";
		break;
	case 0x00809A00:
		ptr = "	NOVUS NETWORKS LTD";
		break;
	case 0x00809B00:
		ptr = "	JUSTSYSTEM CORPORATION";
		break;
	case 0x00809C00:
		ptr = "	LUXCOM, INC.";
		break;
	case 0x00809D00:
		ptr = "	Commscraft Ltd.";
		break;
	case 0x00809E00:
		ptr = "	DATUS GMBH";
		break;
	case 0x00809F00:
		ptr = "	ALCATEL BUSINESS SYSTEMS";
		break;
	case 0x0080A000:
		ptr = "	EDISA HEWLETT PACKARD S/A";
		break;
	case 0x0080A100:
		ptr = "	MICROTEST, INC.";
		break;
	case 0x0080A200:
		ptr = "	CREATIVE ELECTRONIC SYSTEMS";
		break;
	case 0x0080A300:
		ptr = "	LANTRONIX";
		break;
	case 0x0080A400:
		ptr = "	LIBERTY ELECTRONICS";
		break;
	case 0x0080A500:
		ptr = "	SPEED INTERNATIONAL";
		break;
	case 0x0080A600:
		ptr = "	REPUBLIC TECHNOLOGY, INC.";
		break;
	case 0x0080A700:
		ptr = "	MEASUREX CORP.";
		break;
	case 0x0080A800:
		ptr = "	VITACOM CORPORATION";
		break;
	case 0x0080A900:
		ptr = "	CLEARPOINT RESEARCH";
		break;
	case 0x0080AA00:
		ptr = "	MAXPEED";
		break;
	case 0x0080AB00:
		ptr = "	DUKANE NETWORK INTEGRATION";
		break;
	case 0x0080AC00:
		ptr = "	IMLOGIX, DIVISION OF GENESYS";
		break;
	case 0x0080AD00:
		ptr = "	CNET TECHNOLOGY, INC.";
		break;
	case 0x0080AE00:
		ptr = "	HUGHES NETWORK SYSTEMS";
		break;
	case 0x0080AF00:
		ptr = "	ALLUMER CO., LTD.";
		break;
	case 0x0080B000:
		ptr = "	ADVANCED INFORMATION";
		break;
	case 0x0080B100:
		ptr = "	SOFTCOM A/S";
		break;
	case 0x0080B200:
		ptr = "	NETWORK EQUIPMENT TECHNOLOGIES";
		break;
	case 0x0080B300:
		ptr = "	AVAL DATA CORPORATION";
		break;
	case 0x0080B400:
		ptr = "	SOPHIA SYSTEMS";
		break;
	case 0x0080B500:
		ptr = "	UNITED NETWORKS INC.";
		break;
	case 0x0080B600:
		ptr = "	THEMIS COMPUTER";
		break;
	case 0x0080B700:
		ptr = "	STELLAR COMPUTER";
		break;
	case 0x0080B800:
		ptr = "	BUG, INCORPORATED";
		break;
	case 0x0080B900:
		ptr = "	ARCHE TECHNOLIGIES INC.";
		break;
	case 0x0080BA00:
		ptr = "	SPECIALIX (ASIA) PTE, LTD";
		break;
	case 0x0080BB00:
		ptr = "	HUGHES LAN SYSTEMS";
		break;
	case 0x0080BC00:
		ptr = "	HITACHI ENGINEERING CO., LTD";
		break;
	case 0x0080BD00:
		ptr = "	THE FURUKAWA ELECTRIC CO., LTD";
		break;
	case 0x0080BE00:
		ptr = "	ARIES RESEARCH";
		break;
	case 0x0080BF00:
		ptr = "	TAKAOKA ELECTRIC MFG. CO. LTD.";
		break;
	case 0x0080C000:
		ptr = "	PENRIL DATACOMM";
		break;
	case 0x0080C100:
		ptr = "	LANEX CORPORATION";
		break;
	case 0x0080C200:
		ptr = "	IEEE 802 COMMITTEE";
		break;
	case 0x0080C300:
		ptr = "	BICC INFORMATION SYSTEMS & SVC";
		break;
	case 0x0080C400:
		ptr = "	DOCUMENT TECHNOLOGIES, INC.";
		break;
	case 0x0080C500:
		ptr = "	NOVELLCO DE MEXICO";
		break;
	case 0x0080C600:
		ptr = "	NATIONAL DATACOMM CORPORATION";
		break;
	case 0x0080C700:
		ptr = "	XIRCOM";
		break;
	case 0x0080C800:
		ptr = "	D-LINK SYSTEMS, INC.";
		break;
	case 0x0080C900:
		ptr = "	ALBERTA MICROELECTRONIC CENTRE";
		break;
	case 0x0080CA00:
		ptr = "	NETCOM RESEARCH INCORPORATED";
		break;
	case 0x0080CB00:
		ptr = "	FALCO DATA PRODUCTS";
		break;
	case 0x0080CC00:
		ptr = "	MICROWAVE BYPASS SYSTEMS";
		break;
	case 0x0080CD00:
		ptr = "	MICRONICS COMPUTER, INC.";
		break;
	case 0x0080CE00:
		ptr = "	BROADCAST TELEVISION SYSTEMS";
		break;
	case 0x0080CF00:
		ptr = "	EMBEDDED PERFORMANCE INC.";
		break;
	case 0x0080D000:
		ptr = "	COMPUTER PERIPHERALS, INC.";
		break;
	case 0x0080D100:
		ptr = "	KIMTRON CORPORATION";
		break;
	case 0x0080D200:
		ptr = "	SHINNIHONDENKO CO., LTD.";
		break;
	case 0x0080D300:
		ptr = "	SHIVA CORP.";
		break;
	case 0x0080D400:
		ptr = "	CHASE RESEARCH LTD.";
		break;
	case 0x0080D500:
		ptr = "	CADRE TECHNOLOGIES";
		break;
	case 0x0080D600:
		ptr = "	NUVOTECH, INC.";
		break;
	case 0x0080D700:
		ptr = "	FANTUM ENGINEERING, INC.";
		break;
	case 0x0080D800:
		ptr = "	NETWORK PERIPHERALS INC.";
		break;
	case 0x0080D900:
		ptr = "	EMK ELEKTRONIK";
		break;
	case 0x0080DA00:
		ptr = "	BRUEL & KJAER";
		break;
	case 0x0080DB00:
		ptr = "	GRAPHON CORPORATION";
		break;
	case 0x0080DC00:
		ptr = "	PICKER INTERNATIONAL";
		break;
	case 0x0080DD00:
		ptr = "	GMX INC/GIMIX";
		break;
	case 0x0080DE00:
		ptr = "	GIPSI S.A.";
		break;
	case 0x0080DF00:
		ptr = "	ADC CODENOLL TECHNOLOGY CORP.";
		break;
	case 0x0080E000:
		ptr = "	XTP SYSTEMS, INC.";
		break;
	case 0x0080E100:
		ptr = "	STMICROELECTRONICS";
		break;
	case 0x0080E200:
		ptr = "	T.D.I. CO., LTD.";
		break;
	case 0x0080E300:
		ptr = "	CORAL NETWORK CORPORATION";
		break;
	case 0x0080E400:
		ptr = "	NORTHWEST DIGITAL SYSTEMS, INC";
		break;
	case 0x0080E500:
		ptr = "	MYLEX CORPORATION";
		break;
	case 0x0080E600:
		ptr = "	PEER NETWORKS, INC.";
		break;
	case 0x0080E700:
		ptr = "	LYNWOOD SCIENTIFIC DEV. LTD.";
		break;
	case 0x0080E800:
		ptr = "	CUMULUS CORPORATIION";
		break;
	case 0x0080E900:
		ptr = "	MADGE NETWORKS";
		break;
	case 0x0080EA00:
		ptr = "	THE FIBER COMPANY";
		break;
	case 0x0080EB00:
		ptr = "	COMPCONTROL B.V.";
		break;
	case 0x0080EC00:
		ptr = "	SUPERCOMPUTING SOLUTIONS, INC.";
		break;
	case 0x0080ED00:
		ptr = "	IQ TECHNOLOGIES, INC.";
		break;
	case 0x0080EE00:
		ptr = "	THOMSON CSF";
		break;
	case 0x0080EF00:
		ptr = "	RATIONAL";
		break;
	case 0x0080F000:
		ptr = "	KYUSHU MATSUSHITA ELECTRIC CO.";
		break;
	case 0x0080F100:
		ptr = "	OPUS SYSTEMS";
		break;
	case 0x0080F200:
		ptr = "	RAYCOM SYSTEMS INC";
		break;
	case 0x0080F300:
		ptr = "	SUN ELECTRONICS CORP.";
		break;
	case 0x0080F400:
		ptr = "	TELEMECANIQUE ELECTRIQUE";
		break;
	case 0x0080F500:
		ptr = "	QUANTEL LTD";
		break;
	case 0x0080F600:
		ptr = "	SYNERGY MICROSYSTEMS";
		break;
	case 0x0080F700:
		ptr = "	ZENITH ELECTRONICS";
		break;
	case 0x0080F800:
		ptr = "	MIZAR, INC.";
		break;
	case 0x0080F900:
		ptr = "	HEURIKON CORPORATION";
		break;
	case 0x0080FA00:
		ptr = "	RWT GMBH";
		break;
	case 0x0080FB00:
		ptr = "	BVM LIMITED";
		break;
	case 0x0080FC00:
		ptr = "	AVATAR CORPORATION";
		break;
	case 0x0080FD00:
		ptr = "	EXSCEED CORPRATION";
		break;
	case 0x0080FE00:
		ptr = "	AZURE TECHNOLOGIES, INC.";
		break;
	case 0x0080FF00:
		ptr = "	SOC. DE TELEINFORMATIQUE RTC";
		break;
	case 0x00900000:
		ptr = "	DIAMOND MULTIMEDIA";
		break;
	case 0x00900100:
		ptr = "	NISHIMU ELCTRONICS INDUSTRIES";
		break;
	case 0x00900200:
		ptr = "	ALLGON AB";
		break;
	case 0x00900300:
		ptr = "	APLIO";
		break;
	case 0x00900400:
		ptr = "	3COM EUROPE LTD.";
		break;
	case 0x00900500:
		ptr = "	PROTECH SYSTEMS CO., LTD.";
		break;
	case 0x00900600:
		ptr = "	HAMAMATSU PHOTONICS K.K.";
		break;
	case 0x00900700:
		ptr = "	DOMEX TECHNOLOGY CORP.";
		break;
	case 0x00900800:
		ptr = "	HAN A SYSTEMS, INC.";
		break;
	case 0x00900900:
		ptr = "	i Controls, Inc.";
		break;
	case 0x00900A00:
		ptr = "	PROTON ELECTRONIC INDUSTRIAL";
		break;
	case 0x00900B00:
		ptr = "	LANNER ELECTRONICS, INC.";
		break;
	case 0x00900C00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00900D00:
		ptr = "	OVERLAND DATA INC.";
		break;
	case 0x00900E00:
		ptr = "	HANDLINK TECHNOLOGIES, INC.";
		break;
	case 0x00900F00:
		ptr = "	KAWASAKI HEAVY INDUSTRIES, LTD";
		break;
	case 0x00901000:
		ptr = "	SIMULATION LABORATORIES, INC.";
		break;
	case 0x00901100:
		ptr = "	WAVTRACE, INC.";
		break;
	case 0x00901200:
		ptr = "	GLOBESPAN SEMICONDUCTOR, INC.";
		break;
	case 0x00901300:
		ptr = "	SAMSAN CORP.";
		break;
	case 0x00901400:
		ptr = "	ROTORK INSTRUMENTS, LTD.";
		break;
	case 0x00901500:
		ptr = "	CENTIGRAM COMMUNICATIONS CORP.";
		break;
	case 0x00901600:
		ptr = "	ZAC";
		break;
	case 0x00901700:
		ptr = "	ZYPCOM, INC.";
		break;
	case 0x00901800:
		ptr = "	ITO ELECTRIC INDUSTRY CO, LTD.";
		break;
	case 0x00901900:
		ptr = "	HERMES ELECTRONICS CO., LTD.";
		break;
	case 0x00901A00:
		ptr = "	UNISPHERE SOLUTIONS";
		break;
	case 0x00901B00:
		ptr = "	DIGITAL CONTROLS";
		break;
	case 0x00901C00:
		ptr = "	MPS SOFTWARE GMBH";
		break;
	case 0x00901D00:
		ptr = "	PEC (NZ) LTD.";
		break;
	case 0x00901E00:
		ptr = "	SELESTA INGEGNE RIA S.P.A.";
		break;
	case 0x00901F00:
		ptr = "	ADTEC PRODUCTIONS, INC.";
		break;
	case 0x00902000:
		ptr = "	PHILIPS ANALYTICAL X-RAY B.V.";
		break;
	case 0x00902100:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00902200:
		ptr = "	IVEX";
		break;
	case 0x00902300:
		ptr = "	ZILOG INC.";
		break;
	case 0x00902400:
		ptr = "	PIPELINKS, INC.";
		break;
	case 0x00902500:
		ptr = "	VISION SYSTEMS LTD. PTY";
		break;
	case 0x00902600:
		ptr = "	ADVANCED SWITCHING";
		break;
	case 0x00902700:
		ptr = "	INTEL CORPORATION";
		break;
	case 0x00902800:
		ptr = "	NIPPON SIGNAL CO., LTD.";
		break;
	case 0x00902900:
		ptr = "	CRYPTO AG";
		break;
	case 0x00902A00:
		ptr = "	COMMUNICATION DEVICES, INC.";
		break;
	case 0x00902B00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00902C00:
		ptr = "	DATA & CONTROL EQUIPMENT LTD.";
		break;
	case 0x00902D00:
		ptr = "	DATA ELECTRONICS";
		break;
	case 0x00902E00:
		ptr = "	NAMCO LIMITED";
		break;
	case 0x00902F00:
		ptr = "	NETCORE SYSTEMS, INC.";
		break;
	case 0x00903000:
		ptr = "	HONEYWELL-DATING";
		break;
	case 0x00903100:
		ptr = "	MYSTICOM, LTD.";
		break;
	case 0x00903200:
		ptr = "	PELCOMBE GROUP LTD.";
		break;
	case 0x00903300:
		ptr = "	INNOVAPHONE GMBH";
		break;
	case 0x00903400:
		ptr = "	IMAGIC, INC.";
		break;
	case 0x00903500:
		ptr = "	ALPHA TELECOM, INC.";
		break;
	case 0x00903600:
		ptr = "	ENS, INC.";
		break;
	case 0x00903700:
		ptr = "	ACUCOMM, INC.";
		break;
	case 0x00903800:
		ptr = "	FOUNTAIN TECHNOLOGIES, INC.";
		break;
	case 0x00903900:
		ptr = "	SHASTA NETWORKS";
		break;
	case 0x00903A00:
		ptr = "	NIHON MEDIA TOOL INC.";
		break;
	case 0x00903B00:
		ptr = "	TRIEMS RESEARCH LAB, INC.";
		break;
	case 0x00903C00:
		ptr = "	ATLANTIC NETWORK SYSTEMS";
		break;
	case 0x00903D00:
		ptr = "	BIOPAC SYSTEMS, INC.";
		break;
	case 0x00903E00:
		ptr = "	N.V. PHILIPS INDUSTRIAL";
		break;
	case 0x00903F00:
		ptr = "	AZTEC RADIOMEDIA";
		break;
	case 0x00904000:
		ptr = "	CASTLE NETWORKS, INC.";
		break;
	case 0x00904100:
		ptr = "	APPLIED DIGITAL ACCESS";
		break;
	case 0x00904200:
		ptr = "	ECCS";
		break;
	case 0x00904300:
		ptr = "	NICHIBEI DENSHI CO., LTD.";
		break;
	case 0x00904400:
		ptr = "	ASSURED DIGITAL, INC.";
		break;
	case 0x00904500:
		ptr = "	MARIPOSA TECHNOLOGY";
		break;
	case 0x00904600:
		ptr = "	DEXDYNE, LTD.";
		break;
	case 0x00904700:
		ptr = "	GIGA FAST E. LTD.";
		break;
	case 0x00904800:
		ptr = "	ZEAL CORPORATION";
		break;
	case 0x00904900:
		ptr = "	ENTRIDIA CORPORATION";
		break;
	case 0x00904A00:
		ptr = "	CONCUR SYSTEM TECHNOLOGIES";
		break;
	case 0x00904B00:
		ptr = "	GEMTEK TECHNOLOGY CO., LTD.";
		break;
	case 0x00904C00:
		ptr = "	EPIGRAM, INC.";
		break;
	case 0x00904D00:
		ptr = "	SPEC S.A.";
		break;
	case 0x00904E00:
		ptr = "	DELEM BV";
		break;
	case 0x00904F00:
		ptr = "	ABB POWER T&D COMPANY, INC.";
		break;
	case 0x00905000:
		ptr = "	TELESTE OY";
		break;
	case 0x00905100:
		ptr = "	ULTIMATE TECHNOLOGY CORP.";
		break;
	case 0x00905200:
		ptr = "	SELCOM ELETTRONICA S.R.L.";
		break;
	case 0x00905300:
		ptr = "	DAEWOO ELECTRONICS CO., LTD.";
		break;
	case 0x00905400:
		ptr = "	INNOVATIVE SEMICONDUCTORS, INC";
		break;
	case 0x00905500:
		ptr = "	PARKER HANNIFIN CORPORATION";
		break;
	case 0x00905600:
		ptr = "	TELESTREAM, INC.";
		break;
	case 0x00905700:
		ptr = "	AANETCOM, INC.";
		break;
	case 0x00905800:
		ptr = "	ULTRA ELECTRONICS LTD.";
		break;
	case 0x00905900:
		ptr = "	TELECOM DEVICE K.K.";
		break;
	case 0x00905A00:
		ptr = "	DEARBORN GROUP, INC.";
		break;
	case 0x00905B00:
		ptr = "	RAYMOND AND LAE ENGINEERING";
		break;
	case 0x00905C00:
		ptr = "	EDMI";
		break;
	case 0x00905D00:
		ptr = "	NETCOM SICHERHEITSTECHNIK GMBH";
		break;
	case 0x00905E00:
		ptr = "	RAULAND-BORG CORPORATION";
		break;
	case 0x00905F00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00906000:
		ptr = "	SYSTEM CREATE CORP.";
		break;
	case 0x00906100:
		ptr = "	PACIFIC RESEARCH & ENGINEERING";
		break;
	case 0x00906200:
		ptr = "	ICP VORTEX COMPUTERSYSTEME";
		break;
	case 0x00906300:
		ptr = "	COHERENT COMMUNICATIONS";
		break;
	case 0x00906400:
		ptr = "	THOMSON BROADCAST SYSTEMS";
		break;
	case 0x00906500:
		ptr = "	FINISAR CORPORATION";
		break;
	case 0x00906600:
		ptr = "	TROIKA DESIGN, INC.";
		break;
	case 0x00906700:
		ptr = "	WALKABOUT COMPUTERS, INC.";
		break;
	case 0x00906800:
		ptr = "	DVT CORP.";
		break;
	case 0x00906900:
		ptr = "	JUNIPER NETWORKS, INC.";
		break;
	case 0x00906A00:
		ptr = "	TURNSTONE SYSTEMS, INC.";
		break;
	case 0x00906B00:
		ptr = "	APPLIED RESOURCES, INC.";
		break;
	case 0x00906C00:
		ptr = "	GWT GLOBAL WEIGHING";
		break;
	case 0x00906D00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00906E00:
		ptr = "	PRAXON, INC.";
		break;
	case 0x00906F00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00907000:
		ptr = "	NEO NETWORKS, INC.";
		break;
	case 0x00907100:
		ptr = "	BADGER TECHNOLOGY, INC.";
		break;
	case 0x00907200:
		ptr = "	SIMRAD AS";
		break;
	case 0x00907300:
		ptr = "	GAIO TECHNOLOGY";
		break;
	case 0x00907400:
		ptr = "	ARGON NETWORKS, INC.";
		break;
	case 0x00907500:
		ptr = "	NEC DO BRASIL S.A.";
		break;
	case 0x00907600:
		ptr = "	FMT AIRCRAFT GATE SUPPORT";
		break;
	case 0x00907700:
		ptr = "	ADVANCED FIBRE COMMUNICATIONS";
		break;
	case 0x00907800:
		ptr = "	MER TELEMANAGEMENT";
		break;
	case 0x00907900:
		ptr = "	CLEARONE INC.";
		break;
	case 0x00907A00:
		ptr = "	SPECTRALINK CORP.";
		break;
	case 0x00907B00:
		ptr = "	E-TECH, INC.";
		break;
	case 0x00907C00:
		ptr = "	DIGITALCAST, INC.";
		break;
	case 0x00907D00:
		ptr = "	HOME WIRELESS NETWORKS";
		break;
	case 0x00907E00:
		ptr = "	VETRONIX CORP.";
		break;
	case 0x00907F00:
		ptr = "	WATCHGUARD TECHNOLOGIES, INC.";
		break;
	case 0x00908000:
		ptr = "	NOT LIMITED, INC.";
		break;
	case 0x00908100:
		ptr = "	ALOHA NETWORKS, INC.";
		break;
	case 0x00908200:
		ptr = "	FORCE INSTITUTE";
		break;
	case 0x00908300:
		ptr = "	TURBO COMMUNICATION, INC.";
		break;
	case 0x00908400:
		ptr = "	ATECH SYSTEM";
		break;
	case 0x00908500:
		ptr = "	GOLDEN ENTERPRISES, INC.";
		break;
	case 0x00908600:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00908700:
		ptr = "	ITIS";
		break;
	case 0x00908800:
		ptr = "	BAXALL SECURITY LTD.";
		break;
	case 0x00908900:
		ptr = "	SOFTCOM MICROSYSTEMS, INC.";
		break;
	case 0x00908A00:
		ptr = "	BAYLY COMMUNICATIONS, INC.";
		break;
	case 0x00908B00:
		ptr = "	CELL COMPUTING, INC.";
		break;
	case 0x00908C00:
		ptr = "	ETREND ELECTRONICS, INC.";
		break;
	case 0x00908D00:
		ptr = "	VICKERS ELECTRONICS SYSTEMS";
		break;
	case 0x00908E00:
		ptr = "	PROMATORY COMMUNICATIONS";
		break;
	case 0x00908F00:
		ptr = "	AUDIOCODES LTD.";
		break;
	case 0x00909000:
		ptr = "	I-BUS";
		break;
	case 0x00909100:
		ptr = "	DIGITALSCAPE, INC.";
		break;
	case 0x00909200:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00909300:
		ptr = "	NANAO CORPORATION";
		break;
	case 0x00909400:
		ptr = "	OSPREY TECHNOLOGIES, INC.";
		break;
	case 0x00909500:
		ptr = "	UNIVERSAL AVIONICS";
		break;
	case 0x00909600:
		ptr = "	ASKEY COMPUTER CORP.";
		break;
	case 0x00909700:
		ptr = "	SYCAMORE NETWORKS";
		break;
	case 0x00909800:
		ptr = "	SBC DESIGNS, INC.";
		break;
	case 0x00909900:
		ptr = "	ALLIED TELESIS,K.K.";
		break;
	case 0x00909A00:
		ptr = "	ONE WORLD SYSTEMS, INC.";
		break;
	case 0x00909B00:
		ptr = "	MARKPOINT AB";
		break;
	case 0x00909C00:
		ptr = "	COMBOX, LTD.";
		break;
	case 0x00909D00:
		ptr = "	GSE SYSTEMS, INC.";
		break;
	case 0x00909E00:
		ptr = "	DELPHI ENGINEERING GROUP";
		break;
	case 0x00909F00:
		ptr = "	DIGI-DATA CORPORATION";
		break;
	case 0x0090A000:
		ptr = "	8X8 INC.";
		break;
	case 0x0090A100:
		ptr = "	FLYING PIG SYSTEMS, LTD.";
		break;
	case 0x0090A200:
		ptr = "	CYBERTAN TECHNOLOGY, INC.";
		break;
	case 0x0090A300:
		ptr = "	MEDIALINCS CO., LTD.";
		break;
	case 0x0090A400:
		ptr = "	ALTIGA NETWORKS";
		break;
	case 0x0090A500:
		ptr = "	SPECTRA LOGIC";
		break;
	case 0x0090A600:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x0090A700:
		ptr = "	CLIENTEC CORPORATION";
		break;
	case 0x0090A800:
		ptr = "	NINETILES NETWORKS LTD.";
		break;
	case 0x0090A900:
		ptr = "	WESTERN DIGITAL";
		break;
	case 0x0090AA00:
		ptr = "	INDIGO ACTIVE VISION";
		break;
	case 0x0090AB00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x0090AC00:
		ptr = "	OPTIVISION, INC.";
		break;
	case 0x0090AD00:
		ptr = "	ASPECT ELECTRONICS, INC.";
		break;
	case 0x0090AE00:
		ptr = "	ITALTEL SPA";
		break;
	case 0x0090AF00:
		ptr = "	J. MORITA MFG. CORP.";
		break;
	case 0x0090B000:
		ptr = "	VADEM";
		break;
	case 0x0090B100:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x0090B200:
		ptr = "	AVICI SYSTEMS INC.";
		break;
	case 0x0090B300:
		ptr = "	AGRANAT SYSTEMS";
		break;
	case 0x0090B400:
		ptr = "	WILLOWBROOK TECHNOLOGIES";
		break;
	case 0x0090B500:
		ptr = "	NIKON CORPORATION";
		break;
	case 0x0090B600:
		ptr = "	FIBEX SYSTEMS";
		break;
	case 0x0090B700:
		ptr = "	DIGITAL LIGHTWAVE, INC.";
		break;
	case 0x0090B800:
		ptr = "	ROHDE & SCHWARZ GMBH & CO. KG";
		break;
	case 0x0090B900:
		ptr = "	BERAN INSTRUMENTS LTD.";
		break;
	case 0x0090BA00:
		ptr = "	VALID NETWORKS, INC.";
		break;
	case 0x0090BB00:
		ptr = "	TAINET COMMUNICATION SYSTEM";
		break;
	case 0x0090BC00:
		ptr = "	TELEMANN CO., LTD.";
		break;
	case 0x0090BD00:
		ptr = "	OMNIA COMMUNICATIONS, INC.";
		break;
	case 0x0090BE00:
		ptr = "	IBC/INTEGRATED BUSINESS";
		break;
	case 0x0090BF00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x0090C000:
		ptr = "	K.J. LAW ENGINEERS, INC.";
		break;
	case 0x0090C100:
		ptr = "	EDA INDUSTRIES";
		break;
	case 0x0090C200:
		ptr = "	JK MICROSYSTEMS, INC.";
		break;
	case 0x0090C300:
		ptr = "	TOPIC SEMICONDUCTOR CORP.";
		break;
	case 0x0090C400:
		ptr = "	JAVELIN SYSTEMS, INC.";
		break;
	case 0x0090C500:
		ptr = "	INTERNET MAGIC, INC.";
		break;
	case 0x0090C600:
		ptr = "	OPTIM SYSTEMS, INC.";
		break;
	case 0x0090C700:
		ptr = "	ICOM INC.";
		break;
	case 0x0090C800:
		ptr = "	WAVERIDER COMMUNICATIONS";
		break;
	case 0x0090C900:
		ptr = "	PRODUCTIVITY ENHANCEMENT";
		break;
	case 0x0090CA00:
		ptr = "	ACCORD VIDEO";
		break;
	case 0x0090CB00:
		ptr = "	WIRELESS ONLINE, INC.";
		break;
	case 0x0090CC00:
		ptr = "	PLANEX COMMUNICATIONS, INC.";
		break;
	case 0x0090CD00:
		ptr = "	ENT-EMPRESA NACIONAL";
		break;
	case 0x0090CE00:
		ptr = "	TETRA GMBH";
		break;
	case 0x0090CF00:
		ptr = "	NORTEL";
		break;
	case 0x0090D000:
		ptr = "	ALCATEL BELL";
		break;
	case 0x0090D100:
		ptr = "	LEICHU ENTERPRISE CO., LTD.";
		break;
	case 0x0090D200:
		ptr = "	ARTEL VIDEO SYSTEMS";
		break;
	case 0x0090D300:
		ptr = "	GIESECKE & DEVRIENT GMBH";
		break;
	case 0x0090D400:
		ptr = "	BINDVIEW DEVELOPMENT CORP.";
		break;
	case 0x0090D500:
		ptr = "	EUPHONIX, INC.";
		break;
	case 0x0090D600:
		ptr = "	CRYSTAL GROUP";
		break;
	case 0x0090D700:
		ptr = "	NETBOOST CORP.";
		break;
	case 0x0090D800:
		ptr = "	WHITECROSS SYSTEMS";
		break;
	case 0x0090D900:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x0090DA00:
		ptr = "	DYNARC, INC.";
		break;
	case 0x0090DB00:
		ptr = "	NEXT LEVEL COMMUNICATIONS";
		break;
	case 0x0090DC00:
		ptr = "	TECO INFORMATION SYSTEMS";
		break;
	case 0x0090DD00:
		ptr = "	THE MIHARU COMMUNICATIONS";
		break;
	case 0x0090DE00:
		ptr = "	CARDKEY SYSTEMS, INC.";
		break;
	case 0x0090DF00:
		ptr = "	MITSUBISHI CHEMICAL";
		break;
	case 0x0090E000:
		ptr = "	SYSTRAN CORP.";
		break;
	case 0x0090E100:
		ptr = "	TELENA S.P.A.";
		break;
	case 0x0090E200:
		ptr = "	DISTRIBUTED PROCESSING";
		break;
	case 0x0090E300:
		ptr = "	AVEX ELECTRONICS INC.";
		break;
	case 0x0090E400:
		ptr = "	NEC AMERICA, INC.";
		break;
	case 0x0090E500:
		ptr = "	TEKNEMA, INC.";
		break;
	case 0x0090E600:
		ptr = "	ACER LABORATORIES, INC.";
		break;
	case 0x0090E700:
		ptr = "	HORSCH ELEKTRONIK AG";
		break;
	case 0x0090E800:
		ptr = "	MOXA TECHNOLOGIES CORP., LTD.";
		break;
	case 0x0090E900:
		ptr = "	JANZ COMPUTER AG";
		break;
	case 0x0090EA00:
		ptr = "	ALPHA TECHNOLOGIES, INC.";
		break;
	case 0x0090EB00:
		ptr = "	SENTRY TELECOM SYSTEMS";
		break;
	case 0x0090EC00:
		ptr = "	PYRESCOM";
		break;
	case 0x0090ED00:
		ptr = "	CENTRAL SYSTEM RESEARCH";
		break;
	case 0x0090EE00:
		ptr = "	PERSONAL COMMUNICATIONS";
		break;
	case 0x0090EF00:
		ptr = "	INTEGRIX, INC.";
		break;
	case 0x0090F000:
		ptr = "	HARMONIC LIGHTWAVES, LTD.";
		break;
	case 0x0090F100:
		ptr = "	BOXHILL SYSTEMS CORPORATION";
		break;
	case 0x0090F200:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x0090F300:
		ptr = "	ASPECT COMMUNICATIONS";
		break;
	case 0x0090F400:
		ptr = "	LIGHTNING INSTRUMENTATION";
		break;
	case 0x0090F500:
		ptr = "	CLEVO CO.";
		break;
	case 0x0090F600:
		ptr = "	ESCALATE NETWORKS, INC.";
		break;
	case 0x0090F700:
		ptr = "	NBASE COMMUNICATIONS LTD.";
		break;
	case 0x0090F800:
		ptr = "	MEDIATRIX TELECOM";
		break;
	case 0x0090F900:
		ptr = "	LEITCH";
		break;
	case 0x0090FA00:
		ptr = "	GIGANET, INC.";
		break;
	case 0x0090FB00:
		ptr = "	PORTWELL, INC.";
		break;
	case 0x0090FC00:
		ptr = "	NETWORK COMPUTING DEVICES";
		break;
	case 0x0090FD00:
		ptr = "	COPPERCOM, INC.";
		break;
	case 0x0090FE00:
		ptr = "	ELECOM CO., LTD.  (LANEED DIV.";
		break;
	case 0x0090FF00:
		ptr = "	TELLUS TECHNOLOGY INC.";
		break;
	case 0x009D8E00:
		ptr = "	CARDIAC RECORDERS, INC.";
		break;
	case 0x00A00000:
		ptr = "	CENTILLION NETWORKS, INC.";
		break;
	case 0x00A00100:
		ptr = "	WATKINS-JOHNSON COMPANY";
		break;
	case 0x00A00200:
		ptr = "	LEEDS & NORTHRUP AUSTRALIA";
		break;
	case 0x00A00300:
		ptr = "	STAEFA CONTROL SYSTEM";
		break;
	case 0x00A00400:
		ptr = "	NETPOWER, INC.";
		break;
	case 0x00A00500:
		ptr = "	DANIEL INSTRUMENTS, LTD.";
		break;
	case 0x00A00600:
		ptr = "	IMAGE DATA PROCESSING";
		break;
	case 0x00A00700:
		ptr = "	APEXX TECHNOLOGY, INC.";
		break;
	case 0x00A00800:
		ptr = "	NETCORP";
		break;
	case 0x00A00900:
		ptr = "	WHITETREE NETWORK";
		break;
	case 0x00A00A00:
		ptr = "	R.D.C. COMMUNICATION";
		break;
	case 0x00A00B00:
		ptr = "	COMPUTEX CO., LTD.";
		break;
	case 0x00A00C00:
		ptr = "	KINGMAX TECHNOLOGY, INC.";
		break;
	case 0x00A00D00:
		ptr = "	THE PANDA PROJECT";
		break;
	case 0x00A00E00:
		ptr = "	VISUAL NETWORKS, INC.";
		break;
	case 0x00A00F00:
		ptr = "	Broadband Technologies";
		break;
	case 0x00A01000:
		ptr = "	SYSLOGIC DATENTECHNIK AG";
		break;
	case 0x00A01100:
		ptr = "	MUTOH INDUSTRIES LTD.";
		break;
	case 0x00A01200:
		ptr = "	B.A.T.M. ADVANCED TECHNOLOGIES";
		break;
	case 0x00A01300:
		ptr = "	TELTREND LTD.";
		break;
	case 0x00A01400:
		ptr = "	CSIR";
		break;
	case 0x00A01500:
		ptr = "	WYLE";
		break;
	case 0x00A01600:
		ptr = "	MICROPOLIS CORP.";
		break;
	case 0x00A01700:
		ptr = "	J B M CORPORATION";
		break;
	case 0x00A01800:
		ptr = "	CREATIVE CONTROLLERS, INC.";
		break;
	case 0x00A01900:
		ptr = "	NEBULA CONSULTANTS, INC.";
		break;
	case 0x00A01A00:
		ptr = "	BINAR ELEKTRONIK AB";
		break;
	case 0x00A01B00:
		ptr = "	PREMISYS COMMUNICATIONS, INC.";
		break;
	case 0x00A01C00:
		ptr = "	NASCENT NETWORKS CORPORATION";
		break;
	case 0x00A01D00:
		ptr = "	SIXNET";
		break;
	case 0x00A01E00:
		ptr = "	EST CORPORATION";
		break;
	case 0x00A01F00:
		ptr = "	TRICORD SYSTEMS, INC.";
		break;
	case 0x00A02000:
		ptr = "	CITICORP/TTI";
		break;
	case 0x00A02100:
		ptr = "	GENERAL DYNAMICS-";
		break;
	case 0x00A02200:
		ptr = "	CENTRE FOR DEVELOPMENT OF";
		break;
	case 0x00A02300:
		ptr = "	APPLIED CREATIVE TECHNOLOGY,";
		break;
	case 0x00A02400:
		ptr = "	3COM CORPORATION";
		break;
	case 0x00A02500:
		ptr = "	REDCOM LABS INC.";
		break;
	case 0x00A02600:
		ptr = "	TELDAT, S.A.";
		break;
	case 0x00A02700:
		ptr = "	FIREPOWER SYSTEMS, INC.";
		break;
	case 0x00A02800:
		ptr = "	CONNER PERIPHERALS";
		break;
	case 0x00A02900:
		ptr = "	COULTER CORPORATION";
		break;
	case 0x00A02A00:
		ptr = "	TRANCELL SYSTEMS";
		break;
	case 0x00A02B00:
		ptr = "	TRANSITIONS RESEARCH CORP.";
		break;
	case 0x00A02C00:
		ptr = "	INTERWAVE COMMUNICATIONS";
		break;
	case 0x00A02D00:
		ptr = "	SKIPSTONE, INC.";
		break;
	case 0x00A02E00:
		ptr = "	BRAND COMMUNICATIONS, LTD.";
		break;
	case 0x00A02F00:
		ptr = "	PIRELLI CAVI";
		break;
	case 0x00A03000:
		ptr = "	CAPTOR NV/SA";
		break;
	case 0x00A03100:
		ptr = "	HAZELTINE CORPORATION, MS 1-17";
		break;
	case 0x00A03200:
		ptr = "	GES SINGAPORE PTE. LTD.";
		break;
	case 0x00A03300:
		ptr = "	IMC MESS-SYSTEME GMBH";
		break;
	case 0x00A03400:
		ptr = "	AXEL";
		break;
	case 0x00A03500:
		ptr = "	CYLINK CORPORATION";
		break;
	case 0x00A03600:
		ptr = "	APPLIED NETWORK TECHNOLOGY";
		break;
	case 0x00A03700:
		ptr = "	DATASCOPE CORPORATION";
		break;
	case 0x00A03800:
		ptr = "	EMAIL ELECTRONICS";
		break;
	case 0x00A03900:
		ptr = "	ROSS TECHNOLOGY, INC.";
		break;
	case 0x00A03A00:
		ptr = "	KUBOTEK CORPORATION";
		break;
	case 0x00A03B00:
		ptr = "	TOSHIN ELECTRIC CO., LTD.";
		break;
	case 0x00A03C00:
		ptr = "	EG&G NUCLEAR INSTRUMENTS";
		break;
	case 0x00A03D00:
		ptr = "	OPTO - 22";
		break;
	case 0x00A03E00:
		ptr = "	ATM FORUM";
		break;
	case 0x00A03F00:
		ptr = "	COMPUTER SOCIETY MICROPROCES'R";
		break;
	case 0x00A04000:
		ptr = "	APPLE COMPUTER";
		break;
	case 0x00A04100:
		ptr = "	LEYBOLD-INFICON";
		break;
	case 0x00A04200:
		ptr = "	SPUR PRODUCTS CORP.";
		break;
	case 0x00A04300:
		ptr = "	AMERICAN TECHNOLOGY LABS, INC.";
		break;
	case 0x00A04400:
		ptr = "	NTT INTELLIGENT TECHNOLOGY";
		break;
	case 0x00A04500:
		ptr = "	PHOENIX CONTACT GMBH & CO.";
		break;
	case 0x00A04600:
		ptr = "	SCITEX CORP. LTD.";
		break;
	case 0x00A04700:
		ptr = "	INTEGRATED FITNESS CORP.";
		break;
	case 0x00A04800:
		ptr = "	QUESTECH, LTD.";
		break;
	case 0x00A04900:
		ptr = "	DIGITECH INDUSTRIES, INC.";
		break;
	case 0x00A04A00:
		ptr = "	NISSHIN ELECTRIC CO., LTD.";
		break;
	case 0x00A04B00:
		ptr = "	TFL LAN INC.";
		break;
	case 0x00A04C00:
		ptr = "	INNOVATIVE SYSTEMS & TECH. INC";
		break;
	case 0x00A04D00:
		ptr = "	EDA INSTRUMENTS, INC.";
		break;
	case 0x00A04E00:
		ptr = "	VOELKER TECHNOLOGIES, INC.";
		break;
	case 0x00A04F00:
		ptr = "	AMERITEC CORP.";
		break;
	case 0x00A05000:
		ptr = "	CYPRESS SEMICONDUCTOR";
		break;
	case 0x00A05100:
		ptr = "	ANGIA COMMUNICATIONS. INC.";
		break;
	case 0x00A05200:
		ptr = "	STANILITE ELECTRONICS PTY. LTD";
		break;
	case 0x00A05300:
		ptr = "	COMPACT DEVICES, INC.";
		break;
	case 0x00A05500:
		ptr = "	LINKTECH, INC.";
		break;
	case 0x00A05600:
		ptr = "	MICROPROSS";
		break;
	case 0x00A05700:
		ptr = "	ELSA AG";
		break;
	case 0x00A05800:
		ptr = "	GLORY, LTD.";
		break;
	case 0x00A05900:
		ptr = "	HAMILTON HALLMARK";
		break;
	case 0x00A05A00:
		ptr = "	KOFAX IMAGE PRODUCTS";
		break;
	case 0x00A05B00:
		ptr = "	MARQUIP, INC.";
		break;
	case 0x00A05C00:
		ptr = "	INVENTORY CONVERSION, INC./";
		break;
	case 0x00A05D00:
		ptr = "	CS COMPUTER SYSTEME GMBH";
		break;
	case 0x00A05E00:
		ptr = "	MYRIAD LOGIC INC.";
		break;
	case 0x00A05F00:
		ptr = "	BTG ENGINEERING BV";
		break;
	case 0x00A06000:
		ptr = "	ACER PERIPHERALS, INC.";
		break;
	case 0x00A06100:
		ptr = "	PURITAN BENNETT";
		break;
	case 0x00A06200:
		ptr = "	AES PRODATA";
		break;
	case 0x00A06300:
		ptr = "	JRL SYSTEMS, INC.";
		break;
	case 0x00A06400:
		ptr = "	KVB/ANALECT";
		break;
	case 0x00A06500:
		ptr = "	NEXLAND, INC.";
		break;
	case 0x00A06600:
		ptr = "	ISA CO., LTD.";
		break;
	case 0x00A06700:
		ptr = "	NETWORK SERVICES GROUP";
		break;
	case 0x00A06900:
		ptr = "	TRUETIME";
		break;
	case 0x00A06A00:
		ptr = "	VERILINK CORP.";
		break;
	case 0x00A06B00:
		ptr = "	DMS DORSCH MIKROSYSTEM GMBH";
		break;
	case 0x00A06D00:
		ptr = "	MANNESMANN TALLY CORPORATION";
		break;
	case 0x00A06E00:
		ptr = "	AUSTRON, INC.";
		break;
	case 0x00A06F00:
		ptr = "	THE APPCON GROUP, INC.";
		break;
	case 0x00A07000:
		ptr = "	COASTCOM";
		break;
	case 0x00A07100:
		ptr = "	VIDEO LOTTERY TECHNOLOGIES,INC";
		break;
	case 0x00A07200:
		ptr = "	OVATION SYSTEMS LTD.";
		break;
	case 0x00A07300:
		ptr = "	COM21, INC.";
		break;
	case 0x00A07400:
		ptr = "	PERCEPTION TECHNOLOGY";
		break;
	case 0x00A07500:
		ptr = "	MICRON TECHNOLOGY, INC.";
		break;
	case 0x00A07600:
		ptr = "	CARDWARE LAB, INC.";
		break;
	case 0x00A07700:
		ptr = "	FUJITSU NEXION, INC.";
		break;
	case 0x00A07800:
		ptr = "	CELLACCESS TECHNOLOGY, INC.";
		break;
	case 0x00A07900:
		ptr = "	ALPS ELECTRIC (USA), INC.";
		break;
	case 0x00A07A00:
		ptr = "	ADVANCED PERIPHERALS";
		break;
	case 0x00A07B00:
		ptr = "	DAWN COMPUTER INCORPORATION";
		break;
	case 0x00A07C00:
		ptr = "	TONYANG NYLON CO., LTD.";
		break;
	case 0x00A07D00:
		ptr = "	SEEQ TECHNOLOGY, INC.";
		break;
	case 0x00A07E00:
		ptr = "	AVID TECHNOLOGY, INC.";
		break;
	case 0x00A07F00:
		ptr = "	GSM-SYNTEL, LTD.";
		break;
	case 0x00A08000:
		ptr = "	ANTARES MICROSYSTEMS";
		break;
	case 0x00A08100:
		ptr = "	ALCATEL DATA NETWORKS";
		break;
	case 0x00A08200:
		ptr = "	NKT ELEKTRONIK A/S";
		break;
	case 0x00A08300:
		ptr = "	ASIMMPHONY TURKEY";
		break;
	case 0x00A08400:
		ptr = "	DATAPLEX PTY. LTD.";
		break;
	case 0x00A08600:
		ptr = "	AMBER WAVE SYSTEMS, INC.";
		break;
	case 0x00A08700:
		ptr = "	MITEL SEMICONDUCTOR, LTD.";
		break;
	case 0x00A08800:
		ptr = "	ESSENTIAL COMMUNICATIONS";
		break;
	case 0x00A08900:
		ptr = "	XPOINT TECHNOLOGIES, INC.";
		break;
	case 0x00A08A00:
		ptr = "	BROOKTROUT TECHNOLOGY, INC.";
		break;
	case 0x00A08B00:
		ptr = "	ASTON ELECTRONIC DESIGNS LTD.";
		break;
	case 0x00A08C00:
		ptr = "	MULTIMEDIA LANS, INC.";
		break;
	case 0x00A08D00:
		ptr = "	JACOMO CORPORATION";
		break;
	case 0x00A08E00:
		ptr = "	IPSILON NETWORKS, INC.";
		break;
	case 0x00A08F00:
		ptr = "	DESKNET SYSTEMS, INC.";
		break;
	case 0x00A09000:
		ptr = "	TIMESTEP CORPORATION";
		break;
	case 0x00A09100:
		ptr = "	APPLICOM INTERNATIONAL";
		break;
	case 0x00A09200:
		ptr = "	H. BOLLMANN MANUFACTURERS, LTD";
		break;
	case 0x00A09300:
		ptr = "	B/E AEROSPACE";
		break;
	case 0x00A09400:
		ptr = "	COMSAT CORPORATION";
		break;
	case 0x00A09500:
		ptr = "	ACACIA NETWORKS, INC.";
		break;
	case 0x00A09600:
		ptr = "	MITSUMI ELECTRIC CO., LTD.";
		break;
	case 0x00A09700:
		ptr = "	JC INFORMATION SYSTEMS";
		break;
	case 0x00A09800:
		ptr = "	NETWORK APPLIANCE CORP.";
		break;
	case 0x00A09900:
		ptr = "	K-NET LTD.";
		break;
	case 0x00A09A00:
		ptr = "	NIHON KOHDEN AMERICA";
		break;
	case 0x00A09B00:
		ptr = "	QPSX COMMUNICATIONS, LTD.";
		break;
	case 0x00A09C00:
		ptr = "	XYPLEX, INC.";
		break;
	case 0x00A09D00:
		ptr = "	JOHNATHON FREEMAN TECHNOLOGIES";
		break;
	case 0x00A09E00:
		ptr = "	ICTV";
		break;
	case 0x00A09F00:
		ptr = "	COMMVISION CORP.";
		break;
	case 0x00A0A000:
		ptr = "	COMPACT DATA, LTD.";
		break;
	case 0x00A0A100:
		ptr = "	EPIC DATA INC.";
		break;
	case 0x00A0A200:
		ptr = "	DIGICOM S.P.A.";
		break;
	case 0x00A0A300:
		ptr = "	RELIABLE POWER METERS";
		break;
	case 0x00A0A400:
		ptr = "	MICROS SYSTEMS, INC.";
		break;
	case 0x00A0A500:
		ptr = "	TEKNOR MICROSYSTEME, INC.";
		break;
	case 0x00A0A600:
		ptr = "	M.I. SYSTEMS, K.K.";
		break;
	case 0x00A0A700:
		ptr = "	VORAX CORPORATION";
		break;
	case 0x00A0A800:
		ptr = "	RENEX CORPORATION";
		break;
	case 0x00A0A900:
		ptr = "	GN NETTEST (CANADA) INC.";
		break;
	case 0x00A0AA00:
		ptr = "	SPACELABS MEDICAL";
		break;
	case 0x00A0AB00:
		ptr = "	NETCS INFORMATIONSTECHNIK GMBH";
		break;
	case 0x00A0AC00:
		ptr = "	GILAT SATELLITE NETWORKS, LTD.";
		break;
	case 0x00A0AD00:
		ptr = "	MARCONI SPA";
		break;
	case 0x00A0AE00:
		ptr = "	NUCOM SYSTEMS, INC.";
		break;
	case 0x00A0AF00:
		ptr = "	WMS INDUSTRIES";
		break;
	case 0x00A0B000:
		ptr = "	I-O DATA DEVICE, INC.";
		break;
	case 0x00A0B100:
		ptr = "	FIRST VIRTUAL CORPORATION";
		break;
	case 0x00A0B200:
		ptr = "	SHIMA SEIKI";
		break;
	case 0x00A0B300:
		ptr = "	ZYKRONIX";
		break;
	case 0x00A0B400:
		ptr = "	TEXAS MICROSYSTEMS, INC.";
		break;
	case 0x00A0B500:
		ptr = "	3H TECHNOLOGY";
		break;
	case 0x00A0B600:
		ptr = "	SANRITZ AUTOMATION CO., LTD.";
		break;
	case 0x00A0B700:
		ptr = "	CORDANT, INC.";
		break;
	case 0x00A0B800:
		ptr = "	SYMBIOS LOGIC INC.";
		break;
	case 0x00A0B900:
		ptr = "	EAGLE TECHNOLOGY, INC.";
		break;
	case 0x00A0BA00:
		ptr = "	PATTON ELECTRONICS CO.";
		break;
	case 0x00A0BB00:
		ptr = "	HILAN GMBH";
		break;
	case 0x00A0BC00:
		ptr = "	VIASAT, INCORPORATED";
		break;
	case 0x00A0BD00:
		ptr = "	I-TECH CORP.";
		break;
	case 0x00A0BE00:
		ptr = "	INTEGRATED CIRCUIT SYSTEMS,INC";
		break;
	case 0x00A0BF00:
		ptr = "	WIRELESS DATA GROUP MOTOROLA";
		break;
	case 0x00A0C000:
		ptr = "	DIGITAL LINK CORP.";
		break;
	case 0x00A0C100:
		ptr = "	ORTIVUS MEDICAL AB";
		break;
	case 0x00A0C200:
		ptr = "	R.A. SYSTEMS CO., LTD.";
		break;
	case 0x00A0C300:
		ptr = "	UNICOMPUTER GMBH";
		break;
	case 0x00A0C400:
		ptr = "	CRISTIE ELECTRONICS LTD.";
		break;
	case 0x00A0C500:
		ptr = "	ZYXEL COMMUNICATION";
		break;
	case 0x00A0C600:
		ptr = "	QUALCOMM INCORPORATED";
		break;
	case 0x00A0C700:
		ptr = "	TADIRAN TELECOMMUNICATIONS";
		break;
	case 0x00A0C800:
		ptr = "	ADTRAN INC.";
		break;
	case 0x00A0C900:
		ptr = "	INTEL CORPORATION - HF1-06";
		break;
	case 0x00A0CA00:
		ptr = "	FUJITSU DENSO LTD.";
		break;
	case 0x00A0CB00:
		ptr = "	ARK TELECOMMUNICATIONS, INC.";
		break;
	case 0x00A0CC00:
		ptr = "	LITE-ON COMMUNICATIONS, INC.";
		break;
	case 0x00A0CD00:
		ptr = "	DR. JOHANNES HEIDENHAIN GMBH";
		break;
	case 0x00A0CE00:
		ptr = "	ASTROCOM CORPORATION";
		break;
	case 0x00A0CF00:
		ptr = "	SOTAS, INC.";
		break;
	case 0x00A0D000:
		ptr = "	TEN X TECHNOLOGY, INC.";
		break;
	case 0x00A0D100:
		ptr = "	INVENTEC CORPORATION";
		break;
	case 0x00A0D200:
		ptr = "	ALLIED TELESIS INTERNATIONAL";
		break;
	case 0x00A0D300:
		ptr = "	INSTEM COMPUTER SYSTEMS, LTD.";
		break;
	case 0x00A0D400:
		ptr = "	RADIOLAN,  INC.";
		break;
	case 0x00A0D500:
		ptr = "	SIERRA WIRELESS INC.";
		break;
	case 0x00A0D600:
		ptr = "	SBE, INC.";
		break;
	case 0x00A0D700:
		ptr = "	KASTEN CHASE APPLIED RESEARCH";
		break;
	case 0x00A0D800:
		ptr = "	SPECTRA - TEK";
		break;
	case 0x00A0D900:
		ptr = "	CONVEX COMPUTER CORPORATION";
		break;
	case 0x00A0DA00:
		ptr = "	INTEGRATED SYSTEMS";
		break;
	case 0x00A0DB00:
		ptr = "	FISHER & PAYKEL PRODUCTION";
		break;
	case 0x00A0DC00:
		ptr = "	O.N. ELECTRONIC CO., LTD.";
		break;
	case 0x00A0DD00:
		ptr = "	AZONIX CORPORATION";
		break;
	case 0x00A0DE00:
		ptr = "	YAMAHA CORPORATION";
		break;
	case 0x00A0DF00:
		ptr = "	STS TECHNOLOGIES, INC.";
		break;
	case 0x00A0E000:
		ptr = "	TENNYSON TECHNOLOGIES PTY LTD";
		break;
	case 0x00A0E100:
		ptr = "	WESTPORT RESEARCH";
		break;
	case 0x00A0E200:
		ptr = "	KEISOKU GIKEN CORP.";
		break;
	case 0x00A0E300:
		ptr = "	XKL SYSTEMS CORP.";
		break;
	case 0x00A0E400:
		ptr = "	OPTIQUEST";
		break;
	case 0x00A0E500:
		ptr = "	NHC COMMUNICATIONS";
		break;
	case 0x00A0E600:
		ptr = "	DIALOGIC CORPORATION";
		break;
	case 0x00A0E700:
		ptr = "	CENTRAL DATA CORPORATION";
		break;
	case 0x00A0E800:
		ptr = "	REUTERS HOLDINGS PLC";
		break;
	case 0x00A0E900:
		ptr = "	ELECTRONIC RETAILING SYSTEMS";
		break;
	case 0x00A0EA00:
		ptr = "	ETHERCOM CORP.";
		break;
	case 0x00A0EB00:
		ptr = "	FASTCOMM COMMUNICATIONS CORP.";
		break;
	case 0x00A0EC00:
		ptr = "	TRANSMITTON LTD.";
		break;
	case 0x00A0ED00:
		ptr = "	PRI AUTOMATION";
		break;
	case 0x00A0EE00:
		ptr = "	NASHOBA NETWORKS";
		break;
	case 0x00A0EF00:
		ptr = "	LUCIDATA LTD.";
		break;
	case 0x00A0F000:
		ptr = "	TORONTO MICROELECTRONICS INC.";
		break;
	case 0x00A0F100:
		ptr = "	MTI";
		break;
	case 0x00A0F200:
		ptr = "	INFOTEK COMMUNICATIONS, INC.";
		break;
	case 0x00A0F300:
		ptr = "	STAUBLI";
		break;
	case 0x00A0F400:
		ptr = "	GE";
		break;
	case 0x00A0F500:
		ptr = "	RADGUARD LTD.";
		break;
	case 0x00A0F600:
		ptr = "	AUTOGAS SYSTEMS, INC.";
		break;
	case 0x00A0F700:
		ptr = "	V.I COMPUTER CORP.";
		break;
	case 0x00A0F800:
		ptr = "	SYMBOL TECHNOLOGIES, INC.";
		break;
	case 0x00A0F900:
		ptr = "	BINTEC COMMUNICATIONS GMBH";
		break;
	case 0x00A0FA00:
		ptr = "	Marconi Communication GmbH";
		break;
	case 0x00A0FB00:
		ptr = "	TORAY ENGINEERING CO., LTD.";
		break;
	case 0x00A0FC00:
		ptr = "	IMAGE SCIENCES, INC.";
		break;
	case 0x00A0FD00:
		ptr = "	SCITEX DIGITAL PRINTING, INC.";
		break;
	case 0x00A0FE00:
		ptr = "	BOSTON TECHNOLOGY, INC.";
		break;
	case 0x00A0FF00:
		ptr = "	TELLABS OPERATIONS, INC.";
		break;
	case 0x00AA0000:
	case 0x00AA0100:
	case 0x00AA0200:
		ptr = "	INTEL CORPORATION";
		break;
	case 0x00AA3C00:
		ptr = "	OLIVETTI TELECOM SPA (OLTECO)";
		break;
	case 0x00B00900:
		ptr = "	Grass Valley Group";
		break;
	case 0x00B01700:
		ptr = "	InfoGear Technology Corp.";
		break;
	case 0x00B01900:
		ptr = "	Casi-Rusco";
		break;
	case 0x00B01C00:
		ptr = "	Westport Technologies";
		break;
	case 0x00B01E00:
		ptr = "	Rantic Labs, Inc.";
		break;
	case 0x00B02A00:
		ptr = "	ORSYS GmbH";
		break;
	case 0x00B02D00:
		ptr = "	ViaGate Technologies, Inc.";
		break;
	case 0x00B03B00:
		ptr = "	HiQ Networks";
		break;
	case 0x00B04800:
		ptr = "	Marconi Communications Inc.";
		break;
	case 0x00B04A00:
		ptr = "	Cisco Systems, Inc.";
		break;
	case 0x00B05200:
		ptr = "	Intellon Corporation";
		break;
	case 0x00B06400:
		ptr = "	Cisco Systems, Inc.";
		break;
	case 0x00B06900:
		ptr = "	Honewell Oy";
		break;
	case 0x00B06D00:
		ptr = "	Jones Futurex Inc.";
		break;
	case 0x00B08000:
		ptr = "	Mannesmann Ipulsys B.V.";
		break;
	case 0x00B08600:
		ptr = "	LocSoft Limited";
		break;
	case 0x00B08E00:
		ptr = "	Cisco Systems, Inc.";
		break;
	case 0x00B09100:
		ptr = "	Transmeta Corp.";
		break;
	case 0x00B09400:
		ptr = "	Alaris, Inc.";
		break;
	case 0x00B09A00:
		ptr = "	Morrow Technologies Corp.";
		break;
	case 0x00B09D00:
		ptr = "	Point Grey Research Inc.";
		break;
	case 0x00B0AC00:
		ptr = "	SIAE-Microelettronica S.p.A.";
		break;
	case 0x00B0AE00:
		ptr = "	Symmetricom";
		break;
	case 0x00B0B300:
		ptr = "	Xstreamis PLC";
		break;
	case 0x00B0C200:
		ptr = "	Cisco Systems, Inc.";
		break;
	case 0x00B0C700:
		ptr = "	Tellabs Operations, Inc.";
		break;
	case 0x00B0D000:
		ptr = "	Dell Computer Corp.";
		break;
	case 0x00B0DB00:
		ptr = "	Nextcell, Inc.";
		break;
	case 0x00B0DF00:
		ptr = "	Reliable Data Technology, Inc.";
		break;
	case 0x00B0E700:
		ptr = "	British Federal Ltd.";
		break;
	case 0x00B0EC00:
		ptr = "	EACEM";
		break;
	case 0x00B0EE00:
		ptr = "	Ajile Systems, Inc.";
		break;
	case 0x00B0F000:
		ptr = "	CALY NETWORKS";
		break;
	case 0x00B0F500:
		ptr = "	NetWorth Technologies, Inc.";
		break;
	case 0x00BB0100:
		ptr = "	OCTOTHORPE CORP.";
		break;
	case 0x00BBF000:
		ptr = "	UNGERMANN-BASS INC.";
		break;
	case 0x00C00000:
		ptr = "	LANOPTICS, LTD.";
		break;
	case 0x00C00100:
		ptr = "	DIATEK PATIENT MANAGMENT";
		break;
	case 0x00C00200:
		ptr = "	SERCOMM CORPORATION";
		break;
	case 0x00C00300:
		ptr = "	GLOBALNET COMMUNICATIONS";
		break;
	case 0x00C00400:
		ptr = "	JAPAN BUSINESS COMPUTER CO.LTD";
		break;
	case 0x00C00500:
		ptr = "	LIVINGSTON ENTERPRISES, INC.";
		break;
	case 0x00C00600:
		ptr = "	NIPPON AVIONICS CO., LTD.";
		break;
	case 0x00C00700:
		ptr = "	PINNACLE DATA SYSTEMS, INC.";
		break;
	case 0x00C00800:
		ptr = "	SECO SRL";
		break;
	case 0x00C00900:
		ptr = "	KT TECHNOLOGY (S) PTE LTD";
		break;
	case 0x00C00A00:
		ptr = "	MICRO CRAFT";
		break;
	case 0x00C00B00:
		ptr = "	NORCONTROL A.S.";
		break;
	case 0x00C00C00:
		ptr = "	RELIA TECHNOLGIES";
		break;
	case 0x00C00D00:
		ptr = "	ADVANCED LOGIC RESEARCH, INC.";
		break;
	case 0x00C00E00:
		ptr = "	PSITECH, INC.";
		break;
	case 0x00C00F00:
		ptr = "	QUANTUM SOFTWARE SYSTEMS LTD.";
		break;
	case 0x00C01000:
		ptr = "	HIRAKAWA HEWTECH CORP.";
		break;
	case 0x00C01100:
		ptr = "	INTERACTIVE COMPUTING DEVICES";
		break;
	case 0x00C01200:
		ptr = "	NETSPAN CORPORATION";
		break;
	case 0x00C01300:
		ptr = "	NETRIX";
		break;
	case 0x00C01400:
		ptr = "	TELEMATICS CALABASAS INT'L,INC";
		break;
	case 0x00C01500:
		ptr = "	NEW MEDIA CORPORATION";
		break;
	case 0x00C01600:
		ptr = "	ELECTRONIC THEATRE CONTROLS";
		break;
	case 0x00C01700:
		ptr = "	FORTE NETWORKS";
		break;
	case 0x00C01800:
		ptr = "	LANART CORPORATION";
		break;
	case 0x00C01900:
		ptr = "	LEAP TECHNOLOGY, INC.";
		break;
	case 0x00C01A00:
		ptr = "	COROMETRICS MEDICAL SYSTEMS";
		break;
	case 0x00C01B00:
		ptr = "	SOCKET COMMUNICATIONS, INC.";
		break;
	case 0x00C01C00:
		ptr = "	INTERLINK COMMUNICATIONS LTD.";
		break;
	case 0x00C01D00:
		ptr = "	GRAND JUNCTION NETWORKS, INC.";
		break;
	case 0x00C01E00:
		ptr = "	LA FRANCAISE DES JEUX";
		break;
	case 0x00C01F00:
		ptr = "	S.E.R.C.E.L.";
		break;
	case 0x00C02000:
		ptr = "	ARCO ELECTRONIC, CONTROL LTD.";
		break;
	case 0x00C02100:
		ptr = "	NETEXPRESS";
		break;
	case 0x00C02200:
		ptr = "	LASERMASTER TECHNOLOGIES, INC.";
		break;
	case 0x00C02300:
		ptr = "	TUTANKHAMON ELECTRONICS";
		break;
	case 0x00C02400:
		ptr = "	EDEN SISTEMAS DE COMPUTACAO SA";
		break;
	case 0x00C02500:
		ptr = "	DATAPRODUCTS CORPORATION";
		break;
	case 0x00C02600:
		ptr = "	LANS TECHNOLOGY CO., LTD.";
		break;
	case 0x00C02700:
		ptr = "	CIPHER SYSTEMS, INC.";
		break;
	case 0x00C02800:
		ptr = "	JASCO CORPORATION";
		break;
	case 0x00C02900:
		ptr = "	KABEL RHEYDT AG";
		break;
	case 0x00C02A00:
		ptr = "	OHKURA ELECTRIC CO., LTD.";
		break;
	case 0x00C02B00:
		ptr = "	GERLOFF GESELLSCHAFT FUR";
		break;
	case 0x00C02C00:
		ptr = "	CENTRUM COMMUNICATIONS, INC.";
		break;
	case 0x00C02D00:
		ptr = "	FUJI PHOTO FILM CO., LTD.";
		break;
	case 0x00C02E00:
		ptr = "	NETWIZ";
		break;
	case 0x00C02F00:
		ptr = "	OKUMA CORPORATION";
		break;
	case 0x00C03000:
		ptr = "	INTEGRATED ENGINEERING B. V.";
		break;
	case 0x00C03100:
		ptr = "	DESIGN RESEARCH SYSTEMS, INC.";
		break;
	case 0x00C03200:
		ptr = "	I-CUBED LIMITED";
		break;
	case 0x00C03300:
		ptr = "	TELEBIT COMMUNICATIONS APS";
		break;
	case 0x00C03400:
		ptr = "	TRANSACTION NETWORK";
		break;
	case 0x00C03500:
		ptr = "	QUINTAR COMPANY";
		break;
	case 0x00C03600:
		ptr = "	RAYTECH ELECTRONIC CORP.";
		break;
	case 0x00C03700:
		ptr = "	DYNATEM";
		break;
	case 0x00C03800:
		ptr = "	RASTER IMAGE PROCESSING SYSTEM";
		break;
	case 0x00C03900:
		ptr = "	TDK SEMICONDUCTOR CORPORATION";
		break;
	case 0x00C03A00:
		ptr = "	MEN-MIKRO ELEKTRONIK GMBH";
		break;
	case 0x00C03B00:
		ptr = "	MULTIACCESS COMPUTING CORP.";
		break;
	case 0x00C03C00:
		ptr = "	TOWER TECH S.R.L.";
		break;
	case 0x00C03D00:
		ptr = "	WIESEMANN & THEIS GMBH";
		break;
	case 0x00C03E00:
		ptr = "	FA. GEBR. HELLER GMBH";
		break;
	case 0x00C03F00:
		ptr = "	STORES AUTOMATED SYSTEMS, INC.";
		break;
	case 0x00C04000:
		ptr = "	ECCI";
		break;
	case 0x00C04100:
		ptr = "	DIGITAL TRANSMISSION SYSTEMS";
		break;
	case 0x00C04200:
		ptr = "	DATALUX CORP.";
		break;
	case 0x00C04300:
		ptr = "	STRATACOM";
		break;
	case 0x00C04400:
		ptr = "	EMCOM CORPORATION";
		break;
	case 0x00C04500:
		ptr = "	ISOLATION SYSTEMS, LTD.";
		break;
	case 0x00C04600:
		ptr = "	KEMITRON LTD.";
		break;
	case 0x00C04700:
		ptr = "	UNIMICRO SYSTEMS, INC.";
		break;
	case 0x00C04800:
		ptr = "	BAY TECHNICAL ASSOCIATES";
		break;
	case 0x00C04900:
		ptr = "	U.S. ROBOTICS, INC.";
		break;
	case 0x00C04A00:
		ptr = "	GROUP 2000 AG";
		break;
	case 0x00C04B00:
		ptr = "	CREATIVE MICROSYSTEMS";
		break;
	case 0x00C04C00:
		ptr = "	DEPARTMENT OF FOREIGN AFFAIRS";
		break;
	case 0x00C04D00:
		ptr = "	MITEC, INC.";
		break;
	case 0x00C04E00:
		ptr = "	COMTROL CORPORATION";
		break;
	case 0x00C04F00:
		ptr = "	DELL COMPUTER CORPORATION";
		break;
	case 0x00C05000:
		ptr = "	TOYO DENKI SEIZO K.K.";
		break;
	case 0x00C05100:
		ptr = "	ADVANCED INTEGRATION RESEARCH";
		break;
	case 0x00C05200:
		ptr = "	BURR-BROWN";
		break;
	case 0x00C05300:
		ptr = "	DAVOX CORPORATION";
		break;
	case 0x00C05400:
		ptr = "	NETWORK PERIPHERALS, LTD.";
		break;
	case 0x00C05500:
		ptr = "	MODULAR COMPUTING TECHNOLOGIES";
		break;
	case 0x00C05600:
		ptr = "	SOMELEC";
		break;
	case 0x00C05700:
		ptr = "	MYCO ELECTRONICS";
		break;
	case 0x00C05800:
		ptr = "	DATAEXPERT CORP.";
		break;
	case 0x00C05900:
		ptr = "	NIPPON DENSO CO., LTD.";
		break;
	case 0x00C05A00:
		ptr = "	SEMAPHORE COMMUNICATIONS CORP.";
		break;
	case 0x00C05B00:
		ptr = "	NETWORKS NORTHWEST, INC.";
		break;
	case 0x00C05C00:
		ptr = "	ELONEX PLC";
		break;
	case 0x00C05D00:
		ptr = "	L&N TECHNOLOGIES";
		break;
	case 0x00C05E00:
		ptr = "	VARI-LITE, INC.";
		break;
	case 0x00C05F00:
		ptr = "	FINE-PAL COMPANY LIMITED";
		break;
	case 0x00C06000:
		ptr = "	ID SCANDINAVIA AS";
		break;
	case 0x00C06100:
		ptr = "	SOLECTEK CORPORATION";
		break;
	case 0x00C06200:
		ptr = "	IMPULSE TECHNOLOGY";
		break;
	case 0x00C06300:
		ptr = "	MORNING STAR TECHNOLOGIES, INC";
		break;
	case 0x00C06400:
		ptr = "	GENERAL DATACOMM IND. INC.";
		break;
	case 0x00C06500:
		ptr = "	SCOPE COMMUNICATIONS, INC.";
		break;
	case 0x00C06600:
		ptr = "	DOCUPOINT, INC.";
		break;
	case 0x00C06700:
		ptr = "	UNITED BARCODE INDUSTRIES";
		break;
	case 0x00C06800:
		ptr = "	PHILIP DRAKE ELECTRONICS LTD.";
		break;
	case 0x00C06900:
		ptr = "	ADAPTIVE BROADBAND CORPORATION";
		break;
	case 0x00C06A00:
		ptr = "	ZAHNER-ELEKTRIK GMBH & CO. KG";
		break;
	case 0x00C06B00:
		ptr = "	OSI PLUS CORPORATION";
		break;
	case 0x00C06C00:
		ptr = "	SVEC COMPUTER CORP.";
		break;
	case 0x00C06D00:
		ptr = "	BOCA RESEARCH, INC.";
		break;
	case 0x00C06E00:
		ptr = "	HAFT TECHNOLOGY, INC.";
		break;
	case 0x00C06F00:
		ptr = "	KOMATSU LTD.";
		break;
	case 0x00C07000:
		ptr = "	SECTRA SECURE-TRANSMISSION AB";
		break;
	case 0x00C07100:
		ptr = "	AREANEX COMMUNICATIONS, INC.";
		break;
	case 0x00C07200:
		ptr = "	KNX LTD.";
		break;
	case 0x00C07300:
		ptr = "	XEDIA CORPORATION";
		break;
	case 0x00C07400:
		ptr = "	TOYODA AUTOMATIC LOOM";
		break;
	case 0x00C07500:
		ptr = "	XANTE CORPORATION";
		break;
	case 0x00C07600:
		ptr = "	I-DATA INTERNATIONAL A-S";
		break;
	case 0x00C07700:
		ptr = "	DAEWOO TELECOM LTD.";
		break;
	case 0x00C07800:
		ptr = "	COMPUTER SYSTEMS ENGINEERING";
		break;
	case 0x00C07900:
		ptr = "	FONSYS CO.,LTD.";
		break;
	case 0x00C07A00:
		ptr = "	PRIVA B.V.";
		break;
	case 0x00C07B00:
		ptr = "	ASCEND COMMUNICATIONS, INC.";
		break;
	case 0x00C07C00:
		ptr = "	HIGHTECH INFORMATION";
		break;
	case 0x00C07D00:
		ptr = "	RISC DEVELOPMENTS LTD.";
		break;
	case 0x00C07E00:
		ptr = "	KUBOTA CORPORATION ELECTRONIC";
		break;
	case 0x00C07F00:
		ptr = "	NUPON COMPUTING CORP.";
		break;
	case 0x00C08000:
		ptr = "	NETSTAR, INC.";
		break;
	case 0x00C08100:
		ptr = "	METRODATA LTD.";
		break;
	case 0x00C08200:
		ptr = "	MOORE PRODUCTS CO.";
		break;
	case 0x00C08300:
		ptr = "	TRACE MOUNTAIN PRODUCTS, INC.";
		break;
	case 0x00C08400:
		ptr = "	DATA LINK CORP. LTD.";
		break;
	case 0x00C08500:
		ptr = "	ELECTRONICS FOR IMAGING, INC.";
		break;
	case 0x00C08600:
		ptr = "	THE LYNK CORPORATION";
		break;
	case 0x00C08700:
		ptr = "	UUNET TECHNOLOGIES, INC.";
		break;
	case 0x00C08800:
		ptr = "	EKF ELEKTRONIK GMBH";
		break;
	case 0x00C08900:
		ptr = "	TELINDUS DISTRIBUTION";
		break;
	case 0x00C08A00:
		ptr = "	LAUTERBACH DATENTECHNIK GMBH";
		break;
	case 0x00C08B00:
		ptr = "	RISQ MODULAR SYSTEMS, INC.";
		break;
	case 0x00C08C00:
		ptr = "	PERFORMANCE TECHNOLOGIES, INC.";
		break;
	case 0x00C08D00:
		ptr = "	TRONIX PRODUCT DEVELOPMENT";
		break;
	case 0x00C08E00:
		ptr = "	NETWORK INFORMATION TECHNOLOGY";
		break;
	case 0x00C08F00:
		ptr = "	MATSUSHITA ELECTRIC WORKS, LTD";
		break;
	case 0x00C09000:
		ptr = "	PRAIM S.R.L.";
		break;
	case 0x00C09100:
		ptr = "	JABIL CIRCUIT, INC.";
		break;
	case 0x00C09200:
		ptr = "	MENNEN MEDICAL INC.";
		break;
	case 0x00C09300:
		ptr = "	ALTA RESEARCH CORP.";
		break;
	case 0x00C09400:
		ptr = "	VMX INC.";
		break;
	case 0x00C09500:
		ptr = "	ZNYX";
		break;
	case 0x00C09600:
		ptr = "	TAMURA CORPORATION";
		break;
	case 0x00C09700:
		ptr = "	ARCHIPEL SA";
		break;
	case 0x00C09800:
		ptr = "	CHUNTEX ELECTRONIC CO., LTD.";
		break;
	case 0x00C09900:
		ptr = "	YOSHIKI INDUSTRIAL CO.,LTD.";
		break;
	case 0x00C09A00:
		ptr = "	PHOTONICS CORPORATION";
		break;
	case 0x00C09B00:
		ptr = "	RELIANCE COMM/TEC, R-TEC";
		break;
	case 0x00C09C00:
		ptr = "	TOA ELECTRONIC LTD.";
		break;
	case 0x00C09D00:
		ptr = "	DISTRIBUTED SYSTEMS INT'L, INC";
		break;
	case 0x00C09E00:
		ptr = "	CACHE COMPUTERS, INC.";
		break;
	case 0x00C09F00:
		ptr = "	QUANTA COMPUTER, INC.";
		break;
	case 0x00C0A000:
		ptr = "	ADVANCE MICRO RESEARCH, INC.";
		break;
	case 0x00C0A100:
		ptr = "	TOKYO DENSHI SEKEI CO.";
		break;
	case 0x00C0A200:
		ptr = "	INTERMEDIUM A/S";
		break;
	case 0x00C0A300:
		ptr = "	DUAL ENTERPRISES CORPORATION";
		break;
	case 0x00C0A400:
		ptr = "	UNIGRAF OY";
		break;
	case 0x00C0A500:
		ptr = "	DICKENS DATA SYSTEMS";
		break;
	case 0x00C0A600:
		ptr = "	EXICOM AUSTRALIA PTY. LTD";
		break;
	case 0x00C0A700:
		ptr = "	SEEL LTD.";
		break;
	case 0x00C0A800:
		ptr = "	GVC CORPORATION";
		break;
	case 0x00C0A900:
		ptr = "	BARRON MCCANN LTD.";
		break;
	case 0x00C0AA00:
		ptr = "	SILICON VALLEY COMPUTER";
		break;
	case 0x00C0AB00:
		ptr = "	Telco Systems, Inc.";
		break;
	case 0x00C0AC00:
		ptr = "	GAMBIT COMPUTER COMMUNICATIONS";
		break;
	case 0x00C0AD00:
		ptr = "	MARBEN COMMUNICATION SYSTEMS";
		break;
	case 0x00C0AE00:
		ptr = "	TOWERCOM CO. INC. DBA PC HOUSE";
		break;
	case 0x00C0AF00:
		ptr = "	TEKLOGIX INC.";
		break;
	case 0x00C0B000:
		ptr = "	GCC TECHNOLOGIES,INC.";
		break;
	case 0x00C0B100:
		ptr = "	GENIUS NET CO.";
		break;
	case 0x00C0B200:
		ptr = "	NORAND CORPORATION";
		break;
	case 0x00C0B300:
		ptr = "	COMSTAT DATACOMM CORPORATION";
		break;
	case 0x00C0B400:
		ptr = "	MYSON TECHNOLOGY, INC.";
		break;
	case 0x00C0B500:
		ptr = "	CORPORATE NETWORK SYSTEMS,INC.";
		break;
	case 0x00C0B600:
		ptr = "	MERIDIAN DATA, INC.";
		break;
	case 0x00C0B700:
		ptr = "	AMERICAN POWER CONVERSION CORP";
		break;
	case 0x00C0B800:
		ptr = "	FRASER'S HILL LTD.";
		break;
	case 0x00C0B900:
		ptr = "	FUNK SOFTWARE, INC.";
		break;
	case 0x00C0BA00:
		ptr = "	NETVANTAGE";
		break;
	case 0x00C0BB00:
		ptr = "	FORVAL CREATIVE, INC.";
		break;
	case 0x00C0BC00:
		ptr = "	TELECOM AUSTRALIA/CSSC";
		break;
	case 0x00C0BD00:
		ptr = "	INEX TECHNOLOGIES, INC.";
		break;
	case 0x00C0BE00:
		ptr = "	ALCATEL - SEL";
		break;
	case 0x00C0BF00:
		ptr = "	TECHNOLOGY CONCEPTS, LTD.";
		break;
	case 0x00C0C000:
		ptr = "	SHORE MICROSYSTEMS, INC.";
		break;
	case 0x00C0C100:
		ptr = "	QUAD/GRAPHICS, INC.";
		break;
	case 0x00C0C200:
		ptr = "	INFINITE NETWORKS LTD.";
		break;
	case 0x00C0C300:
		ptr = "	ACUSON COMPUTED SONOGRAPHY";
		break;
	case 0x00C0C400:
		ptr = "	COMPUTER OPERATIONAL";
		break;
	case 0x00C0C500:
		ptr = "	SID INFORMATICA";
		break;
	case 0x00C0C600:
		ptr = "	PERSONAL MEDIA CORP.";
		break;
	case 0x00C0C700:
		ptr = "	SPARKTRUM MICROSYSTEMS, INC.";
		break;
	case 0x00C0C800:
		ptr = "	MICRO BYTE PTY. LTD.";
		break;
	case 0x00C0C900:
		ptr = "	ELSAG BAILEY PROCESS";
		break;
	case 0x00C0CA00:
		ptr = "	ALFA, INC.";
		break;
	case 0x00C0CB00:
		ptr = "	CONTROL TECHNOLOGY CORPORATION";
		break;
	case 0x00C0CC00:
		ptr = "	TELESCIENCES CO SYSTEMS, INC.";
		break;
	case 0x00C0CD00:
		ptr = "	COMELTA, S.A.";
		break;
	case 0x00C0CE00:
		ptr = "	CEI SYSTEMS & ENGINEERING PTE";
		break;
	case 0x00C0CF00:
		ptr = "	IMATRAN VOIMA OY";
		break;
	case 0x00C0D000:
		ptr = "	RATOC SYSTEM INC.";
		break;
	case 0x00C0D100:
		ptr = "	COMTREE TECHNOLOGY CORPORATION";
		break;
	case 0x00C0D200:
		ptr = "	SYNTELLECT, INC.";
		break;
	case 0x00C0D300:
		ptr = "	OLYMPUS IMAGE SYSTEMS, INC.";
		break;
	case 0x00C0D400:
		ptr = "	AXON NETWORKS, INC.";
		break;
	case 0x00C0D500:
		ptr = "	QUANCOM ELECTRONIC GMBH";
		break;
	case 0x00C0D600:
		ptr = "	J1 SYSTEMS, INC.";
		break;
	case 0x00C0D700:
		ptr = "	TAIWAN TRADING CENTER DBA";
		break;
	case 0x00C0D800:
		ptr = "	UNIVERSAL DATA SYSTEMS";
		break;
	case 0x00C0D900:
		ptr = "	QUINTE NETWORK CONFIDENTIALITY";
		break;
	case 0x00C0DA00:
		ptr = "	NICE SYSTEMS LTD.";
		break;
	case 0x00C0DB00:
		ptr = "	IPC CORPORATION (PTE) LTD.";
		break;
	case 0x00C0DC00:
		ptr = "	EOS TECHNOLOGIES, INC.";
		break;
	case 0x00C0DD00:
		ptr = "	ANCOR COMMUNICATIONS";
		break;
	case 0x00C0DE00:
		ptr = "	ZCOMM, INC.";
		break;
	case 0x00C0DF00:
		ptr = "	KYE SYSTEMS CORP.";
		break;
	case 0x00C0E000:
		ptr = "	DSC COMMUNICATION CORP.";
		break;
	case 0x00C0E100:
		ptr = "	SONIC SOLUTIONS";
		break;
	case 0x00C0E200:
		ptr = "	CALCOMP, INC.";
		break;
	case 0x00C0E300:
		ptr = "	OSITECH COMMUNICATIONS, INC.";
		break;
	case 0x00C0E400:
		ptr = "	SIEMENS BUILDING";
		break;
	case 0x00C0E500:
		ptr = "	GESPAC, S.A.";
		break;
	case 0x00C0E600:
		ptr = "	TXPORT";
		break;
	case 0x00C0E700:
		ptr = "	FIBERDATA AB";
		break;
	case 0x00C0E800:
		ptr = "	PLEXCOM, INC.";
		break;
	case 0x00C0E900:
		ptr = "	OAK SOLUTIONS, LTD.";
		break;
	case 0x00C0EA00:
		ptr = "	ARRAY TECHNOLOGY LTD.";
		break;
	case 0x00C0EB00:
		ptr = "	SEH COMPUTERTECHNIK GMBH";
		break;
	case 0x00C0EC00:
		ptr = "	DAUPHIN TECHNOLOGY";
		break;
	case 0x00C0ED00:
		ptr = "	US ARMY ELECTRONIC";
		break;
	case 0x00C0EE00:
		ptr = "	KYOCERA CORPORATION";
		break;
	case 0x00C0EF00:
		ptr = "	ABIT CORPORATION";
		break;
	case 0x00C0F000:
		ptr = "	KINGSTON TECHNOLOGY CORP.";
		break;
	case 0x00C0F100:
		ptr = "	SHINKO ELECTRIC CO., LTD.";
		break;
	case 0x00C0F200:
		ptr = "	TRANSITION NETWORKS";
		break;
	case 0x00C0F300:
		ptr = "	NETWORK COMMUNICATIONS CORP.";
		break;
	case 0x00C0F400:
		ptr = "	INTERLINK SYSTEM CO., LTD.";
		break;
	case 0x00C0F500:
		ptr = "	METACOMP, INC.";
		break;
	case 0x00C0F600:
		ptr = "	CELAN TECHNOLOGY INC.";
		break;
	case 0x00C0F700:
		ptr = "	ENGAGE COMMUNICATION, INC.";
		break;
	case 0x00C0F800:
		ptr = "	ABOUT COMPUTING INC.";
		break;
	case 0x00C0F900:
		ptr = "	HARRIS AND JEFFRIES, INC.";
		break;
	case 0x00C0FA00:
		ptr = "	CANARY COMMUNICATIONS, INC.";
		break;
	case 0x00C0FB00:
		ptr = "	ADVANCED TECHNOLOGY LABS";
		break;
	case 0x00C0FC00:
		ptr = "	ELASTIC REALITY, INC.";
		break;
	case 0x00C0FD00:
		ptr = "	PROSUM";
		break;
	case 0x00C0FE00:
		ptr = "	APTEC COMPUTER SYSTEMS, INC.";
		break;
	case 0x00C0FF00:
		ptr = "	BOX HILL SYSTEMS CORPORATION";
		break;
	case 0x00CF1C00:
		ptr = "	COMMUNICATION MACHINERY CORP.";
		break;
	case 0x00D00000:
		ptr = "	FERRAN SCIENTIFIC, INC.";
		break;
	case 0x00D00100:
		ptr = "	VST TECHNOLOGIES, INC.";
		break;
	case 0x00D00200:
		ptr = "	DITECH CORPORATION";
		break;
	case 0x00D00300:
		ptr = "	COMDA ENTERPRISES CORP.";
		break;
	case 0x00D00400:
		ptr = "	PENTACOM LTD.";
		break;
	case 0x00D00500:
		ptr = "	ZHS ZEITMANAGEMENTSYSTEME";
		break;
	case 0x00D00600:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00D00700:
		ptr = "	MIC ASSOCIATES, INC.";
		break;
	case 0x00D00800:
		ptr = "	MACTELL CORPORATION";
		break;
	case 0x00D00900:
		ptr = "	HSING TECH. ENTERPRISE CO. LTD";
		break;
	case 0x00D00A00:
		ptr = "	LANACCESS TELECOM S.A.";
		break;
	case 0x00D00B00:
		ptr = "	RHK TECHNOLOGY, INC.";
		break;
	case 0x00D00C00:
		ptr = "	SNIJDER MICRO SYSTEMS";
		break;
	case 0x00D00D00:
		ptr = "	MICROMERITICS INSTRUMENT";
		break;
	case 0x00D00E00:
		ptr = "	PLURIS, INC.";
		break;
	case 0x00D00F00:
		ptr = "	SPEECH DESIGN GMBH";
		break;
	case 0x00D01000:
		ptr = "	CONVERGENT NETWORKS, INC.";
		break;
	case 0x00D01100:
		ptr = "	PRISM VIDEO, INC.";
		break;
	case 0x00D01200:
		ptr = "	GATEWORKS CORP.";
		break;
	case 0x00D01300:
		ptr = "	PRIMEX AEROSPACE COMPANY";
		break;
	case 0x00D01400:
		ptr = "	ROOT, INC.";
		break;
	case 0x00D01500:
		ptr = "	UNIVEX MICROTECHNOLOGY CORP.";
		break;
	case 0x00D01600:
		ptr = "	SCM MICROSYSTEMS, INC.";
		break;
	case 0x00D01700:
		ptr = "	SYNTECH INFORMATION CO., LTD.";
		break;
	case 0x00D01800:
		ptr = "	QWES. COM, INC.";
		break;
	case 0x00D01900:
		ptr = "	DAINIPPON SCREEN CORPORATE";
		break;
	case 0x00D01A00:
		ptr = "	URMET SUD S.P.A.";
		break;
	case 0x00D01B00:
		ptr = "	MIMAKI ENGINEERING CO., LTD.";
		break;
	case 0x00D01C00:
		ptr = "	SBS TECHNOLOGIES,";
		break;
	case 0x00D01D00:
		ptr = "	FURUNO ELECTRIC CO., LTD.";
		break;
	case 0x00D01E00:
		ptr = "	PINGTEL CORP.";
		break;
	case 0x00D01F00:
		ptr = "	CTAM PTY. LTD.";
		break;
	case 0x00D02000:
		ptr = "	AIM SYSTEM, INC.";
		break;
	case 0x00D02100:
		ptr = "	REGENT ELECTRONICS CORP.";
		break;
	case 0x00D02200:
		ptr = "	INCREDIBLE TECHNOLOGIES, INC.";
		break;
	case 0x00D02300:
		ptr = "	INFORTREND TECHNOLOGY, INC.";
		break;
	case 0x00D02400:
		ptr = "	COGNEX";
		break;
	case 0x00D02500:
		ptr = "	XROSSTECH, INC.";
		break;
	case 0x00D02600:
		ptr = "	HIRSCHMANN AUSTRIA GMBH";
		break;
	case 0x00D02700:
		ptr = "	APPLIED AUTOMATION, INC.";
		break;
	case 0x00D02800:
		ptr = "	OMNEON VIDEO NETWORKS";
		break;
	case 0x00D02900:
		ptr = "	WAKEFERN FOOD CORPORATION";
		break;
	case 0x00D02A00:
		ptr = "	FLEXION SYSTEMS";
		break;
	case 0x00D02B00:
		ptr = "	JETCELL, INC.";
		break;
	case 0x00D02C00:
		ptr = "	CAMPBELL SCIENTIFIC, INC.";
		break;
	case 0x00D02D00:
		ptr = "	ADEMCO";
		break;
	case 0x00D02E00:
		ptr = "	COMMUNICATION AUTOMATION CORP.";
		break;
	case 0x00D02F00:
		ptr = "	VLSI TECHNOLOGY INC.";
		break;
	case 0x00D03000:
		ptr = "	SAFETRAN SYSTEMS CORP.";
		break;
	case 0x00D03100:
		ptr = "	INDUSTRIAL LOGIC CORPORATION";
		break;
	case 0x00D03200:
		ptr = "	YANO ELECTRIC CO., LTD.";
		break;
	case 0x00D03300:
		ptr = "	DALIAN DAXIAN NETWORK";
		break;
	case 0x00D03400:
		ptr = "	ORMEC SYSTEMS CORP.";
		break;
	case 0x00D03500:
		ptr = "	BEHAVIOR TECH. COMPUTER CORP.";
		break;
	case 0x00D03600:
		ptr = "	TECHNOLOGY ATLANTA CORP.";
		break;
	case 0x00D03700:
		ptr = "	PHILIPS-DVS-LO BDR";
		break;
	case 0x00D03800:
		ptr = "	FIVEMERE, LTD.";
		break;
	case 0x00D03900:
		ptr = "	UTILICOM, INC.";
		break;
	case 0x00D03A00:
		ptr = "	ZONEWORX, INC.";
		break;
	case 0x00D03B00:
		ptr = "	VISION PRODUCTS PTY. LTD.";
		break;
	case 0x00D03C00:
		ptr = "	POWER MICRO RESEARCH";
		break;
	case 0x00D03E00:
		ptr = "	ROCKETCHIPS, INC.";
		break;
	case 0x00D03F00:
		ptr = "	AMERICAN COMMUNICATION";
		break;
	case 0x00D04000:
		ptr = "	SYSMATE CO., LTD.";
		break;
	case 0x00D04100:
		ptr = "	AMIGO TECHNOLOGY CO., LTD.";
		break;
	case 0x00D04200:
		ptr = "	MAHLO GMBH & CO. UG";
		break;
	case 0x00D04300:
		ptr = "	ZONAL RETAIL DATA SYSTEMS";
		break;
	case 0x00D04400:
		ptr = "	ALIDIAN NETWORKS, INC.";
		break;
	case 0x00D04500:
		ptr = "	KVASER AB";
		break;
	case 0x00D04600:
		ptr = "	DOLBY LABORATORIES, INC.";
		break;
	case 0x00D04700:
		ptr = "	XN TECHNOLOGIES";
		break;
	case 0x00D04800:
		ptr = "	ECTON, INC.";
		break;
	case 0x00D04900:
		ptr = "	IMPRESSTEK CO., LTD.";
		break;
	case 0x00D04A00:
		ptr = "	PRESENCE TECHNOLOGY GMBH";
		break;
	case 0x00D04B00:
		ptr = "	LA CIE GROUP S.A.";
		break;
	case 0x00D04C00:
		ptr = "	EUROTEL TELECOM LTD.";
		break;
	case 0x00D04D00:
		ptr = "	DIV OF RESEARCH & STATISTICS";
		break;
	case 0x00D04E00:
		ptr = "	LOGIBAG";
		break;
	case 0x00D04F00:
		ptr = "	BITRONICS, INC.";
		break;
	case 0x00D05000:
		ptr = "	ISKRATEL";
		break;
	case 0x00D05100:
		ptr = "	O2 MICRO, INC.";
		break;
	case 0x00D05200:
		ptr = "	ASCEND COMMUNICATIONS, INC.";
		break;
	case 0x00D05300:
		ptr = "	CONNECTED SYSTEMS";
		break;
	case 0x00D05400:
		ptr = "	SAS INSTITUTE INC.";
		break;
	case 0x00D05500:
		ptr = "	KATHREIN-WERKE KG";
		break;
	case 0x00D05600:
		ptr = "	SOMAT CORPORATION";
		break;
	case 0x00D05700:
		ptr = "	ULTRAK, INC.";
		break;
	case 0x00D05800:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00D05900:
		ptr = "	AMBIT MICROSYSTEMS CORP.";
		break;
	case 0x00D05A00:
		ptr = "	SYMBIONICS, LTD.";
		break;
	case 0x00D05B00:
		ptr = "	ACROLOOP MOTION CONTROL";
		break;
	case 0x00D05C00:
		ptr = "	TECHNOTREND SYSTEMTECHNIK GMBH";
		break;
	case 0x00D05D00:
		ptr = "	INTELLIWORXX, INC.";
		break;
	case 0x00D05E00:
		ptr = "	STRATABEAM TECHNOLOGY, INC.";
		break;
	case 0x00D05F00:
		ptr = "	VALCOM, INC.";
		break;
	case 0x00D06000:
		ptr = "	PANASONIC EUROPEAN";
		break;
	case 0x00D06100:
		ptr = "	TREMON ENTERPRISES CO., LTD.";
		break;
	case 0x00D06200:
		ptr = "	DIGIGRAM";
		break;
	case 0x00D06300:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00D06400:
		ptr = "	MULTITEL";
		break;
	case 0x00D06500:
		ptr = "	TOKO ELECTRIC";
		break;
	case 0x00D06600:
		ptr = "	WINTRISS ENGINEERING CORP.";
		break;
	case 0x00D06700:
		ptr = "	CAMPIO COMMUNICATIONS";
		break;
	case 0x00D06800:
		ptr = "	IWILL CORPORATION";
		break;
	case 0x00D06900:
		ptr = "	TECHNOLOGIC SYSTEMS";
		break;
	case 0x00D06A00:
		ptr = "	LINKUP SYSTEMS CORPORATION";
		break;
	case 0x00D06B00:
		ptr = "	SR TELECOM INC.";
		break;
	case 0x00D06C00:
		ptr = "	SHAREWAVE, INC.";
		break;
	case 0x00D06D00:
		ptr = "	ACRISON, INC.";
		break;
	case 0x00D06E00:
		ptr = "	TRENDVIEW RECORDERS LTD.";
		break;
	case 0x00D06F00:
		ptr = "	KMC CONTROLS";
		break;
	case 0x00D07000:
		ptr = "	LONG WELL ELECTRONICS CORP.";
		break;
	case 0x00D07100:
		ptr = "	ECHELON CORP.";
		break;
	case 0x00D07200:
		ptr = "	BROADLOGIC";
		break;
	case 0x00D07300:
		ptr = "	ACN ADVANCED COMMUNICATIONS";
		break;
	case 0x00D07400:
		ptr = "	TAQUA SYSTEMS, INC.";
		break;
	case 0x00D07500:
		ptr = "	ALARIS MEDICAL SYSTEMS, INC.";
		break;
	case 0x00D07600:
		ptr = "	MERRILL LYNCH & CO., INC.";
		break;
	case 0x00D07700:
		ptr = "	LUCENT TECHNOLOGIES";
		break;
	case 0x00D07800:
		ptr = "	ELTEX OF SWEDEN AB";
		break;
	case 0x00D07900:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00D07A00:
		ptr = "	AMAQUEST COMPUTER CORP.";
		break;
	case 0x00D07B00:
		ptr = "	COMCAM INTERNATIONAL LTD.";
		break;
	case 0x00D07C00:
		ptr = "	KOYO ELECTRONICS INC. CO.,LTD.";
		break;
	case 0x00D07D00:
		ptr = "	COSINE COMMUNICATIONS";
		break;
	case 0x00D07E00:
		ptr = "	KEYCORP LTD.";
		break;
	case 0x00D07F00:
		ptr = "	STRATEGY & TECHNOLOGY, LIMITED";
		break;
	case 0x00D08000:
		ptr = "	EXABYTE CORPORATION";
		break;
	case 0x00D08100:
		ptr = "	REAL TIME DEVICES USA, INC.";
		break;
	case 0x00D08200:
		ptr = "	IOWAVE INC.";
		break;
	case 0x00D08300:
		ptr = "	INVERTEX, INC.";
		break;
	case 0x00D08400:
		ptr = "	NEXCOMM SYSTEMS, INC.";
		break;
	case 0x00D08500:
		ptr = "	OTIS ELEVATOR COMPANY";
		break;
	case 0x00D08600:
		ptr = "	FOVEON, INC.";
		break;
	case 0x00D08700:
		ptr = "	MICROFIRST INC.";
		break;
	case 0x00D08800:
		ptr = "	MAINSAIL NETWORKS, INC.";
		break;
	case 0x00D08900:
		ptr = "	DYNACOLOR, INC.";
		break;
	case 0x00D08A00:
		ptr = "	PHOTRON USA";
		break;
	case 0x00D08B00:
		ptr = "	STORAGE AREA NETWORKS, LTD.";
		break;
	case 0x00D08C00:
		ptr = "	GENOA TECHNOLOGY, INC.";
		break;
	case 0x00D08D00:
		ptr = "	PHOENIX GROUP, INC.";
		break;
	case 0x00D08E00:
		ptr = "	NVISION INC.";
		break;
	case 0x00D08F00:
		ptr = "	ARDENT TECHNOLOGIES, INC.";
		break;
	case 0x00D09000:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00D09100:
		ptr = "	SMARTSAN SYSTEMS, INC.";
		break;
	case 0x00D09200:
		ptr = "	GLENAYRE WESTERN MULTIPLEX";
		break;
	case 0x00D09300:
		ptr = "	TQ - COMPONENTS GMBH";
		break;
	case 0x00D09500:
		ptr = "	XYLAN CORPORATION";
		break;
	case 0x00D09600:
		ptr = "	3COM EUROPE LTD.";
		break;
	case 0x00D09700:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00D09800:
		ptr = "	IPS AUTOMATION";
		break;
	case 0x00D09900:
		ptr = "	ELCARD OY";
		break;
	case 0x00D09A00:
		ptr = "	FILANET CORPORATION";
		break;
	case 0x00D09B00:
		ptr = "	SPECTEL LTD.";
		break;
	case 0x00D09C00:
		ptr = "	KAPADIA COMMUNICATIONS";
		break;
	case 0x00D09D00:
		ptr = "	VERIS INDUSTRIES";
		break;
	case 0x00D09E00:
		ptr = "	2WIRE, INC.";
		break;
	case 0x00D09F00:
		ptr = "	NOVTEK TEST SYSTEMS";
		break;
	case 0x00D0A000:
		ptr = "	MIPS DENMARK";
		break;
	case 0x00D0A100:
		ptr = "	OSKAR VIERLING GMBH + CO. KG";
		break;
	case 0x00D0A200:
		ptr = "	INTEGRATED DEVICE";
		break;
	case 0x00D0A300:
		ptr = "	VOCAL DATA, INC.";
		break;
	case 0x00D0A400:
		ptr = "	ALANTRO COMMUNICATIONS";
		break;
	case 0x00D0A500:
		ptr = "	AMERICAN ARIUM";
		break;
	case 0x00D0A600:
		ptr = "	LANBIRD TECHNOLOGY CO., LTD.";
		break;
	case 0x00D0A700:
		ptr = "	TOKYO SOKKI KENKYUJO CO., LTD.";
		break;
	case 0x00D0A800:
		ptr = "	NETWORK ENGINES, INC.";
		break;
	case 0x00D0A900:
		ptr = "	SHINANO KENSHI CO., LTD.";
		break;
	case 0x00D0AA00:
		ptr = "	CHASE COMMUNICATIONS";
		break;
	case 0x00D0AB00:
		ptr = "	DELTAKABEL TELECOM CV";
		break;
	case 0x00D0AC00:
		ptr = "	GRAYSON WIRELESS";
		break;
	case 0x00D0AD00:
		ptr = "	TL INDUSTRIES";
		break;
	case 0x00D0AE00:
		ptr = "	ORESIS COMMUNICATIONS, INC.";
		break;
	case 0x00D0AF00:
		ptr = "	CUTLER-HAMMER, INC.";
		break;
	case 0x00D0B000:
		ptr = "	BITSWITCH LTD.";
		break;
	case 0x00D0B100:
		ptr = "	OMEGA ELECTRONICS SA";
		break;
	case 0x00D0B200:
		ptr = "	XIOTECH CORPORATION";
		break;
	case 0x00D0B300:
		ptr = "	DRS FLIGHT SAFETY AND";
		break;
	case 0x00D0B400:
		ptr = "	KATSUJIMA CO., LTD.";
		break;
	case 0x00D0B500:
		ptr = "	DOTCOM";
		break;
	case 0x00D0B600:
		ptr = "	CRESCENT NETWORKS, INC.";
		break;
	case 0x00D0B700:
		ptr = "	INTEL";
		break;
	case 0x00D0B800:
		ptr = "	IOMEGA CORP.";
		break;
	case 0x00D0B900:
		ptr = "	MICROTEK INTERNATIONAL, INC.";
		break;
	case 0x00D0BA00:
	case 0x00D0BB00:
	case 0x00D0BC00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00D0BD00:
		ptr = "	SICAN GMBH";
		break;
	case 0x00D0BE00:
		ptr = "	EMUTEC INC.";
		break;
	case 0x00D0BF00:
		ptr = "	PIVOTAL TECHNOLOGIES";
		break;
	case 0x00D0C000:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00D0C100:
		ptr = "	HARMONIC DATA SYSTEMS, LTD.";
		break;
	case 0x00D0C200:
		ptr = "	BALTHAZAR TECHNOLOGY AB";
		break;
	case 0x00D0C300:
		ptr = "	VIVID TECHNOLOGY PTE, LTD.";
		break;
	case 0x00D0C400:
		ptr = "	TERATECH CORPORATION";
		break;
	case 0x00D0C500:
		ptr = "	COMPUTATIONAL SYSTEMS, INC.";
		break;
	case 0x00D0C600:
		ptr = "	THOMAS & BETTS CORP.";
		break;
	case 0x00D0C700:
		ptr = "	PATHWAY, INC.";
		break;
	case 0x00D0C800:
		ptr = "	I/O CONSULTING A/S";
		break;
	case 0x00D0C900:
		ptr = "	ADVANTECH CO., LTD.";
		break;
	case 0x00D0CA00:
		ptr = "	INTRINSYC SOFTWARE INC.";
		break;
	case 0x00D0CB00:
		ptr = "	DASAN CO., LTD.";
		break;
	case 0x00D0CC00:
		ptr = "	TECHNOLOGIES LYRE INC.";
		break;
	case 0x00D0CD00:
		ptr = "	ATAN TECHNOLOGY INC.";
		break;
	case 0x00D0CE00:
		ptr = "	ASYST ELECTRONIC";
		break;
	case 0x00D0CF00:
		ptr = "	MORETON BAY";
		break;
	case 0x00D0D000:
		ptr = "	ZHONGXING TELECOM LTD.";
		break;
	case 0x00D0D100:
		ptr = "	SIROCCO SYSTEMS, INC.";
		break;
	case 0x00D0D200:
		ptr = "	EPILOG CORPORATION";
		break;
	case 0x00D0D300:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00D0D400:
		ptr = "	V-BITS, INC.";
		break;
	case 0x00D0D500:
		ptr = "	GRUNDIG AG";
		break;
	case 0x00D0D600:
		ptr = "	AETHRA TELECOMUNICAZIONI";
		break;
	case 0x00D0D700:
		ptr = "	B2C2, INC.";
		break;
	case 0x00D0D800:
		ptr = "	NOMADIC TECHNOLOGIES";
		break;
	case 0x00D0D900:
		ptr = "	DEDICATED MICROCOMPUTERS";
		break;
	case 0x00D0DA00:
		ptr = "	TAICOM DATA SYSTEMS CO., LTD.";
		break;
	case 0x00D0DB00:
		ptr = "	MCQUAY INTERNATIONAL";
		break;
	case 0x00D0DC00:
		ptr = "	MODULAR MINING SYSTEMS, INC.";
		break;
	case 0x00D0DD00:
		ptr = "	SUNRISE TELECOM, INC.";
		break;
	case 0x00D0DE00:
		ptr = "	PHILIPS MULTIMEDIA NETWORK";
		break;
	case 0x00D0DF00:
		ptr = "	KUZUMI ELECTRONICS, INC.";
		break;
	case 0x00D0E000:
		ptr = "	DOOIN ELECTRONICS CO.";
		break;
	case 0x00D0E100:
		ptr = "	AVIONITEK ISRAEL INC.";
		break;
	case 0x00D0E200:
		ptr = "	MRT MICRO, INC.";
		break;
	case 0x00D0E300:
		ptr = "	ELE-CHEM ENGINEERING CO., LTD.";
		break;
	case 0x00D0E400:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00D0E500:
		ptr = "	SOLIDUM SYSTEMS CORP.";
		break;
	case 0x00D0E600:
		ptr = "	IBOND INC.";
		break;
	case 0x00D0E700:
		ptr = "	VCON TELECOMMUNICATION LTD.";
		break;
	case 0x00D0E800:
		ptr = "	MAC SYSTEM CO., LTD.";
		break;
	case 0x00D0E900:
		ptr = "	ADVANTAGE CENTURY";
		break;
	case 0x00D0EA00:
		ptr = "	NEXTONE COMMUNICATIONS, INC.";
		break;
	case 0x00D0EB00:
		ptr = "	LIGHTERA NETWORKS, INC.";
		break;
	case 0x00D0EC00:
		ptr = "	NAKAYO TELECOMMUNICATIONS, INC";
		break;
	case 0x00D0ED00:
		ptr = "	XIOX";
		break;
	case 0x00D0EE00:
		ptr = "	DICTAPHONE CORPORATION";
		break;
	case 0x00D0EF00:
		ptr = "	IGT";
		break;
	case 0x00D0F000:
		ptr = "	CONVISION TECHNOLOGY GMBH";
		break;
	case 0x00D0F100:
		ptr = "	SEGA ENTERPRISES, LTD.";
		break;
	case 0x00D0F200:
		ptr = "	MONTEREY NETWORKS";
		break;
	case 0x00D0F300:
		ptr = "	SOLARI DI UDINE SPA";
		break;
	case 0x00D0F400:
		ptr = "	CARINTHIAN TECH INSTITUTE";
		break;
	case 0x00D0F500:
		ptr = "	ORANGE MICRO, INC.";
		break;
	case 0x00D0F600:
		ptr = "	NORTHCHURCH COMMUNICATIONS INC";
		break;
	case 0x00D0F700:
		ptr = "	NEXT NETS CORPORATION";
		break;
	case 0x00D0F800:
		ptr = "	FUJIAN STAR TERMINAL";
		break;
	case 0x00D0F900:
		ptr = "	ACUTE COMMUNICATIONS CORP.";
		break;
	case 0x00D0FA00:
		ptr = "	RACAL GUARDATA";
		break;
	case 0x00D0FB00:
		ptr = "	TEK MICROSYSTEMS, INCORPORATED";
		break;
	case 0x00D0FC00:
		ptr = "	GRANITE MICROSYSTEMS";
		break;
	case 0x00D0FD00:
		ptr = "	OPTIMA TELE.COM, INC.";
		break;
	case 0x00D0FE00:
		ptr = "	ASTRAL POINT";
		break;
	case 0x00D0FF00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00DD0000:
	case 0x00DD0100:
	case 0x00DD0200:
	case 0x00DD0300:
	case 0x00DD0400:
	case 0x00DD0500:
	case 0x00DD0600:
	case 0x00DD0700:
	case 0x00DD0800:
	case 0x00DD0900:
	case 0x00DD0A00:
	case 0x00DD0B00:
	case 0x00DD0C00:
	case 0x00DD0D00:
	case 0x00DD0E00:
	case 0x00DD0F00:
		ptr = "	UNGERMANN-BASS INC.";
		break;
	case 0x00E00000:
		ptr = "	FUJITSU, LTD";
		break;
	case 0x00E00100:
		ptr = "	STRAND LIGHTING LIMITED";
		break;
	case 0x00E00200:
		ptr = "	CROSSROADS SYSTEMS, INC.";
		break;
	case 0x00E00300:
		ptr = "	NOKIA WIRELESS BUSINESS COMMUN";
		break;
	case 0x00E00400:
		ptr = "	PMC-SIERRA, INC.";
		break;
	case 0x00E00500:
		ptr = "	TECHNICAL CORP.";
		break;
	case 0x00E00600:
		ptr = "	SILICON INTEGRATED SYS. CORP.";
		break;
	case 0x00E00700:
		ptr = "	NETWORK ALCHEMY LTD.";
		break;
	case 0x00E00800:
		ptr = "	AMAZING CONTROLS! INC.";
		break;
	case 0x00E00900:
		ptr = "	MARATHON TECHNOLOGIES CORP.";
		break;
	case 0x00E00A00:
		ptr = "	DIBA, INC.";
		break;
	case 0x00E00B00:
		ptr = "	ROOFTOP COMMUNICATIONS CORP.";
		break;
	case 0x00E00C00:
		ptr = "	MOTOROLA";
		break;
	case 0x00E00D00:
		ptr = "	RADIANT SYSTEMS";
		break;
	case 0x00E00E00:
		ptr = "	AVALON IMAGING SYSTEMS, INC.";
		break;
	case 0x00E00F00:
		ptr = "	SHANGHAI BAUD DATA";
		break;
	case 0x00E01000:
		ptr = "	HESS SB-AUTOMATENBAU GMBH";
		break;
	case 0x00E01100:
		ptr = "	UNIDEN SAN DIEGO";
		break;
	case 0x00E01200:
		ptr = "	PLUTO TECHNOLOGIES";
		break;
	case 0x00E01300:
		ptr = "	EASTERN ELECTRONIC CO., LTD.";
		break;
	case 0x00E01400:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00E01500:
		ptr = "	HEIWA CORPORATION";
		break;
	case 0x00E01600:
		ptr = "	RAPID CITY COMMUNICATIONS";
		break;
	case 0x00E01700:
		ptr = "	EXXACT GMBH";
		break;
	case 0x00E01800:
		ptr = "	ASUSTEK COMPUTER INC.";
		break;
	case 0x00E01900:
		ptr = "	ING. GIORDANO ELETTRONICA";
		break;
	case 0x00E01A00:
		ptr = "	COMTEC SYSTEMS. CO., LTD.";
		break;
	case 0x00E01B00:
		ptr = "	SPHERE COMMUNICATIONS, INC.";
		break;
	case 0x00E01C00:
		ptr = "	MOBILITY ELECTRONICSY";
		break;
	case 0x00E01D00:
		ptr = "	WEBTV NETWORKS, INC.";
		break;
	case 0x00E01E00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00E01F00:
		ptr = "	AVIDIA SYSTEMS, INC.";
		break;
	case 0x00E02000:
		ptr = "	TECNOMEN OY";
		break;
	case 0x00E02100:
		ptr = "	FREEGATE CORP.";
		break;
	case 0x00E02200:
		ptr = "	MEDIALIGHT INC.";
		break;
	case 0x00E02300:
		ptr = "	TELRAD";
		break;
	case 0x00E02400:
		ptr = "	GADZOOX NETWORKS";
		break;
	case 0x00E02500:
		ptr = "	DIT CO., LTD.";
		break;
	case 0x00E02600:
		ptr = "	EASTMAN KODAK CO.";
		break;
	case 0x00E02700:
		ptr = "	DUX, INC.";
		break;
	case 0x00E02800:
		ptr = "	APTIX CORPORATION";
		break;
	case 0x00E02900:
		ptr = "	STANDARD MICROSYSTEMS CORP.";
		break;
	case 0x00E02A00:
		ptr = "	TANDBERG TELEVISION AS";
		break;
	case 0x00E02B00:
		ptr = "	EXTREME NETWORKS";
		break;
	case 0x00E02C00:
		ptr = "	AST COMPUTER";
		break;
	case 0x00E02D00:
		ptr = "	INNOMEDIALOGIC, INC.";
		break;
	case 0x00E02E00:
		ptr = "	SPC ELECTRONICS CORPORATION";
		break;
	case 0x00E02F00:
		ptr = "	MCNS HOLDINGS, L.P.";
		break;
	case 0x00E03000:
		ptr = "	MELITA INTERNATIONAL CORP.";
		break;
	case 0x00E03100:
		ptr = "	HAGIWARA ELECTRIC CO., LTD.";
		break;
	case 0x00E03200:
		ptr = "	MISYS FINANCIAL SYSTEMS, LTD.";
		break;
	case 0x00E03300:
		ptr = "	E.E.P.D. GMBH";
		break;
	case 0x00E03400:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00E03500:
		ptr = "	LOUGHBOROUGH SOUND IMAGES, PLC";
		break;
	case 0x00E03600:
		ptr = "	PIONEER CORPORATION";
		break;
	case 0x00E03700:
		ptr = "	CENTURY CORPORATION";
		break;
	case 0x00E03800:
		ptr = "	PROXIMA CORPORATION";
		break;
	case 0x00E03900:
		ptr = "	PARADYNE CORP.";
		break;
	case 0x00E03A00:
		ptr = "	CABLETRON SYSTEMS, INC.";
		break;
	case 0x00E03B00:
		ptr = "	PROMINET CORPORATION";
		break;
	case 0x00E03C00:
		ptr = "	ADVANSYS";
		break;
	case 0x00E03D00:
		ptr = "	FOCON ELECTRONIC SYSTEMS A/S";
		break;
	case 0x00E03E00:
		ptr = "	ALFATECH, INC.";
		break;
	case 0x00E03F00:
		ptr = "	JATON CORPORATION";
		break;
	case 0x00E04000:
		ptr = "	DESKSTATION TECHNOLOGY, INC.";
		break;
	case 0x00E04100:
		ptr = "	CSPI";
		break;
	case 0x00E04200:
		ptr = "	PACOM DATA LTD.";
		break;
	case 0x00E04300:
		ptr = "	VITALCOM";
		break;
	case 0x00E04400:
		ptr = "	LSICS CORPORATION";
		break;
	case 0x00E04500:
		ptr = "	TOUCHWAVE, INC.";
		break;
	case 0x00E04600:
		ptr = "	BENTLY NEVADA CORP.";
		break;
	case 0x00E04700:
		ptr = "	INFOCUS SYSTEMS";
		break;
	case 0x00E04800:
		ptr = "	SDL COMMUNICATIONS, INC.";
		break;
	case 0x00E04900:
		ptr = "	MICROWI ELECTRONIC GMBH";
		break;
	case 0x00E04A00:
		ptr = "	ENHANCED MESSAGING SYSTEMS,INC";
		break;
	case 0x00E04B00:
		ptr = "	JUMP INDUSTRIELLE";
		break;
	case 0x00E04C00:
		ptr = "	REALTEK SEMICONDUCTOR CORP.";
		break;
	case 0x00E04D00:
		ptr = "	INTERNET INITIATIVE JAPAN, INC";
		break;
	case 0x00E04E00:
		ptr = "	SANYO DENKI CO., LTD.";
		break;
	case 0x00E04F00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00E05000:
		ptr = "	EXECUTONE INFORMATION";
		break;
	case 0x00E05100:
		ptr = "	TALX CORPORATION";
		break;
	case 0x00E05200:
		ptr = "	FOUNDRY NETWORKS, INC.";
		break;
	case 0x00E05300:
		ptr = "	CELLPORT LABS, INC.";
		break;
	case 0x00E05400:
		ptr = "	KODAI HITEC CO., LTD.";
		break;
	case 0x00E05500:
		ptr = "	INGENIERIA ELECTRONICA";
		break;
	case 0x00E05600:
		ptr = "	HOLONTECH CORPORATION";
		break;
	case 0x00E05700:
		ptr = "	HAN MICROTELECOM. CO., LTD.";
		break;
	case 0x00E05800:
		ptr = "	PHASE ONE DENMARK A/S";
		break;
	case 0x00E05900:
		ptr = "	CONTROLLED ENVIRONMENTS, LTD.";
		break;
	case 0x00E05A00:
		ptr = "	GALEA NETWORK SECURITY";
		break;
	case 0x00E05B00:
		ptr = "	WEST END SYSTEMS CORP.";
		break;
	case 0x00E05C00:
		ptr = "	MATSUSHITA KOTOBUKI";
		break;
	case 0x00E05D00:
		ptr = "	UNITEC CO., LTD.";
		break;
	case 0x00E05E00:
		ptr = "	JAPAN AVIATION ELECTRONICS";
		break;
	case 0x00E05F00:
		ptr = "	E-NET, INC.";
		break;
	case 0x00E06000:
		ptr = "	SHERWOOD";
		break;
	case 0x00E06100:
		ptr = "	EDGEPOINT NETWORKS, INC.";
		break;
	case 0x00E06200:
		ptr = "	HOST ENGINEERING";
		break;
	case 0x00E06300:
		ptr = "	CABLETRON - YAGO SYSTEMS, INC.";
		break;
	case 0x00E06400:
		ptr = "	SAMSUNG ELECTRONICS";
		break;
	case 0x00E06500:
		ptr = "	OPTICAL ACCESS INTERNATIONAL";
		break;
	case 0x00E06600:
		ptr = "	PROMAX SYSTEMS, INC.";
		break;
	case 0x00E06700:
		ptr = "	EAC AUTOMATION-CONSULTING GMBH";
		break;
	case 0x00E06800:
		ptr = "	MERRIMAC SYSTEMS INC.";
		break;
	case 0x00E06900:
		ptr = "	JAYCOR NETWORKS, INC.";
		break;
	case 0x00E06A00:
		ptr = "	KAPSCH AG";
		break;
	case 0x00E06B00:
		ptr = "	W&G SPECIAL PRODUCTS";
		break;
	case 0x00E06C00:
		ptr = "	BALTIMORE TECHNOLOGIES, LTD.";
		break;
	case 0x00E06D00:
		ptr = "	COMPUWARE CORPORATION";
		break;
	case 0x00E06E00:
		ptr = "	FAR SYSTEMS SPA";
		break;
	case 0x00E06F00:
		ptr = "	TERAYON CORP.";
		break;
	case 0x00E07000:
		ptr = "	DH TECHNOLOGY";
		break;
	case 0x00E07100:
		ptr = "	EPIS MICROCOMPUTER";
		break;
	case 0x00E07200:
		ptr = "	LYNK";
		break;
	case 0x00E07300:
		ptr = "	NATIONAL AMUSEMENT";
		break;
	case 0x00E07400:
		ptr = "	TIERNAN COMMUNICATIONS, INC.";
		break;
	case 0x00E07500:
		ptr = "	ATLAS COMPUTER EQUIPMENT, INC.";
		break;
	case 0x00E07600:
		ptr = "	DEVELOPMENT CONCEPTS, INC.";
		break;
	case 0x00E07700:
		ptr = "	WEBGEAR, INC.";
		break;
	case 0x00E07800:
		ptr = "	BERKELEY NETWORKS";
		break;
	case 0x00E07900:
		ptr = "	A.T.N.R.";
		break;
	case 0x00E07A00:
		ptr = "	MIKRODIDAKT AB";
		break;
	case 0x00E07B00:
		ptr = "	BAY NETWORKS";
		break;
	case 0x00E07C00:
		ptr = "	METTLER-TOLEDO, INC.";
		break;
	case 0x00E07D00:
		ptr = "	NETRONIX, INC.";
		break;
	case 0x00E07E00:
		ptr = "	WALT DISNEY IMAGINEERING";
		break;
	case 0x00E07F00:
		ptr = "	LOGISTISTEM SRL";
		break;
	case 0x00E08000:
		ptr = "	CONTROL RESOURCES CORPORATION";
		break;
	case 0x00E08100:
		ptr = "	TYAN COMPUTER CORP.";
		break;
	case 0x00E08200:
		ptr = "	ANERMA";
		break;
	case 0x00E08300:
		ptr = "	JATO TECHNOLOGIES, INC.";
		break;
	case 0x00E08400:
		ptr = "	COMPULITE R&D";
		break;
	case 0x00E08500:
		ptr = "	GLOBAL MAINTECH, INC.";
		break;
	case 0x00E08600:
		ptr = "	CYBEX COMPUTER PRODUCTS";
		break;
	case 0x00E08700:
		ptr = "	LECROY";
		break;
	case 0x00E08800:
		ptr = "	LTX CORPORATION";
		break;
	case 0x00E08900:
		ptr = "	MICROFRAME INC.";
		break;
	case 0x00E08A00:
		ptr = "	GEC AVERY, LTD.";
		break;
	case 0x00E08B00:
		ptr = "	QLOGIC CORP.";
		break;
	case 0x00E08C00:
		ptr = "	NEOPARADIGM LABS, INC.";
		break;
	case 0x00E08D00:
		ptr = "	PRESSURE SYSTEMS, INC.";
		break;
	case 0x00E08E00:
		ptr = "	UTSTARCOM";
		break;
	case 0x00E08F00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00E09000:
		ptr = "	BECKMAN LAB. AUTOMATION DIV.";
		break;
	case 0x00E09100:
		ptr = "	LG ELECTRONICS, INC.";
		break;
	case 0x00E09200:
		ptr = "	ADMTEK INCORPORATED";
		break;
	case 0x00E09300:
		ptr = "	ACKFIN NETWORKS";
		break;
	case 0x00E09400:
		ptr = "	OSAI SRL";
		break;
	case 0x00E09500:
		ptr = "	ADVANCED-VISION TECHNOLGIES";
		break;
	case 0x00E09600:
		ptr = "	SHIMADZU CORPORATION";
		break;
	case 0x00E09700:
		ptr = "	CARRIER ACCESS CORPORATION";
		break;
	case 0x00E09800:
		ptr = "	ABOCOM SYSTEMS, INC.";
		break;
	case 0x00E09900:
		ptr = "	SAMSON AG";
		break;
	case 0x00E09A00:
		ptr = "	POSITRON INDUSTRIES, INC.";
		break;
	case 0x00E09B00:
		ptr = "	ENGAGE NETWORKS, INC.";
		break;
	case 0x00E09C00:
		ptr = "	MII";
		break;
	case 0x00E09D00:
		ptr = "	SARNOFF CORPORATION";
		break;
	case 0x00E09E00:
		ptr = "	QUANTUM CORPORATION";
		break;
	case 0x00E09F00:
		ptr = "	PIXEL VISION";
		break;
	case 0x00E0A000:
		ptr = "	WILTRON CO.";
		break;
	case 0x00E0A100:
		ptr = "	HIMA PAUL HILDEBRANDT";
		break;
	case 0x00E0A200:
		ptr = "	MICROSLATE INC.";
		break;
	case 0x00E0A300:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00E0A400:
		ptr = "	ESAOTE S.P.A.";
		break;
	case 0x00E0A500:
		ptr = "	COMCORE SEMICONDUCTOR, INC.";
		break;
	case 0x00E0A600:
		ptr = "	TELOGY NETWORKS, INC.";
		break;
	case 0x00E0A700:
		ptr = "	IPC INFORMATION SYSTEMS, INC.";
		break;
	case 0x00E0A800:
		ptr = "	SAT GMBH&CO";
		break;
	case 0x00E0A900:
		ptr = "	FUNAI ELECTRIC CO., LTD.";
		break;
	case 0x00E0AA00:
		ptr = "	ELECTROSONIC LTD.";
		break;
	case 0x00E0AB00:
		ptr = "	DIMAT S.A.";
		break;
	case 0x00E0AC00:
		ptr = "	MIDSCO, INC.";
		break;
	case 0x00E0AD00:
		ptr = "	EES TECHNOLOGY, LTD.";
		break;
	case 0x00E0AE00:
		ptr = "	XAQTI CORPORATION";
		break;
	case 0x00E0AF00:
		ptr = "	GENERAL DYNAMICS INFORMATION";
		break;
	case 0x00E0B000:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00E0B100:
		ptr = "	PACKET ENGINES, INC.";
		break;
	case 0x00E0B200:
		ptr = "	TELMAX COMMUNICATIONS CORP.";
		break;
	case 0x00E0B300:
		ptr = "	ETHERWAN SYSTEMS, INC.";
		break;
	case 0x00E0B400:
		ptr = "	TECHNO SCOPE CO., LTD.";
		break;
	case 0x00E0B500:
		ptr = "	ARDENT COMMUNICATIONS CORP.";
		break;
	case 0x00E0B600:
		ptr = "	OSICOM TECHNOLOGIES";
		break;
	case 0x00E0B700:
		ptr = "	PI GROUP, LTD.";
		break;
	case 0x00E0B800:
		ptr = "	GATEWAY 2000";
		break;
	case 0x00E0B900:
		ptr = "	BYAS SYSTEMS";
		break;
	case 0x00E0BA00:
		ptr = "	BERGHOF AUTOMATIONSTECHNIK";
		break;
	case 0x00E0BB00:
		ptr = "	NBX CORPORATION";
		break;
	case 0x00E0BC00:
		ptr = "	SYMON COMMUNICATIONS, INC.";
		break;
	case 0x00E0BD00:
		ptr = "	INTERFACE SYSTEMS, INC.";
		break;
	case 0x00E0BE00:
		ptr = "	GENROCO INTERNATIONAL, INC.";
		break;
	case 0x00E0BF00:
		ptr = "	TORRENT NETWORKING";
		break;
	case 0x00E0C000:
		ptr = "	SEIWA ERECTRIC MFG. CO., LTD.";
		break;
	case 0x00E0C100:
		ptr = "	MEMOREX TELEX JAPAN, LTD.";
		break;
	case 0x00E0C200:
		ptr = "	NECSY SPA";
		break;
	case 0x00E0C300:
		ptr = "	SAKAI SYSTEM DEVELOPMENT CORP.";
		break;
	case 0x00E0C400:
		ptr = "	HORNER ELECTRIC, INC.";
		break;
	case 0x00E0C500:
		ptr = "	BCOM ELECTRONICS INC.";
		break;
	case 0x00E0C600:
		ptr = "	LINK2IT, L.L.C.";
		break;
	case 0x00E0C700:
		ptr = "	EUROTECH SRL";
		break;
	case 0x00E0C800:
		ptr = "	VIRTUAL ACCESS, LTD.";
		break;
	case 0x00E0C900:
		ptr = "	AUTOMATEDLOGIC CORPORATION";
		break;
	case 0x00E0CA00:
		ptr = "	BEST DATA PRODUCTS";
		break;
	case 0x00E0CB00:
		ptr = "	RESON, INC.";
		break;
	case 0x00E0CC00:
		ptr = "	HERO SYSTEMS, LTD.";
		break;
	case 0x00E0CD00:
		ptr = "	SENSIS CORPORATION";
		break;
	case 0x00E0CE00:
		ptr = "	ARN";
		break;
	case 0x00E0CF00:
		ptr = "	INTEGRATED DEVICE";
		break;
	case 0x00E0D000:
		ptr = "	NETSPEED, INC.";
		break;
	case 0x00E0D100:
		ptr = "	TELSIS LIMITED";
		break;
	case 0x00E0D200:
		ptr = "	VERSANET COMMUNICATIONS, INC.";
		break;
	case 0x00E0D300:
		ptr = "	DATENTECHNIK GMBH";
		break;
	case 0x00E0D400:
		ptr = "	EXCELLENT COMPUTER";
		break;
	case 0x00E0D500:
		ptr = "	ARCXEL TECHNOLOGIES, INC.";
		break;
	case 0x00E0D600:
		ptr = "	COMPUTER & COMMUNICATION";
		break;
	case 0x00E0D700:
		ptr = "	SUNSHINE ELECTRONICS, INC.";
		break;
	case 0x00E0D800:
		ptr = "	LANBIT COMPUTER, INC.";
		break;
	case 0x00E0D900:
		ptr = "	TAZMO CO., LTD.";
		break;
	case 0x00E0DA00:
		ptr = "	ASSURED ACCESS";
		break;
	case 0x00E0DB00:
		ptr = "	VIAVIDEO COMMUNICATIONS";
		break;
	case 0x00E0DC00:
		ptr = "	NEXWARE CORP.";
		break;
	case 0x00E0DD00:
		ptr = "	ZENITH ELECTRONICS CORPORATION";
		break;
	case 0x00E0DE00:
		ptr = "	DATAX NV";
		break;
	case 0x00E0DF00:
		ptr = "	KE KOMMUNIKATIONS-ELECTRONIK";
		break;
	case 0x00E0E000:
		ptr = "	SI ELECTRONICS, LTD.";
		break;
	case 0x00E0E100:
		ptr = "	G2 NETWORKS, ILNC.";
		break;
	case 0x00E0E200:
		ptr = "	INNOVA CORP.";
		break;
	case 0x00E0E300:
		ptr = "	SK-ELEKTRONIK GMBH";
		break;
	case 0x00E0E400:
		ptr = "	FANUC ROBOTICS NORTH AMERICA,";
		break;
	case 0x00E0E500:
		ptr = "	CINCO NETWORKS, INC.";
		break;
	case 0x00E0E600:
		ptr = "	INCAA DATACOM B.V.";
		break;
	case 0x00E0E700:
		ptr = "	RAYTHEON E-SYSTEMS, INC.";
		break;
	case 0x00E0E800:
		ptr = "	GRETACODER DATA SYSTEMS AG";
		break;
	case 0x00E0E900:
		ptr = "	DATA LABS, INC.";
		break;
	case 0x00E0EA00:
		ptr = "	INNOVAT COMMUNICATIONS, INC.";
		break;
	case 0x00E0EB00:
		ptr = "	DIGICOM SYSTEMS, INCORPORATED";
		break;
	case 0x00E0EC00:
		ptr = "	CELESTICA INC.";
		break;
	case 0x00E0ED00:
		ptr = "	SILICOM, LTD.";
		break;
	case 0x00E0EE00:
		ptr = "	MAREL HF";
		break;
	case 0x00E0EF00:
		ptr = "	DIONEX";
		break;
	case 0x00E0F000:
		ptr = "	ABLER TECHNOLOGY, INC.";
		break;
	case 0x00E0F100:
		ptr = "	THAT CORPORATION";
		break;
	case 0x00E0F200:
		ptr = "	ARLOTTO COMNET, INC.";
		break;
	case 0x00E0F300:
		ptr = "	WEBSPRINT COMMUNICATIONS, INC.";
		break;
	case 0x00E0F400:
		ptr = "	INSIDE TECHNOLOGY A/S";
		break;
	case 0x00E0F500:
		ptr = "	TELES AG";
		break;
	case 0x00E0F600:
		ptr = "	DECISION EUROPE";
		break;
	case 0x00E0F700:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00E0F800:
		ptr = "	DIANA CONTROL AB";
		break;
	case 0x00E0F900:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00E0FA00:
		ptr = "	TRL TECHNOLOGY, LTD.";
		break;
	case 0x00E0FB00:
		ptr = "	LEIGHTRONIX, INC.";
		break;
	case 0x00E0FC00:
		ptr = "	HUAWEI TECHNOLOGIES CO., LTD.";
		break;
	case 0x00E0FD00:
		ptr = "	A-TREND TECHNOLOGY CO., LTD.";
		break;
	case 0x00E0FE00:
		ptr = "	CISCO SYSTEMS, INC.";
		break;
	case 0x00E0FF00:
		ptr = "	SECURITY DYNAMICS TECHNOLOGIES";
		break;
	case 0x00E6D300:
		ptr = "	NIXDORF COMPUTER CORP.";
		break;
	case 0x02070100:
		ptr = "	RACAL-DATACOM";
		break;
	case 0x021C7C00:
		ptr = "	PERQ SYSTEMS CORPORATION";
		break;
	case 0x02608600:
		ptr = "	LOGIC REPLACEMENT TECH. LTD.";
		break;
	case 0x02608C00:
		ptr = "	3COM CORPORATION";
		break;
	case 0x02700100:
		ptr = "	RACAL-DATACOM";
		break;
	case 0x0270B000:
		ptr = "	M/A-COM INC. COMPANIES";
		break;
	case 0x0270B300:
		ptr = "	DATA RECALL LTD";
		break;
	case 0x029D8E00:
		ptr = "	CARDIAC RECORDERS INC.";
		break;
	case 0x02AA3C00:
		ptr = "	OLIVETTI TELECOMM SPA (OLTECO)";
		break;
	case 0x02BB0100:
		ptr = "	OCTOTHORPE CORP.";
		break;
	case 0x02C08C00:
		ptr = "	3COM CORPORATION";
		break;
	case 0x02CF1C00:
		ptr = "	COMMUNICATION MACHINERY CORP.";
		break;
	case 0x02E6D300:
		ptr = "	NIXDORF COMPUTER CORPORATION";
		break;
	case 0x040AE000:
		ptr = "	XMIT AG COMPUTER NETWORKS";
		break;
	case 0x04E0C400:
		ptr = "	TRIUMPH-ADLER AG";
		break;
	case 0x08000100:
		ptr = "	COMPUTERVISION CORPORATION";
		break;
	case 0x08000200:
		ptr = "	BRIDGE COMMUNICATIONS INC.";
		break;
	case 0x08000300:
		ptr = "	ADVANCED COMPUTER COMM.";
		break;
	case 0x08000400:
		ptr = "	CROMEMCO INCORPORATED";
		break;
	case 0x08000500:
		ptr = "	SYMBOLICS INC.";
		break;
	case 0x08000600:
		ptr = "	SIEMENS AG";
		break;
	case 0x08000700:
		ptr = "	APPLE COMPUTER INC.";
		break;
	case 0x08000800:
		ptr = "	BOLT BERANEK AND NEWMAN INC.";
		break;
	case 0x08000900:
		ptr = "	HEWLETT PACKARD";
		break;
	case 0x08000A00:
		ptr = "	NESTAR SYSTEMS INCORPORATED";
		break;
	case 0x08000B00:
		ptr = "	UNISYS CORPORATION";
		break;
	case 0x08000C00:
		ptr = "	MIKLYN DEVELOPMENT CO.";
		break;
	case 0x08000D00:
		ptr = "	INTERNATIONAL COMPUTERS LTD.";
		break;
	case 0x08000E00:
		ptr = "	NCR CORPORATION";
		break;
	case 0x08000F00:
		ptr = "	MITEL CORPORATION";
		break;
	case 0x08001100:
		ptr = "	TEKTRONIX INC.";
		break;
	case 0x08001200:
		ptr = "	BELL ATLANTIC INTEGRATED SYST.";
		break;
	case 0x08001300:
		ptr = "	EXXON";
		break;
	case 0x08001400:
		ptr = "	EXCELAN";
		break;
	case 0x08001500:
		ptr = "	STC BUSINESS SYSTEMS";
		break;
	case 0x08001600:
		ptr = "	BARRISTER INFO SYS CORP";
		break;
	case 0x08001700:
		ptr = "	NATIONAL SEMICONDUCTOR";
		break;
	case 0x08001800:
		ptr = "	PIRELLI FOCOM NETWORKS";
		break;
	case 0x08001900:
		ptr = "	GENERAL ELECTRIC CORPORATION";
		break;
	case 0x08001A00:
		ptr = "	TIARA/ 10NET";
		break;
	case 0x08001B00:
		ptr = "	DATA GENERAL";
		break;
	case 0x08001C00:
		ptr = "	KDD-KOKUSAI DEBNSIN DENWA CO.";
		break;
	case 0x08001D00:
		ptr = "	ABLE COMMUNICATIONS INC.";
		break;
	case 0x08001E00:
		ptr = "	APOLLO COMPUTER INC.";
		break;
	case 0x08001F00:
		ptr = "	SHARP CORPORATION";
		break;
	case 0x08002000:
		ptr = "	SUN MICROSYSTEMS INC.";
		break;
	case 0x08002100:
		ptr = "	3M COMPANY";
		break;
	case 0x08002200:
		ptr = "	NBI INC.";
		break;
	case 0x08002300:
		ptr = "	MATSUHITA GRAPHIC COMM SYS INC";
		break;
	case 0x08002400:
		ptr = "	10NET COMMUNICATIONS/DCA";
		break;
	case 0x08002500:
		ptr = "	CONTROL DATA";
		break;
	case 0x08002600:
		ptr = "	NORSK DATA A.S.";
		break;
	case 0x08002700:
		ptr = "	CADMUS COMPUTER SYSTEMS";
		break;
	case 0x08002800:
		ptr = "	TEXAS INSTRUMENTS";
		break;
	case 0x08002900:
		ptr = "	MEGATEK CORPORATION";
		break;
	case 0x08002A00:
		ptr = "	MOSAIC TECHNOLOGIES INC.";
		break;
	case 0x08002B00:
		ptr = "	DIGITAL EQUIPMENT CORPORATION";
		break;
	case 0x08002C00:
		ptr = "	BRITTON LEE INC.";
		break;
	case 0x08002D00:
		ptr = "	LAN-TEC INC.";
		break;
	case 0x08002E00:
		ptr = "	METAPHOR COMPUTER SYSTEMS";
		break;
	case 0x08002F00:
		ptr = "	PRIME COMPUTER INC.";
		break;
	case 0x08003000:
		ptr = "	NETWORK RESEARCH CORPORATION";
		break;
#if 0  // duplicates??
	case 0x08003000:
		ptr = "	CERN";
		break;
	case 0x08003000:
		ptr = "	ROYAL MELBOURNE INST OF TECH";
		break;
#endif
	case 0x08003100:
		ptr = "	LITTLE MACHINES INC.";
		break;
	case 0x08003200:
		ptr = "	TIGAN INCORPORATED";
		break;
	case 0x08003300:
		ptr = "	BAUSCH & LOMB";
		break;
	case 0x08003400:
		ptr = "	FILENET CORPORATION";
		break;
	case 0x08003500:
		ptr = "	MICROFIVE CORPORATION";
		break;
	case 0x08003600:
		ptr = "	INTERGRAPH CORPORATION";
		break;
	case 0x08003700:
		ptr = "	FUJI-XEROX CO. LTD.";
		break;
	case 0x08003800:
		ptr = "	CII HONEYWELL BULL";
		break;
	case 0x08003900:
		ptr = "	SPIDER SYSTEMS LIMITED";
		break;
	case 0x08003A00:
		ptr = "	ORCATECH INC.";
		break;
	case 0x08003B00:
		ptr = "	TORUS SYSTEMS LIMITED";
		break;
	case 0x08003C00:
		ptr = "	SCHLUMBERGER WELL SERVICES";
		break;
	case 0x08003D00:
		ptr = "	CADNETIX CORPORATIONS";
		break;
	case 0x08003E00:
		ptr = "	CODEX CORPORATION";
		break;
	case 0x08003F00:
		ptr = "	FRED KOSCHARA ENTERPRISES";
		break;
	case 0x08004000:
		ptr = "	FERRANTI COMPUTER SYS. LIMITED";
		break;
	case 0x08004100:
		ptr = "	RACAL-MILGO INFORMATION SYS..";
		break;
	case 0x08004200:
		ptr = "	JAPAN MACNICS CORP.";
		break;
	case 0x08004300:
		ptr = "	PIXEL COMPUTER INC.";
		break;
	case 0x08004400:
		ptr = "	DAVID SYSTEMS INC.";
		break;
	case 0x08004500:
		ptr = "	CONCURRENT COMPUTER CORP.";
		break;
	case 0x08004600:
		ptr = "	SONY CORPORATION LTD.";
		break;
	case 0x08004700:
		ptr = "	SEQUENT COMPUTER SYSTEMS INC.";
		break;
	case 0x08004800:
		ptr = "	EUROTHERM GAUGING SYSTEMS";
		break;
	case 0x08004900:
		ptr = "	UNIVATION";
		break;
	case 0x08004A00:
		ptr = "	BANYAN SYSTEMS INC.";
		break;
	case 0x08004B00:
		ptr = "	PLANNING RESEARCH CORP.";
		break;
	case 0x08004C00:
		ptr = "	HYDRA COMPUTER SYSTEMS INC.";
		break;
	case 0x08004D00:
		ptr = "	CORVUS SYSTEMS INC.";
		break;
	case 0x08004E00:
		ptr = "	3COM EUROPE LTD.";
		break;
	case 0x08004F00:
		ptr = "	CYGNET SYSTEMS";
		break;
	case 0x08005000:
		ptr = "	DAISY SYSTEMS CORP.";
		break;
	case 0x08005100:
		ptr = "	EXPERDATA";
		break;
	case 0x08005200:
		ptr = "	INSYSTEC";
		break;
	case 0x08005300:
		ptr = "	MIDDLE EAST TECH. UNIVERSITY";
		break;
	case 0x08005500:
		ptr = "	STANFORD TELECOMM. INC.";
		break;
	case 0x08005600:
		ptr = "	STANFORD LINEAR ACCEL. CENTER";
		break;
	case 0x08005700:
		ptr = "	EVANS & SUTHERLAND";
		break;
	case 0x08005800:
		ptr = "	SYSTEMS CONCEPTS";
		break;
	case 0x08005900:
		ptr = "	A/S MYCRON";
		break;
	case 0x08005A00:
		ptr = "	IBM CORPORATION";
		break;
	case 0x08005B00:
		ptr = "	VTA TECHNOLOGIES INC.";
		break;
	case 0x08005C00:
		ptr = "	FOUR PHASE SYSTEMS";
		break;
	case 0x08005D00:
		ptr = "	GOULD INC.";
		break;
	case 0x08005E00:
		ptr = "	COUNTERPOINT COMPUTER INC.";
		break;
	case 0x08005F00:
		ptr = "	SABER TECHNOLOGY CORP.";
		break;
	case 0x08006000:
		ptr = "	INDUSTRIAL NETWORKING INC.";
		break;
	case 0x08006100:
		ptr = "	JAROGATE LTD.";
		break;
	case 0x08006200:
		ptr = "	GENERAL DYNAMICS";
		break;
	case 0x08006300:
		ptr = "	PLESSEY";
		break;
	case 0x08006400:
		ptr = "	AUTOPHON AG";
		break;
	case 0x08006500:
		ptr = "	GENRAD INC.";
		break;
	case 0x08006600:
		ptr = "	AGFA CORPORATION";
		break;
	case 0x08006700:
		ptr = "	COMDESIGN";
		break;
	case 0x08006800:
		ptr = "	RIDGE COMPUTERS";
		break;
	case 0x08006900:
		ptr = "	SILICON GRAPHICS INC.";
		break;
	case 0x08006A00:
		ptr = "	ATT BELL LABORATORIES";
		break;
	case 0x08006B00:
		ptr = "	ACCEL TECHNOLOGIES INC.";
		break;
	case 0x08006C00:
		ptr = "	SUNTEK TECHNOLOGY INT'L";
		break;
	case 0x08006D00:
		ptr = "	WHITECHAPEL COMPUTER WORKS";
		break;
	case 0x08006E00:
		ptr = "	MASSCOMP";
		break;
	case 0x08006F00:
		ptr = "	PHILIPS APELDOORN B.V.";
		break;
	case 0x08007000:
		ptr = "	MITSUBISHI ELECTRIC CORP.";
		break;
	case 0x08007100:
		ptr = "	MATRA (DSIE)";
		break;
	case 0x08007200:
		ptr = "	XEROX CORP UNIV GRANT PROGRAM";
		break;
	case 0x08007300:
		ptr = "	TECMAR INC.";
		break;
	case 0x08007400:
		ptr = "	CASIO COMPUTER CO. LTD.";
		break;
	case 0x08007500:
		ptr = "	DANSK DATA ELECTRONIK";
		break;
	case 0x08007600:
		ptr = "	PC LAN TECHNOLOGIES";
		break;
	case 0x08007700:
		ptr = "	TSL COMMUNICATIONS LTD.";
		break;
	case 0x08007800:
		ptr = "	ACCELL CORPORATION";
		break;
	case 0x08007900:
		ptr = "	THE DROID WORKS";
		break;
	case 0x08007A00:
		ptr = "	INDATA";
		break;
	case 0x08007B00:
		ptr = "	SANYO ELECTRIC CO. LTD.";
		break;
	case 0x08007C00:
		ptr = "	VITALINK COMMUNICATIONS CORP.";
		break;
	case 0x08007E00:
		ptr = "	AMALGAMATED WIRELESS(AUS) LTD";
		break;
	case 0x08007F00:
		ptr = "	CARNEGIE-MELLON UNIVERSITY";
		break;
	case 0x08008000:
		ptr = "	AES DATA INC.";
		break;
	case 0x08008100:
		ptr = "	,ASTECH INC.";
		break;
	case 0x08008200:
		ptr = "	VERITAS SOFTWARE";
		break;
	case 0x08008300:
		ptr = "	SEIKO INSTRUM. AND ELECTRONICS";
		break;
	case 0x08008400:
		ptr = "	TOMEN ELECTRONICS CORP.";
		break;
	case 0x08008500:
		ptr = "	ELXSI";
		break;
	case 0x08008600:
		ptr = "	IMAGEN CORPORATION";
		break;
	case 0x08008700:
		ptr = "	XYPLEX";
		break;
	case 0x08008800:
		ptr = "	MCDATA CORPORATION";
		break;
	case 0x08008900:
		ptr = "	KINETICS";
		break;
	case 0x08008A00:
		ptr = "	PERFORMANCE TECHNOLOGY";
		break;
	case 0x08008B00:
		ptr = "	PYRAMID TECHNOLOGY CORP.";
		break;
	case 0x08008C00:
		ptr = "	NETWORK RESEARCH CORPORATION";
		break;
	case 0x08008D00:
		ptr = "	XYVISION INC.";
		break;
	case 0x08008E00:
		ptr = "	TANDEM COMPUTERS";
		break;
	case 0x08008F00:
		ptr = "	CHIPCOM CORPORATION";
		break;
	case 0x08009000:
		ptr = "	SONOMA SYSTEMS";
		break;
	case 0x08BBCC00:
		ptr = "	AK-NORD EDV VERTRIEBSGES. MBH";
		break;
	case 0x10005A00:
		ptr = "	IBM CORPORATION";
		break;
	case 0x1000E800:
		ptr = "	NATIONAL SEMICONDUCTOR";
		break;
	case 0x80001000:
		ptr = "	ATT BELL LABORATORIES";
		break;
	case 0xAA000000:
	case 0xAA000100:
	case 0xAA000200:
	case 0xAA000300:
	case 0xAA000400:
		ptr = " DIGITAL EQUIPMENT CORPORATION";
		break;
	case 0x44455300:
		ptr = "Dialup adapter?";
		break;
	default:
		ptr = "Unknown!";
		break;
	}

	return ptr;
}