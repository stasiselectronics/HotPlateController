EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Sensor_Temperature:MAX31855KASA U4
U 1 1 5F92CAE2
P 9450 4950
F 0 "U4" H 9850 5450 50  0000 C CNN
F 1 "MAX31855KASA" H 10100 5350 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 10450 4600 50  0001 C CIN
F 3 "http://datasheets.maximintegrated.com/en/ds/MAX31855.pdf" H 9450 4950 50  0001 C CNN
	1    9450 4950
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J5
U 1 1 5F92E2A4
P 8550 4950
F 0 "J5" H 8468 4625 50  0000 C CNN
F 1 "Thermocouple" H 8468 4716 50  0000 C CNN
F 2 "TerminalBlock_TE-Connectivity:TerminalBlock_TE_282834-2_1x02_P2.54mm_Horizontal" H 8550 4950 50  0001 C CNN
F 3 "~" H 8550 4950 50  0001 C CNN
	1    8550 4950
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D1
U 1 1 5FFA34C2
P 8400 1200
F 0 "D1" H 8393 1417 50  0000 C CNN
F 1 "LED" H 8393 1326 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 8400 1200 50  0001 C CNN
F 3 "~" H 8400 1200 50  0001 C CNN
	1    8400 1200
	-1   0    0    1   
$EndComp
$Comp
L Device:R R5
U 1 1 5FFA3C43
P 8800 1500
F 0 "R5" H 8870 1546 50  0000 L CNN
F 1 "R" H 8870 1455 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 8730 1500 50  0001 C CNN
F 3 "~" H 8800 1500 50  0001 C CNN
	1    8800 1500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR021
U 1 1 5FFA4BC6
P 8800 1850
F 0 "#PWR021" H 8800 1600 50  0001 C CNN
F 1 "GND" H 8805 1677 50  0000 C CNN
F 2 "" H 8800 1850 50  0001 C CNN
F 3 "" H 8800 1850 50  0001 C CNN
	1    8800 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 1200 8800 1200
Wire Wire Line
	8800 1200 8800 1350
Wire Wire Line
	8800 1650 8800 1850
Wire Wire Line
	8250 1200 8050 1200
$Comp
L Device:LED D2
U 1 1 5FFAA004
P 10100 1200
F 0 "D2" H 10093 1417 50  0000 C CNN
F 1 "LED" H 10093 1326 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 10100 1200 50  0001 C CNN
F 3 "~" H 10100 1200 50  0001 C CNN
	1    10100 1200
	-1   0    0    1   
$EndComp
$Comp
L Device:R R7
U 1 1 5FFAA00A
P 10500 1500
F 0 "R7" H 10570 1546 50  0000 L CNN
F 1 "R" H 10570 1455 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 10430 1500 50  0001 C CNN
F 3 "~" H 10500 1500 50  0001 C CNN
	1    10500 1500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR025
U 1 1 5FFAA010
P 10500 1850
F 0 "#PWR025" H 10500 1600 50  0001 C CNN
F 1 "GND" H 10505 1677 50  0000 C CNN
F 2 "" H 10500 1850 50  0001 C CNN
F 3 "" H 10500 1850 50  0001 C CNN
	1    10500 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	10250 1200 10500 1200
Wire Wire Line
	10500 1200 10500 1350
Wire Wire Line
	10500 1650 10500 1850
Wire Wire Line
	9950 1200 9750 1200
$Comp
L Connector_Generic:Conn_01x02 J4
U 1 1 5FFAA848
P 6450 5350
F 0 "J4" H 6368 5567 50  0000 C CNN
F 1 "Conn_01x02" H 6368 5476 50  0000 C CNN
F 2 "" H 6450 5350 50  0001 C CNN
F 3 "~" H 6450 5350 50  0001 C CNN
	1    6450 5350
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR020
U 1 1 5FFAC57B
P 6950 5900
F 0 "#PWR020" H 6950 5650 50  0001 C CNN
F 1 "GND" H 6955 5727 50  0000 C CNN
F 2 "" H 6950 5900 50  0001 C CNN
F 3 "" H 6950 5900 50  0001 C CNN
	1    6950 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 5900 6950 5450
Wire Wire Line
	6950 5450 6650 5450
Wire Wire Line
	7550 4900 6950 4900
Wire Wire Line
	6950 4900 6950 5350
Wire Wire Line
	6950 5350 6650 5350
Text Label 7550 4900 2    50   ~ 0
SSRelay_Trigger
Wire Wire Line
	8750 4950 8850 4950
Wire Wire Line
	8850 4950 8850 5050
Wire Wire Line
	8850 5050 9050 5050
Wire Wire Line
	8750 4850 9050 4850
$Comp
L power:+3V3 #PWR023
U 1 1 5FFB7CD6
P 9450 4450
F 0 "#PWR023" H 9450 4300 50  0001 C CNN
F 1 "+3V3" H 9465 4623 50  0000 C CNN
F 2 "" H 9450 4450 50  0001 C CNN
F 3 "" H 9450 4450 50  0001 C CNN
	1    9450 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9450 4450 9450 4550
$Comp
L power:GND #PWR024
U 1 1 5FFBB35B
P 9450 5500
F 0 "#PWR024" H 9450 5250 50  0001 C CNN
F 1 "GND" H 9455 5327 50  0000 C CNN
F 2 "" H 9450 5500 50  0001 C CNN
F 3 "" H 9450 5500 50  0001 C CNN
	1    9450 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9450 5350 9450 5500
$Comp
L Sensor_Current:ACS712xLCTR-20A U2
U 1 1 5FFC34DE
P 2700 5350
F 0 "U2" V 3350 6150 50  0000 R CNN
F 1 "ACS712xLCTR-20A" V 3250 6150 50  0000 R CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 2800 5000 50  0001 L CIN
F 3 "http://www.allegromicro.com/~/media/Files/Datasheets/ACS712-Datasheet.ashx?la=en" H 2700 5350 50  0001 C CNN
F 4 "" H 2700 5350 50  0001 C CNN "Ordering Code"
F 5 "Allegro MicroSystems, LLC" H 2700 5350 50  0001 C CNN "MF 1"
F 6 "ACS712ELCTR-20A-T" H 2700 5350 50  0001 C CNN "MF 1 MPN"
F 7 "C10681" H 2700 5350 50  0001 C CNN "MF 1 Ordering Code"
	1    2700 5350
	0    -1   -1   0   
$EndComp
$Comp
L Converter_ACDC:HLK-PM01 PS1
U 1 1 5FFC34E4
P 2800 6950
F 0 "PS1" H 2800 7275 50  0000 C CNN
F 1 "HLK-PM01" H 2800 7184 50  0000 C CNN
F 2 "Converter_ACDC:Converter_ACDC_HiLink_HLK-PMxx" H 2800 6650 50  0001 C CNN
F 3 "http://www.hlktech.net/product_detail.php?ProId=54" H 3200 6600 50  0001 C CNN
	1    2800 6950
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x03 J2
U 1 1 5FFC34F0
P 1450 6250
F 0 "J2" H 1368 6567 50  0000 C CNN
F 1 "Screw_Terminal_01x03" H 1368 6476 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-3_P5.08mm" H 1450 6250 50  0001 C CNN
F 3 "~" H 1450 6250 50  0001 C CNN
	1    1450 6250
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x03 J3
U 1 1 5FFC34F6
P 4150 6250
F 0 "J3" H 4068 5925 50  0000 C CNN
F 1 "Screw_Terminal_01x03" H 4068 6016 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-3_P5.08mm" H 4150 6250 50  0001 C CNN
F 3 "~" H 4150 6250 50  0001 C CNN
	1    4150 6250
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5FFC350B
P 3250 7150
F 0 "#PWR013" H 3250 6900 50  0001 C CNN
F 1 "GND" H 3255 6977 50  0000 C CNN
F 2 "" H 3250 7150 50  0001 C CNN
F 3 "" H 3250 7150 50  0001 C CNN
	1    3250 7150
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR08
U 1 1 5FFC3511
P 1700 6500
F 0 "#PWR08" H 1700 6250 50  0001 C CNN
F 1 "Earth" H 1700 6350 50  0001 C CNN
F 2 "" H 1700 6500 50  0001 C CNN
F 3 "~" H 1700 6500 50  0001 C CNN
	1    1700 6500
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR012
U 1 1 5FFC351D
P 3250 6750
F 0 "#PWR012" H 3250 6600 50  0001 C CNN
F 1 "+5V" H 3265 6923 50  0000 C CNN
F 2 "" H 3250 6750 50  0001 C CNN
F 3 "" H 3250 6750 50  0001 C CNN
	1    3250 6750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 6350 1700 6350
Wire Wire Line
	1700 6350 1700 6500
Wire Wire Line
	1700 6350 3950 6350
Connection ~ 1700 6350
Wire Wire Line
	2500 6150 2200 6150
Wire Wire Line
	3200 6850 3250 6850
Wire Wire Line
	3250 6850 3250 6750
Wire Wire Line
	3200 7050 3250 7050
Wire Wire Line
	3250 7050 3250 7150
Wire Wire Line
	3950 6250 2100 6250
Wire Wire Line
	2400 7050 2100 7050
Wire Wire Line
	2100 7050 2100 6250
Connection ~ 2100 6250
Wire Wire Line
	2100 6250 1650 6250
Wire Wire Line
	2200 6150 2200 6850
Wire Wire Line
	2200 6850 2400 6850
Connection ~ 2200 6150
Wire Wire Line
	2200 6150 1650 6150
Text Label 10550 4750 2    50   ~ 0
ESP32_SPI_SCK
Wire Wire Line
	9850 4750 10550 4750
$Comp
L Device:R R?
U 1 1 5FFD3016
P 5025 3075
AR Path="/5F45F2B5/5FFD3016" Ref="R?"  Part="1" 
AR Path="/5FFD3016" Ref="R3"  Part="1" 
AR Path="/5FFB786E/5FFD3016" Ref="R?"  Part="1" 
AR Path="/5FFB9C6F/5FFD3016" Ref="R?"  Part="1" 
F 0 "R3" H 5095 3121 50  0000 L CNN
F 1 "10k 5% 0.25W" H 5095 3030 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 4955 3075 50  0001 C CNN
F 3 "~" H 5025 3075 50  0001 C CNN
F 4 "Yageo" H 5025 3075 50  0001 C CNN "MF 1"
F 5 "RC1206JR-0710KL" H 5025 3075 50  0001 C CNN "MF 1 MPN"
	1    5025 3075
	1    0    0    -1  
$EndComp
Wire Wire Line
	5025 3225 5025 3425
Text Label 5075 3425 0    50   ~ 0
EN
$Comp
L power:+3.3V #PWR?
U 1 1 5FFD301E
P 5025 2775
AR Path="/5F45F2B5/5FFD301E" Ref="#PWR?"  Part="1" 
AR Path="/5FFD301E" Ref="#PWR016"  Part="1" 
AR Path="/5FFB786E/5FFD301E" Ref="#PWR?"  Part="1" 
AR Path="/5FFB9C6F/5FFD301E" Ref="#PWR?"  Part="1" 
F 0 "#PWR016" H 5025 2625 50  0001 C CNN
F 1 "+3.3V" H 5040 2948 50  0000 C CNN
F 2 "" H 5025 2775 50  0001 C CNN
F 3 "" H 5025 2775 50  0001 C CNN
	1    5025 2775
	1    0    0    -1  
$EndComp
Wire Wire Line
	5025 2775 5025 2925
$Comp
L Device:C C?
U 1 1 5FFD3027
P 1525 1900
AR Path="/5F45F2B5/5FFD3027" Ref="C?"  Part="1" 
AR Path="/5FFD3027" Ref="C4"  Part="1" 
AR Path="/5FFB786E/5FFD3027" Ref="C?"  Part="1" 
AR Path="/5FFB9C6F/5FFD3027" Ref="C?"  Part="1" 
F 0 "C4" H 1640 1946 50  0000 L CNN
F 1 "1uF 50V" H 1640 1855 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 1563 1750 50  0001 C CNN
F 3 "~" H 1525 1900 50  0001 C CNN
F 4 "Samsung Electro-Mechanics" H 1525 1900 50  0001 C CNN "MF 1"
F 5 "CL31B105KBHNFNE" H 1525 1900 50  0001 C CNN "MF 1 MPN"
	1    1525 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	925  2050 925  2100
Wire Wire Line
	925  2100 1525 2100
Wire Wire Line
	1525 2100 1525 2050
Wire Wire Line
	925  1750 925  1700
Wire Wire Line
	925  1700 1525 1700
Wire Wire Line
	1525 1700 1525 1750
Wire Wire Line
	925  1700 925  1600
$Comp
L power:+3.3V #PWR?
U 1 1 5FFD3034
P 925 1600
AR Path="/5F45F2B5/5FFD3034" Ref="#PWR?"  Part="1" 
AR Path="/5FFD3034" Ref="#PWR05"  Part="1" 
AR Path="/5FFB786E/5FFD3034" Ref="#PWR?"  Part="1" 
AR Path="/5FFB9C6F/5FFD3034" Ref="#PWR?"  Part="1" 
F 0 "#PWR05" H 925 1450 50  0001 C CNN
F 1 "+3.3V" H 940 1773 50  0000 C CNN
F 2 "" H 925 1600 50  0001 C CNN
F 3 "" H 925 1600 50  0001 C CNN
	1    925  1600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FFD303A
P 1525 2200
AR Path="/5F45F2B5/5FFD303A" Ref="#PWR?"  Part="1" 
AR Path="/5FFD303A" Ref="#PWR06"  Part="1" 
AR Path="/5FFB786E/5FFD303A" Ref="#PWR?"  Part="1" 
AR Path="/5FFB9C6F/5FFD303A" Ref="#PWR?"  Part="1" 
F 0 "#PWR06" H 1525 1950 50  0001 C CNN
F 1 "GND" H 1530 2027 50  0000 C CNN
F 2 "" H 1525 2200 50  0001 C CNN
F 3 "" H 1525 2200 50  0001 C CNN
	1    1525 2200
	1    0    0    -1  
$EndComp
Connection ~ 1525 2100
Wire Wire Line
	1525 2200 1525 2100
Connection ~ 925  1700
Text Label 2250 1050 0    50   ~ 0
EN
Text Label 4100 1150 2    50   ~ 0
USB_RX
Text Label 4100 1350 2    50   ~ 0
USB_TX
$Comp
L Switch:SW_Push SW?
U 1 1 5FFD3052
P 6025 3425
AR Path="/5F45F2B5/5FFD3052" Ref="SW?"  Part="1" 
AR Path="/5FFD3052" Ref="SW2"  Part="1" 
AR Path="/5FFB786E/5FFD3052" Ref="SW?"  Part="1" 
AR Path="/5FFB9C6F/5FFD3052" Ref="SW?"  Part="1" 
F 0 "SW2" H 6025 3710 50  0000 C CNN
F 1 "SPST (RED)" H 6025 3619 50  0000 C CNN
F 2 ".DesignArchive:PTS636_SM25F_SMTR_LFS" H 6025 3625 50  0001 C CNN
F 3 "~" H 6025 3625 50  0001 C CNN
F 4 "TE Connectivity ALCOSWITCH Switches" H 6025 3425 50  0001 C CNN "MF 1"
F 5 "1825027-6" H 6025 3425 50  0001 C CNN "MF 1 MPN"
	1    6025 3425
	1    0    0    -1  
$EndComp
Wire Wire Line
	6225 3425 6475 3425
Wire Wire Line
	6475 3425 6475 3625
$Comp
L power:GND #PWR?
U 1 1 5FFD305A
P 6475 3725
AR Path="/5F45F2B5/5FFD305A" Ref="#PWR?"  Part="1" 
AR Path="/5FFD305A" Ref="#PWR019"  Part="1" 
AR Path="/5FFB786E/5FFD305A" Ref="#PWR?"  Part="1" 
AR Path="/5FFB9C6F/5FFD305A" Ref="#PWR?"  Part="1" 
F 0 "#PWR019" H 6475 3475 50  0001 C CNN
F 1 "GND" H 6480 3552 50  0000 C CNN
F 2 "" H 6475 3725 50  0001 C CNN
F 3 "" H 6475 3725 50  0001 C CNN
	1    6475 3725
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5FFD3062
P 6025 3625
AR Path="/5F45F2B5/5FFD3062" Ref="C?"  Part="1" 
AR Path="/5FFD3062" Ref="C8"  Part="1" 
AR Path="/5FFB786E/5FFD3062" Ref="C?"  Part="1" 
AR Path="/5FFB9C6F/5FFD3062" Ref="C?"  Part="1" 
F 0 "C8" V 6175 3625 50  0000 C CNN
F 1 "1nF 50V" V 6275 3625 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 6063 3475 50  0001 C CNN
F 3 "~" H 6025 3625 50  0001 C CNN
F 4 "Walsin Technology Corporation" H 6025 3625 50  0001 C CNN "MF 1"
F 5 "1206B102K500CT" H 6025 3625 50  0001 C CNN "MF 1 MPN"
	1    6025 3625
	0    1    1    0   
$EndComp
Connection ~ 5775 3425
Wire Wire Line
	5775 3425 5825 3425
Wire Wire Line
	5775 3625 5875 3625
Wire Wire Line
	5775 3425 5775 3625
Wire Wire Line
	6175 3625 6475 3625
Connection ~ 6475 3625
Wire Wire Line
	6475 3625 6475 3725
Text Notes 4950 2450 0    50   ~ 0
Boot Mode Selection
Text Notes 5825 2975 0    50   ~ 0
User Reset
$Comp
L Device:C C?
U 1 1 5FFD3073
P 925 1900
AR Path="/5F45F2B5/5FFD3073" Ref="C?"  Part="1" 
AR Path="/5FFD3073" Ref="C3"  Part="1" 
AR Path="/5FFB786E/5FFD3073" Ref="C?"  Part="1" 
AR Path="/5FFB9C6F/5FFD3073" Ref="C?"  Part="1" 
F 0 "C3" H 1075 1850 50  0000 L CNN
F 1 "10uF 25V 10%" H 1075 1925 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 963 1750 50  0001 C CNN
F 3 "~" H 925 1900 50  0001 C CNN
F 4 "Samsung Electro-Mechanics" H 925 1900 50  0001 C CNN "MF 1"
F 5 "CL31A106MAHNNNE" H 925 1900 50  0001 C CNN "MF 1 MPN"
	1    925  1900
	-1   0    0    1   
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5FFD3079
P 2875 825
AR Path="/5F45F2B5/5FFD3079" Ref="#PWR?"  Part="1" 
AR Path="/5FFD3079" Ref="#PWR010"  Part="1" 
AR Path="/5FFB786E/5FFD3079" Ref="#PWR?"  Part="1" 
AR Path="/5FFB9C6F/5FFD3079" Ref="#PWR?"  Part="1" 
F 0 "#PWR010" H 2875 675 50  0001 C CNN
F 1 "+3.3V" H 2890 998 50  0000 C CNN
F 2 "" H 2875 825 50  0001 C CNN
F 3 "" H 2875 825 50  0001 C CNN
	1    2875 825 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2875 825  2875 925 
Text Label 4100 1050 2    50   ~ 0
IO0
Wire Wire Line
	5025 3425 5775 3425
$Comp
L Switch:SW_Push SW?
U 1 1 5FFD3085
P 5825 1525
AR Path="/5F45F2B5/5FFD3085" Ref="SW?"  Part="1" 
AR Path="/5FFD3085" Ref="SW1"  Part="1" 
AR Path="/5FFB786E/5FFD3085" Ref="SW?"  Part="1" 
AR Path="/5FFB9C6F/5FFD3085" Ref="SW?"  Part="1" 
F 0 "SW1" H 5825 1810 50  0000 C CNN
F 1 "SPST (BLUE)" H 5825 1719 50  0000 C CNN
F 2 ".DesignArchive:PTS636_SM25F_SMTR_LFS" H 5825 1725 50  0001 C CNN
F 3 "~" H 5825 1725 50  0001 C CNN
F 4 "TE Connectivity ALCOSWITCH Switches" H 5825 1525 50  0001 C CNN "MF 1"
F 5 "1825027-8" H 5825 1525 50  0001 C CNN "MF 1 MPN"
	1    5825 1525
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5FFD308D
P 5825 1775
AR Path="/5F45F2B5/5FFD308D" Ref="C?"  Part="1" 
AR Path="/5FFD308D" Ref="C7"  Part="1" 
AR Path="/5FFB786E/5FFD308D" Ref="C?"  Part="1" 
AR Path="/5FFB9C6F/5FFD308D" Ref="C?"  Part="1" 
F 0 "C7" V 5975 1775 50  0000 C CNN
F 1 "1nF 50V" V 6075 1775 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 5863 1625 50  0001 C CNN
F 3 "~" H 5825 1775 50  0001 C CNN
F 4 "Walsin Technology Corporation" H 5825 1775 50  0001 C CNN "MF 1"
F 5 "1206B102K500CT" H 5825 1775 50  0001 C CNN "MF 1 MPN"
	1    5825 1775
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5FFD3095
P 5225 1225
AR Path="/5F45F2B5/5FFD3095" Ref="R?"  Part="1" 
AR Path="/5FFD3095" Ref="R4"  Part="1" 
AR Path="/5FFB786E/5FFD3095" Ref="R?"  Part="1" 
AR Path="/5FFB9C6F/5FFD3095" Ref="R?"  Part="1" 
F 0 "R4" H 5050 1300 50  0000 L CNN
F 1 "10k 5% 0.25W" H 4600 1225 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 5155 1225 50  0001 C CNN
F 3 "~" H 5225 1225 50  0001 C CNN
F 4 "Yageo" H 5225 1225 50  0001 C CNN "MF 1"
F 5 "RC1206JR-0710KL" H 5225 1225 50  0001 C CNN "MF 1 MPN"
	1    5225 1225
	1    0    0    -1  
$EndComp
Wire Wire Line
	5225 1375 5225 1525
Wire Wire Line
	5225 1525 5625 1525
Wire Wire Line
	5225 1525 5225 1775
Wire Wire Line
	5225 1775 5675 1775
Connection ~ 5225 1525
Wire Wire Line
	6025 1525 6425 1525
Wire Wire Line
	6425 1525 6425 1775
Wire Wire Line
	5975 1775 6425 1775
Connection ~ 6425 1775
Wire Wire Line
	6425 1775 6425 1975
Wire Wire Line
	5225 925  5225 1075
$Comp
L power:+3.3V #PWR?
U 1 1 5FFD30A6
P 5225 925
AR Path="/5F45F2B5/5FFD30A6" Ref="#PWR?"  Part="1" 
AR Path="/5FFD30A6" Ref="#PWR017"  Part="1" 
AR Path="/5FFB786E/5FFD30A6" Ref="#PWR?"  Part="1" 
AR Path="/5FFB9C6F/5FFD30A6" Ref="#PWR?"  Part="1" 
F 0 "#PWR017" H 5225 775 50  0001 C CNN
F 1 "+3.3V" H 5240 1098 50  0000 C CNN
F 2 "" H 5225 925 50  0001 C CNN
F 3 "" H 5225 925 50  0001 C CNN
	1    5225 925 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FFD30AC
P 6425 1975
AR Path="/5F45F2B5/5FFD30AC" Ref="#PWR?"  Part="1" 
AR Path="/5FFD30AC" Ref="#PWR018"  Part="1" 
AR Path="/5FFB786E/5FFD30AC" Ref="#PWR?"  Part="1" 
AR Path="/5FFB9C6F/5FFD30AC" Ref="#PWR?"  Part="1" 
F 0 "#PWR018" H 6425 1725 50  0001 C CNN
F 1 "GND" H 6430 1802 50  0000 C CNN
F 2 "" H 6425 1975 50  0001 C CNN
F 3 "" H 6425 1975 50  0001 C CNN
	1    6425 1975
	1    0    0    -1  
$EndComp
$Comp
L RF_Module:ESP32-WROOM-32 U?
U 1 1 5FFD30D5
P 3100 2250
AR Path="/5F45F2B5/5FFD30D5" Ref="U?"  Part="1" 
AR Path="/5FFD30D5" Ref="U3"  Part="1" 
AR Path="/5FFB786E/5FFD30D5" Ref="U?"  Part="1" 
AR Path="/5FFB9C6F/5FFD30D5" Ref="U?"  Part="1" 
F 0 "U3" H 3300 3750 50  0000 C CNN
F 1 "ESP32-WROOM-32" H 3600 3650 50  0000 C CNN
F 2 "RF_Module:ESP32-WROOM-32" H 3100 750 50  0001 C CNN
F 3 "https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf" H 2800 2300 50  0001 C CNN
F 4 "Espressif" H 3100 2250 50  0001 C CNN "MF 1"
F 5 "ESP32-WROOM-32D" H 3100 2250 50  0001 C CNN "MF 1 MPN"
	1    3100 2250
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x04_Odd_Even J?
U 1 1 5FFD30DC
P 1275 3125
AR Path="/5FFB9C6F/5FFD30DC" Ref="J?"  Part="1" 
AR Path="/5FFD30DC" Ref="J1"  Part="1" 
F 0 "J1" H 1325 3442 50  0000 C CNN
F 1 "0.100\" 2x4 Header" H 1325 3351 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x04_P2.54mm_Vertical" H 1275 3125 50  0001 C CNN
F 3 "~" H 1275 3125 50  0001 C CNN
	1    1275 3125
	1    0    0    -1  
$EndComp
Wire Wire Line
	1575 3025 1925 3025
Wire Wire Line
	1575 3125 1925 3125
Wire Wire Line
	1575 3225 1925 3225
Wire Wire Line
	1575 3325 1925 3325
Text Label 1925 3025 2    50   ~ 0
EN
Text Label 1925 3125 2    50   ~ 0
IO0
Text Label 1925 3325 2    50   ~ 0
USB_RX
Text Label 1925 3225 2    50   ~ 0
USB_TX
Wire Wire Line
	1075 3025 975  3025
Wire Wire Line
	975  3025 975  3125
Wire Wire Line
	975  3225 1075 3225
Wire Wire Line
	1075 3125 975  3125
Connection ~ 975  3125
Wire Wire Line
	975  3125 975  3225
Wire Wire Line
	1075 3325 1075 3575
Text Label 1425 3575 2    50   ~ 0
VREG_IN
Wire Wire Line
	1075 3575 1425 3575
$Comp
L power:GND #PWR?
U 1 1 5FFD30F3
P 875 3325
AR Path="/5F45F2B5/5FFD30F3" Ref="#PWR?"  Part="1" 
AR Path="/5FFD30F3" Ref="#PWR04"  Part="1" 
AR Path="/5FFB786E/5FFD30F3" Ref="#PWR?"  Part="1" 
AR Path="/5FFB9C6F/5FFD30F3" Ref="#PWR?"  Part="1" 
F 0 "#PWR04" H 875 3075 50  0001 C CNN
F 1 "GND" H 880 3152 50  0000 C CNN
F 2 "" H 875 3325 50  0001 C CNN
F 3 "" H 875 3325 50  0001 C CNN
	1    875  3325
	-1   0    0    -1  
$EndComp
Wire Wire Line
	875  3325 975  3325
Wire Wire Line
	975  3325 975  3225
Connection ~ 975  3225
Wire Notes Line
	4925 2450 5775 2450
Text Notes 825  1300 0    50   ~ 0
U3 Bypass Capacitors
Wire Notes Line
	800  1300 1700 1300
Text GLabel 5075 1525 0    50   Input ~ 0
UserSwitch
Wire Wire Line
	5075 1525 5225 1525
Text Notes 5525 575  0    50   ~ 0
User Pair Switch
Wire Notes Line
	5475 575  6225 575 
Text Notes 925  2675 0    50   ~ 0
Programming Header
Wire Notes Line
	1775 2675 875  2675
Text Notes 875  4025 0    50   ~ 0
EN
Text Notes 825  4225 0    50   ~ 0
IO 0
Text Notes 825  3775 0    50   ~ 0
To enter programming mode
Wire Notes Line style solid
	1025 3925 1125 3925
Wire Notes Line style solid
	1125 3925 1125 4025
Wire Notes Line style solid
	1125 4025 1325 4025
Wire Notes Line style solid
	1325 4025 1325 3925
Wire Notes Line style solid
	1175 4125 1175 4225
Wire Notes Line style solid
	1175 4225 1525 4225
Wire Notes Line style solid
	1525 4225 1525 4125
Wire Notes Line style solid
	1525 4125 1775 4125
Wire Notes Line style solid
	1025 4125 1175 4125
Wire Notes Line style solid
	1325 3925 1775 3925
Wire Notes Line
	5800 2975 6275 2975
$Comp
L Device:R R?
U 1 1 5FFD3122
P 9050 3450
AR Path="/5F45F2B5/5FFD3122" Ref="R?"  Part="1" 
AR Path="/5FFD3122" Ref="R6"  Part="1" 
AR Path="/5FFB786E/5FFD3122" Ref="R?"  Part="1" 
AR Path="/5FFB9C6F/5FFD3122" Ref="R?"  Part="1" 
F 0 "R6" H 9120 3496 50  0000 L CNN
F 1 "10k 5% 0.25W" H 9120 3405 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 8980 3450 50  0001 C CNN
F 3 "~" H 9050 3450 50  0001 C CNN
F 4 "Yageo" H 9050 3450 50  0001 C CNN "MF 1"
F 5 "RC1206JR-0710KL" H 9050 3450 50  0001 C CNN "MF 1 MPN"
	1    9050 3450
	1    0    0    -1  
$EndComp
Text GLabel 8925 3200 0    50   Input ~ 0
U0TX_Active
Wire Wire Line
	8925 3200 9050 3200
Wire Wire Line
	9050 3200 9050 3300
$Comp
L power:GND #PWR?
U 1 1 5FFD312E
P 9050 3725
AR Path="/5F45F2B5/5FFD312E" Ref="#PWR?"  Part="1" 
AR Path="/5FFD312E" Ref="#PWR022"  Part="1" 
AR Path="/5FFB786E/5FFD312E" Ref="#PWR?"  Part="1" 
AR Path="/5FFB9C6F/5FFD312E" Ref="#PWR?"  Part="1" 
F 0 "#PWR022" H 9050 3475 50  0001 C CNN
F 1 "GND" H 9055 3552 50  0000 C CNN
F 2 "" H 9050 3725 50  0001 C CNN
F 3 "" H 9050 3725 50  0001 C CNN
	1    9050 3725
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 3600 9050 3725
Text Notes 9375 3125 0    50   ~ 0
MTDO Pin has internal pull up\nU0TX Active : 0\nU0TX Disabled: 1
Text Label 5325 1525 0    50   ~ 0
IO0
Text Label 10550 4850 2    50   ~ 0
ESP32_SPI_MISO
Wire Wire Line
	9850 4850 10550 4850
Text Label 11050 5050 2    50   ~ 0
ESP32_SPI_TEMPSENSOR_1_CS
Wire Wire Line
	9850 5050 11050 5050
Text GLabel 8050 1200 0    50   Input ~ 0
StatusLED
Text GLabel 9750 1200 0    50   Input ~ 0
HotLED
Text GLabel 12450 1050 0    50   Input ~ 0
HotLED
$Comp
L power:+5V #PWR09
U 1 1 5FFE63B0
P 2150 5250
F 0 "#PWR09" H 2150 5100 50  0001 C CNN
F 1 "+5V" H 2165 5423 50  0000 C CNN
F 2 "" H 2150 5250 50  0001 C CNN
F 3 "" H 2150 5250 50  0001 C CNN
	1    2150 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 5250 2150 5350
Wire Wire Line
	2150 5350 2300 5350
$Comp
L power:GND #PWR?
U 1 1 6000D8ED
P -1650 1200
AR Path="/5FFED6C8/6000D8ED" Ref="#PWR?"  Part="1" 
AR Path="/6000D8ED" Ref="#PWR02"  Part="1" 
F 0 "#PWR02" H -1650 950 50  0001 C CNN
F 1 "GND" H -1645 1027 50  0000 C CNN
F 2 "" H -1650 1200 50  0001 C CNN
F 3 "" H -1650 1200 50  0001 C CNN
	1    -1650 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 6000D8F6
P -2500 850
AR Path="/5FFED6C8/6000D8F6" Ref="C?"  Part="1" 
AR Path="/6000D8F6" Ref="C1"  Part="1" 
F 0 "C1" H -2385 896 50  0000 L CNN
F 1 "220nF 50V" H -2385 805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H -2385 759 50  0001 L CNN
F 3 "~" H -2500 850 50  0001 C CNN
F 4 "YAGEO" H -2500 850 50  0001 C CNN "MF 1"
F 5 "CC1206KKX7R9BB224" H -2500 850 50  0001 C CNN "MF 1 MPN"
F 6 "C107186" H -2500 850 50  0001 C CNN "MF 1 Ordering Code"
	1    -2500 850 
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:AZ1117-3.3 U?
U 1 1 6000D8FF
P -1650 600
AR Path="/5FFED6C8/6000D8FF" Ref="U?"  Part="1" 
AR Path="/6000D8FF" Ref="U1"  Part="1" 
F 0 "U1" H -1650 842 50  0000 C CNN
F 1 "NCP1117ST33T3G" H -1650 751 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H -1650 850 50  0001 C CIN
F 3 "https://www.diodes.com/assets/Datasheets/AZ1117.pdf" H -1650 600 50  0001 C CNN
F 4 "ON Semiconductor" H -1650 600 50  0001 C CNN "MF 1"
F 5 "NCP1117ST33T3G" H -1650 600 50  0001 C CNN "MF 1 MPN"
F 6 "C26537" H -1650 600 50  0001 C CNN "MF 1 Ordering Code"
	1    -1650 600 
	1    0    0    -1  
$EndComp
Wire Wire Line
	-2500 600  -2500 700 
Wire Wire Line
	-2500 1000 -2500 1100
Wire Wire Line
	-1650 1100 -1650 1200
Wire Wire Line
	-1650 900  -1650 1100
Connection ~ -1650 1100
$Comp
L Device:C C?
U 1 1 6000D916
P -750 850
AR Path="/5FFED6C8/6000D916" Ref="C?"  Part="1" 
AR Path="/6000D916" Ref="C2"  Part="1" 
F 0 "C2" H -635 896 50  0000 L CNN
F 1 "220nF 50V" H -635 805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder" H -712 700 50  0001 C CNN
F 3 "~" H -750 850 50  0001 C CNN
F 4 "YAGEO" H -750 850 50  0001 C CNN "MF 1"
F 5 "CC1206KKX7R9BB224" H -750 850 50  0001 C CNN "MF 1 MPN"
F 6 "C107186" H -750 850 50  0001 C CNN "MF 1 Ordering Code"
	1    -750 850 
	1    0    0    -1  
$EndComp
Connection ~ -750 600 
Wire Wire Line
	-750 600  -750 700 
Wire Wire Line
	-1650 1100 -750 1100
Wire Wire Line
	-750 1000 -750 1100
Wire Wire Line
	-2500 600  -1950 600 
Wire Wire Line
	-2500 1100 -1650 1100
Wire Wire Line
	-1350 600  -750 600 
$Comp
L power:+3.3V #PWR?
U 1 1 60029658
P -750 450
AR Path="/5FFED6C8/60029658" Ref="#PWR?"  Part="1" 
AR Path="/60029658" Ref="#PWR03"  Part="1" 
F 0 "#PWR03" H -750 300 50  0001 C CNN
F 1 "+3.3V" H -735 623 50  0000 C CNN
F 2 "" H -750 450 50  0001 C CNN
F 3 "" H -750 450 50  0001 C CNN
	1    -750 450 
	1    0    0    -1  
$EndComp
Wire Wire Line
	-750 450  -750 600 
$Comp
L power:+5V #PWR01
U 1 1 6003D7E0
P -2500 400
F 0 "#PWR01" H -2500 250 50  0001 C CNN
F 1 "+5V" H -2485 573 50  0000 C CNN
F 2 "" H -2500 400 50  0001 C CNN
F 3 "" H -2500 400 50  0001 C CNN
	1    -2500 400 
	1    0    0    -1  
$EndComp
Wire Wire Line
	-2500 400  -2500 600 
Connection ~ -2500 600 
$Comp
L Device:C C?
U 1 1 5FFCD6F5
P 3100 4800
AR Path="/5F45F2B5/5FFCD6F5" Ref="C?"  Part="1" 
AR Path="/5FFCD6F5" Ref="C6"  Part="1" 
AR Path="/5FFB786E/5FFCD6F5" Ref="C?"  Part="1" 
AR Path="/5FFB9C6F/5FFCD6F5" Ref="C?"  Part="1" 
F 0 "C6" V 3250 4800 50  0000 C CNN
F 1 "1nF 50V" V 3350 4800 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 3138 4650 50  0001 C CNN
F 3 "~" H 3100 4800 50  0001 C CNN
F 4 "Walsin Technology Corporation" H 3100 4800 50  0001 C CNN "MF 1"
F 5 "1206B102K500CT" H 3100 4800 50  0001 C CNN "MF 1 MPN"
	1    3100 4800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2800 4950 2800 4800
Wire Wire Line
	2800 4800 2950 4800
Wire Wire Line
	3250 4800 3450 4800
$Comp
L power:GND #PWR014
U 1 1 5FFD7B4A
P 3450 5400
F 0 "#PWR014" H 3450 5150 50  0001 C CNN
F 1 "GND" H 3455 5227 50  0000 C CNN
F 2 "" H 3450 5400 50  0001 C CNN
F 3 "" H 3450 5400 50  0001 C CNN
	1    3450 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 4800 3450 5350
$Comp
L Device:C C?
U 1 1 5FFEE130
P 1850 5350
AR Path="/5F45F2B5/5FFEE130" Ref="C?"  Part="1" 
AR Path="/5FFEE130" Ref="C5"  Part="1" 
AR Path="/5FFB786E/5FFEE130" Ref="C?"  Part="1" 
AR Path="/5FFB9C6F/5FFEE130" Ref="C?"  Part="1" 
F 0 "C5" V 2000 5300 50  0000 L CNN
F 1 "1uF 50V" V 1700 5050 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 1888 5200 50  0001 C CNN
F 3 "~" H 1850 5350 50  0001 C CNN
F 4 "Samsung Electro-Mechanics" H 1850 5350 50  0001 C CNN "MF 1"
F 5 "CL31B105KBHNFNE" H 1850 5350 50  0001 C CNN "MF 1 MPN"
	1    1850 5350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2000 5350 2150 5350
Connection ~ 2150 5350
$Comp
L power:GND #PWR07
U 1 1 5FFF46D5
P 1550 5400
F 0 "#PWR07" H 1550 5150 50  0001 C CNN
F 1 "GND" H 1555 5227 50  0000 C CNN
F 2 "" H 1550 5400 50  0001 C CNN
F 3 "" H 1550 5400 50  0001 C CNN
	1    1550 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 5400 1550 5350
Wire Wire Line
	1550 5350 1700 5350
Wire Wire Line
	3100 5350 3450 5350
Connection ~ 3450 5350
Wire Wire Line
	3450 5350 3450 5400
Wire Wire Line
	2500 5750 2500 6150
Wire Wire Line
	2900 5750 2900 6150
$Comp
L Device:R R?
U 1 1 60016A6F
P 5000 4650
AR Path="/5F45F2B5/60016A6F" Ref="R?"  Part="1" 
AR Path="/60016A6F" Ref="R1"  Part="1" 
AR Path="/5FFB786E/60016A6F" Ref="R?"  Part="1" 
AR Path="/5FFB9C6F/60016A6F" Ref="R?"  Part="1" 
F 0 "R1" H 4750 4750 50  0000 L CNN
F 1 "1.37k 0.25W 1%" H 4250 4650 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 4930 4650 50  0001 C CNN
F 3 "~" H 5000 4650 50  0001 C CNN
F 4 "Yageo" H 5000 4650 50  0001 C CNN "MF 1"
F 5 "RC1206FR-071K37L" H 5000 4650 50  0001 C CNN "MF 1 MPN"
F 6 "C488576" H 5000 4650 50  0001 C CNN "MF 1 Ordering Code"
	1    5000 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 6001CA54
P 5000 5150
AR Path="/5F45F2B5/6001CA54" Ref="R?"  Part="1" 
AR Path="/6001CA54" Ref="R2"  Part="1" 
AR Path="/5FFB786E/6001CA54" Ref="R?"  Part="1" 
AR Path="/5FFB9C6F/6001CA54" Ref="R?"  Part="1" 
F 0 "R2" H 4825 5225 50  0000 L CNN
F 1 "2.67k 0.25W 1%" H 4300 5150 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 4930 5150 50  0001 C CNN
F 3 "~" H 5000 5150 50  0001 C CNN
F 4 "Yageo" H 5000 5150 50  0001 C CNN "MF 1"
F 5 "AC1206FR-072K67L" H 5000 5150 50  0001 C CNN "MF 1 MPN"
F 6 "C229517" H 5000 5150 50  0001 C CNN "MF 1 Ordering Code"
	1    5000 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 4800 5000 4900
Wire Wire Line
	5000 4900 5250 4900
Connection ~ 5000 4900
Wire Wire Line
	5000 4900 5000 5000
Wire Wire Line
	5000 5300 5000 5500
$Comp
L power:GND #PWR015
U 1 1 6002C01B
P 5000 5500
F 0 "#PWR015" H 5000 5250 50  0001 C CNN
F 1 "GND" H 5005 5327 50  0000 C CNN
F 2 "" H 5000 5500 50  0001 C CNN
F 3 "" H 5000 5500 50  0001 C CNN
	1    5000 5500
	1    0    0    -1  
$EndComp
Text GLabel 5250 4900 2    50   Input ~ 0
V_Current_adj
Text GLabel 2900 4400 2    50   Input ~ 0
V_Current
Wire Wire Line
	2900 4400 2700 4400
Wire Wire Line
	2700 4400 2700 4950
Text GLabel 4800 4250 0    50   Input ~ 0
V_Current
Wire Wire Line
	4800 4250 5000 4250
Wire Wire Line
	5000 4250 5000 4500
Text GLabel 12450 1200 0    50   Input ~ 0
V_Current_adj
Text GLabel 12450 1350 0    50   Input ~ 0
StatusLED
Text GLabel 12450 1500 0    50   Input ~ 0
UserSwitch
Text GLabel 4000 3350 2    50   Input ~ 0
V_Current_adj
Wire Wire Line
	3700 3350 4000 3350
$Comp
L power:GND #PWR?
U 1 1 600710C9
P 3100 3800
AR Path="/5F45F2B5/600710C9" Ref="#PWR?"  Part="1" 
AR Path="/600710C9" Ref="#PWR011"  Part="1" 
AR Path="/5FFB786E/600710C9" Ref="#PWR?"  Part="1" 
AR Path="/5FFB9C6F/600710C9" Ref="#PWR?"  Part="1" 
F 0 "#PWR011" H 3100 3550 50  0001 C CNN
F 1 "GND" H 3105 3627 50  0000 C CNN
F 2 "" H 3100 3800 50  0001 C CNN
F 3 "" H 3100 3800 50  0001 C CNN
	1    3100 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 3650 3100 3800
Wire Wire Line
	2250 1050 2500 1050
Wire Wire Line
	3700 1050 4100 1050
Wire Wire Line
	3700 1150 4100 1150
Wire Wire Line
	3700 1350 4100 1350
Wire Wire Line
	2900 6150 3950 6150
$EndSCHEMATC
