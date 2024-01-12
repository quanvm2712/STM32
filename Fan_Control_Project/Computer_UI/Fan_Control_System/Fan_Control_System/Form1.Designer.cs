
namespace Fan_Control_System
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.gbUART = new System.Windows.Forms.GroupBox();
            this.lbConnectStatus = new System.Windows.Forms.Label();
            this.btConnect = new System.Windows.Forms.Button();
            this.btDisconnect = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.cbStopBit = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.cbParity = new System.Windows.Forms.ComboBox();
            this.cbBitLength = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.cbBaudrate = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.cbCOMPort = new System.Windows.Forms.ComboBox();
            this.label6 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.button2 = new System.Windows.Forms.Button();
            this.tbDutyCycle = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.tbTemperature = new System.Windows.Forms.TextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.tbFanRPM = new System.Windows.Forms.TextBox();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.gbUART.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // serialPort1
            // 
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_DataReceived);
            // 
            // gbUART
            // 
            this.gbUART.BackColor = System.Drawing.SystemColors.ControlLight;
            this.gbUART.Controls.Add(this.lbConnectStatus);
            this.gbUART.Controls.Add(this.btConnect);
            this.gbUART.Controls.Add(this.btDisconnect);
            this.gbUART.Controls.Add(this.label5);
            this.gbUART.Controls.Add(this.cbStopBit);
            this.gbUART.Controls.Add(this.label4);
            this.gbUART.Controls.Add(this.label3);
            this.gbUART.Controls.Add(this.cbParity);
            this.gbUART.Controls.Add(this.cbBitLength);
            this.gbUART.Controls.Add(this.label2);
            this.gbUART.Controls.Add(this.cbBaudrate);
            this.gbUART.Controls.Add(this.label1);
            this.gbUART.Controls.Add(this.cbCOMPort);
            this.gbUART.ForeColor = System.Drawing.Color.Black;
            this.gbUART.Location = new System.Drawing.Point(20, 22);
            this.gbUART.Name = "gbUART";
            this.gbUART.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.gbUART.Size = new System.Drawing.Size(255, 378);
            this.gbUART.TabIndex = 0;
            this.gbUART.TabStop = false;
            this.gbUART.Text = "UART Configuration";
            this.gbUART.Enter += new System.EventHandler(this.gbUART_Enter);
            // 
            // lbConnectStatus
            // 
            this.lbConnectStatus.BackColor = System.Drawing.Color.Silver;
            this.lbConnectStatus.Location = new System.Drawing.Point(17, 317);
            this.lbConnectStatus.Name = "lbConnectStatus";
            this.lbConnectStatus.Size = new System.Drawing.Size(232, 40);
            this.lbConnectStatus.TabIndex = 10;
            this.lbConnectStatus.Text = "Closed";
            this.lbConnectStatus.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // btConnect
            // 
            this.btConnect.BackColor = System.Drawing.Color.PaleGreen;
            this.btConnect.Location = new System.Drawing.Point(127, 256);
            this.btConnect.Name = "btConnect";
            this.btConnect.Size = new System.Drawing.Size(122, 45);
            this.btConnect.TabIndex = 9;
            this.btConnect.Text = "Open";
            this.btConnect.UseVisualStyleBackColor = false;
            this.btConnect.Click += new System.EventHandler(this.btConnect_Click);
            // 
            // btDisconnect
            // 
            this.btDisconnect.BackColor = System.Drawing.Color.Silver;
            this.btDisconnect.Location = new System.Drawing.Point(17, 256);
            this.btDisconnect.Name = "btDisconnect";
            this.btDisconnect.Size = new System.Drawing.Size(104, 45);
            this.btDisconnect.TabIndex = 8;
            this.btDisconnect.Text = "Close";
            this.btDisconnect.UseVisualStyleBackColor = false;
            this.btDisconnect.Click += new System.EventHandler(this.btDisconnect_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(14, 207);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(61, 16);
            this.label5.TabIndex = 7;
            this.label5.Text = "Stop bit";
            // 
            // cbStopBit
            // 
            this.cbStopBit.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cbStopBit.FormattingEnabled = true;
            this.cbStopBit.Location = new System.Drawing.Point(109, 204);
            this.cbStopBit.Name = "cbStopBit";
            this.cbStopBit.Size = new System.Drawing.Size(140, 24);
            this.cbStopBit.TabIndex = 6;
            this.cbStopBit.Text = "One";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(14, 167);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(48, 16);
            this.label4.TabIndex = 5;
            this.label4.Text = "Parity";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(14, 125);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(72, 16);
            this.label3.TabIndex = 5;
            this.label3.Text = "Bit length";
            // 
            // cbParity
            // 
            this.cbParity.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cbParity.FormattingEnabled = true;
            this.cbParity.Location = new System.Drawing.Point(109, 164);
            this.cbParity.Name = "cbParity";
            this.cbParity.Size = new System.Drawing.Size(140, 24);
            this.cbParity.TabIndex = 4;
            this.cbParity.Text = "None";
            // 
            // cbBitLength
            // 
            this.cbBitLength.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cbBitLength.FormattingEnabled = true;
            this.cbBitLength.Location = new System.Drawing.Point(109, 122);
            this.cbBitLength.Name = "cbBitLength";
            this.cbBitLength.Size = new System.Drawing.Size(140, 24);
            this.cbBitLength.TabIndex = 4;
            this.cbBitLength.Text = "8";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(14, 82);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(71, 16);
            this.label2.TabIndex = 3;
            this.label2.Text = "Baudrate";
            // 
            // cbBaudrate
            // 
            this.cbBaudrate.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cbBaudrate.FormattingEnabled = true;
            this.cbBaudrate.Location = new System.Drawing.Point(109, 79);
            this.cbBaudrate.Name = "cbBaudrate";
            this.cbBaudrate.Size = new System.Drawing.Size(140, 24);
            this.cbBaudrate.TabIndex = 2;
            this.cbBaudrate.Text = "9600";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(14, 41);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(73, 16);
            this.label1.TabIndex = 1;
            this.label1.Text = "COM Port";
            // 
            // cbCOMPort
            // 
            this.cbCOMPort.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cbCOMPort.FormattingEnabled = true;
            this.cbCOMPort.Location = new System.Drawing.Point(109, 38);
            this.cbCOMPort.Name = "cbCOMPort";
            this.cbCOMPort.Size = new System.Drawing.Size(140, 24);
            this.cbCOMPort.TabIndex = 0;
            this.cbCOMPort.SelectedIndexChanged += new System.EventHandler(this.cbCOMPort_SelectedIndexChanged);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(0, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(51, 16);
            this.label6.TabIndex = 1;
            this.label6.Text = "label6";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.button2);
            this.groupBox1.Controls.Add(this.tbDutyCycle);
            this.groupBox1.Controls.Add(this.label7);
            this.groupBox1.Location = new System.Drawing.Point(301, 292);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(250, 107);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "PWM Control";
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.CornflowerBlue;
            this.button2.Location = new System.Drawing.Point(107, 72);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(126, 29);
            this.button2.TabIndex = 2;
            this.button2.Text = "Send";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // tbDutyCycle
            // 
            this.tbDutyCycle.Location = new System.Drawing.Point(107, 30);
            this.tbDutyCycle.Name = "tbDutyCycle";
            this.tbDutyCycle.Size = new System.Drawing.Size(126, 22);
            this.tbDutyCycle.TabIndex = 1;
            this.tbDutyCycle.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Enter);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(8, 33);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(93, 16);
            this.label7.TabIndex = 0;
            this.label7.Text = "Duty cycle (%)";
            this.label7.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.label7.Click += new System.EventHandler(this.label7_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.groupBox4);
            this.groupBox2.Controls.Add(this.groupBox3);
            this.groupBox2.Location = new System.Drawing.Point(301, 22);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(592, 249);
            this.groupBox2.TabIndex = 4;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "System monitor";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.label9);
            this.groupBox4.Controls.Add(this.tbTemperature);
            this.groupBox4.Location = new System.Drawing.Point(310, 38);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(259, 184);
            this.groupBox4.TabIndex = 1;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Temperature monitor";
            // 
            // tbTemperature
            // 
            this.tbTemperature.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tbTemperature.Location = new System.Drawing.Point(80, 126);
            this.tbTemperature.Multiline = true;
            this.tbTemperature.Name = "tbTemperature";
            this.tbTemperature.ReadOnly = true;
            this.tbTemperature.Size = new System.Drawing.Size(99, 31);
            this.tbTemperature.TabIndex = 2;
            this.tbTemperature.Text = "0";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.label8);
            this.groupBox3.Controls.Add(this.tbFanRPM);
            this.groupBox3.Location = new System.Drawing.Point(15, 38);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(260, 184);
            this.groupBox3.TabIndex = 0;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Fan monitor";
            // 
            // tbFanRPM
            // 
            this.tbFanRPM.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tbFanRPM.Location = new System.Drawing.Point(81, 126);
            this.tbFanRPM.Multiline = true;
            this.tbFanRPM.Name = "tbFanRPM";
            this.tbFanRPM.ReadOnly = true;
            this.tbFanRPM.Size = new System.Drawing.Size(99, 31);
            this.tbFanRPM.TabIndex = 1;
            this.tbFanRPM.Text = "0";
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 1000;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(194, 135);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(41, 16);
            this.label8.TabIndex = 2;
            this.label8.Text = "RPM";
            this.label8.Click += new System.EventHandler(this.label8_Click);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(185, 135);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(24, 16);
            this.label9.TabIndex = 3;
            this.label9.Text = "*C";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(991, 435);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.gbUART);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.gbUART.ResumeLayout(false);
            this.gbUART.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.GroupBox gbUART;
        private System.Windows.Forms.Label lbConnectStatus;
        private System.Windows.Forms.Button btConnect;
        private System.Windows.Forms.Button btDisconnect;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox cbStopBit;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox cbParity;
        private System.Windows.Forms.ComboBox cbBitLength;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox cbBaudrate;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox cbCOMPort;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox tbDutyCycle;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.TextBox tbFanRPM;
        private System.Windows.Forms.TextBox tbTemperature;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
    }
}

