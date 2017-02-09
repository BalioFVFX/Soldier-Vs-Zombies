# Soldier-Vs-Zombies
C++/SDL Game
  using System;
4 using System.Runtime.InteropServices;
5 using System.Windows.Forms;
6
7 namespace Yours.Truly
8 {
9 // *************************************************************************
10 /// <summary>
11 /// A form class to demnstrate the brightness adjustment for computer
12 /// monitors.
13 /// </summary>
14 /// <remarks>
15 /// <para>
16 /// It uses the Interop <see cref="SetDeviceGammaRamp"/> call to set the
17 /// Gamma component to adjust the screen contrast.
18 /// </para>
19 /// <para>
20 /// The <see cref="SetDeviceGammaRamp"/> function sets the gamma ramp on
21 /// direct color display boards having drivers that support downloadable
22 /// gamma ramps in hardware.
23 /// </para>
24 /// <para>
25 /// Direct color display modes do not use color lookup tables and are
26 /// usually 16, 24, or 32 bit. Not all direct color video boards support
27 /// loadable gamma ramps. SetDeviceGammaRamp succeeds only for devices with
28 /// drivers that support downloadable gamma ramps in hardware.
29 /// </para>
30 /// </remarks>
31 public class SetBrightness : Form
32 {
33 // *********************************************************************
34 /// <summary>
35 /// A structure of gamma corrections.
36 /// </summary>
37 [StructLayout(LayoutKind.Sequential, CharSet=CharSet.Ansi)]
38 private struct RAMP
39 {
40 [ MarshalAs(UnmanagedType.ByValArray, SizeConst=256)]
41 public UInt16[] Red;
42 [ MarshalAs(UnmanagedType.ByValArray, SizeConst=256)]
43 public UInt16[] Green;
44 [ MarshalAs(UnmanagedType.ByValArray, SizeConst=256)]
45 public UInt16[] Blue;
46 }
47
48 [DllImport("gdi32.dll")]
49 private static extern bool SetDeviceGammaRamp(IntPtr hDC, ref RAMP lpRamp);
50
51 [DllImport("user32.dll")]
52 static extern IntPtr GetDC(IntPtr hWnd);
53
54 /// <summary> Required designer variable.</summary>
55 private System.ComponentModel.IContainer components = null;
56 private TrackBar m_trackBar;
57
58 private static RAMP s_ramp = new RAMP();
59
60 // *********************************************************************
61 /// <summary>
62 /// Initializes a new instance of <see cref="SetBrightness"/> class.
63 /// </summary>
64 public SetBrightness ()
65 {
66 InitializeComponent();
67 }
68
69 // *********************************************************************
70 /// <summary>
71 /// Clean up any resources being used.
72 /// </summary>
73 /// <param name="disposing">true if managed resources should be
74 /// disposed; otherwise, false.</param>
75 protected override void Dispose (bool disposing)
76 {
77 if (disposing && (components != null))
78 {
79 components.Dispose();
80 }
81 base.Dispose(disposing);
82 }
83
84 // *********************************************************************
85 /// <summary>
86 /// Handles the <see cref="TrackBar.ValueChanged"/> event for the TrackBar
87 /// control. The value of the track bar control sets the Gamma value for
88 /// the device.
89 /// </summary>
90 /// <param name="sender">The object that initiated the event.</param>
91 /// <param name="e">An <see cref="EventArgs"/> object containing event
92 /// data</param>
93 private void HandleValueChanged (object sender, EventArgs e)
94 {
95 SetGamma(m_trackBar.Value);
96 }
97
98 // *********************************************************************
99 /// <summary>
100 /// Main entry point for the application.
101 /// </summary>
102 /// <param name="args">An array of optional arguments.</param>
103 static void Main (string[] args)
104 {
105 SetBrightness mainForm = new SetBrightness();
106 Application.Run(mainForm);
107 }
108
109 // *********************************************************************
110 /// <summary>
111 /// Sets the Gamma corection at the specified <paramref name="gamma"/>
112 /// value.
113 /// </summary>
114 /// <param name="gamma">New Gamma value to be set.</param>
115 private static void SetGamma(int gamma)
116 {
117 s_ramp.Red = new ushort[256];
118 s_ramp.Green = new ushort[256];
119 s_ramp.Blue = new ushort[256];
120
121 for( int i=1; i<256; i++ )
122 {
123 // gamma is a value between 3 and 44
124 s_ramp.Red[i] = s_ramp.Green[i] = s_ramp.Blue[i] =
125 (ushort)(Math.Min(65535,
126 Math.Max(0, Math.Pow((i+1) / 256.0, gamma*0.1) * 65535 + 0.5)));
127 }
128 // Now set the value.
129 SetDeviceGammaRamp(GetDC(IntPtr.Zero), ref s_ramp);
130 }
131
132 #region Windows Form Designer generated code
133
134 /// <summary>
135 /// Required method for Designer support - do not modify
136 /// the contents of this method with the code editor.
137 /// </summary>
138 private void InitializeComponent ()
139 {
140 this.m_trackBar = new System.Windows.Forms.TrackBar();
141 ((System.ComponentModel.ISupportInitialize)(this.m_trackBar)).BeginInit();
142 this.SuspendLayout();
143 //
144 // m_trackBar
145 //
146 this.m_trackBar.Dock = System.Windows.Forms.DockStyle.Fill;
147 this.m_trackBar.Location = new System.Drawing.Point(0,0);
148 this.m_trackBar.Maximum = 44;
149 this.m_trackBar.Minimum = 3;
150 this.m_trackBar.Name = "m_trackBar";
151 this.m_trackBar.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
152 this.m_trackBar.RightToLeftLayout = true;
153 this.m_trackBar.Size = new System.Drawing.Size(277,42);
154 this.m_trackBar.TabIndex = 0;
155 this.m_trackBar.Value = 18;
156 this.m_trackBar.ValueChanged += new System.EventHandler(this.HandleValueChanged);
157 //
158 // SetBrightness
159 //
160 this.AutoScaleDimensions = new System.Drawing.SizeF(6F,13F);
161 this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
162 this.ClientSize = new System.Drawing.Size(277,42);
163 this.Controls.Add(this.m_trackBar);
164 this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
165 this.MaximizeBox = false;
166 this.MinimizeBox = false;
167 this.Name = "SetBrightness";
168 this.Opacity = 0.8;
169 this.ShowIcon = false;
170 this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
171 this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
172 this.Text = "SetBrightness";
173 this.TopMost = true;
174 ((System.ComponentModel.ISupportInitialize)(this.m_trackBar)).EndInit();
175 this.ResumeLayout(false);
176 this.PerformLayout();
177
178 }
179
180 #endregion
181
182 } // end class SetBrightness
183 } // end namespace Yours.Truly