
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
            this.cbCOMPort = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.cbBaudrate = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.cbBitLength = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.cbParity = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.cbStopBit = new System.Windows.Forms.ComboBox();
            this.btDisconnect = new System.Windows.Forms.Button();
            this.btConnect = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.lbConnectStatus = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label7 = new System.Windows.Forms.Label();
            this.tbDutyCycle = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.gbUART.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
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
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(14, 41);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(73, 16);
            this.label1.TabIndex = 1;
            this.label1.Text = "COM Port";
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
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(14, 125);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(72, 16);
            this.label3.TabIndex = 5;
            this.label3.Text = "Bit length";
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
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(14, 167);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(48, 16);
            this.label4.TabIndex = 5;
            this.label4.Text = "Parity";
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
            // btDisconnect
            // 
            this.btDisconnect.BackColor = System.Drawing.Color.Silver;
            this.btDisconnect.Location = new System.Drawing.Point(17, 256);
            this.btDisconnect.Name = "btDisconnect";
            this.btDisconnect.Size = new System.Drawing.Size(104, 45);
            this.btDisconnect.TabIndex = 8;
            this.btDisconnect.Text = "Disconnect";
            this.btDisconnect.UseVisualStyleBackColor = false;
            this.btDisconnect.Click += new System.EventHandler(this.btDisconnect_Click);
            // 
            // btConnect
            // 
            this.btConnect.BackColor = System.Drawing.Color.PaleGreen;
            this.btConnect.Location = new System.Drawing.Point(127, 256);
            this.btConnect.Name = "btConnect";
            this.btConnect.Size = new System.Drawing.Size(122, 45);
            this.btConnect.TabIndex = 9;
            this.btConnect.Text = "Connect";
            this.btConnect.UseVisualStyleBackColor = false;
            this.btConnect.Click += new System.EventHandler(this.btConnect_Click);
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
            // lbConnectStatus
            // 
            this.lbConnectStatus.BackColor = System.Drawing.Color.Silver;
            this.lbConnectStatus.Location = new System.Drawing.Point(17, 317);
            this.lbConnectStatus.Name = "lbConnectStatus";
            this.lbConnectStatus.Size = new System.Drawing.Size(232, 40);
            this.lbConnectStatus.TabIndex = 10;
            this.lbConnectStatus.Text = "Disconnected";
            this.lbConnectStatus.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.button2);
            this.groupBox1.Controls.Add(this.tbDutyCycle);
            this.groupBox1.Controls.Add(this.label7);
            this.groupBox1.Location = new System.Drawing.Point(301, 292);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(296, 107);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "PWM Control";
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
            // tbDutyCycle
            // 
            this.tbDutyCycle.Location = new System.Drawing.Point(107, 30);
            this.tbDutyCycle.Name = "tbDutyCycle";
            this.tbDutyCycle.Size = new System.Drawing.Size(183, 22);
            this.tbDutyCycle.TabIndex = 1;
            this.tbDutyCycle.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Enter);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(0, 0);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 3;
            this.button1.Text = "button1";
            this.button1.UseVisualStyleBackColor = true;
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.Color.CornflowerBlue;
            this.button2.Location = new System.Drawing.Point(145, 68);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(144, 29);
            this.button2.TabIndex = 2;
            this.button2.Text = "Send";
            this.button2.UseVisualStyleBackColor = false;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1060, 433);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.gbUART);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.gbUART.ResumeLayout(false);
            this.gbUART.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
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
        private System.Windows.Forms.Button button1;
    }
}

