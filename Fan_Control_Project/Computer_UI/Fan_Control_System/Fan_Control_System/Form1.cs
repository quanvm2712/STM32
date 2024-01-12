using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.Timers;

namespace Fan_Control_System
{
    public partial class Form1 : Form
    {
        System.Timers.Timer time;

        public Form1()
        {
            InitializeComponent();
            time = new System.Timers.Timer();
            time.Interval = 1000;
            time.Enabled = true;
            time.Start();

        }

        private void cbCOMPort_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //UART Parameter initiallization
            string[] ports = SerialPort.GetPortNames();
            cbCOMPort.Items.AddRange(ports);

            string[] baudrate = { "4800", "9600", "14400", "19200", "38400", "57600", "115200"};
            cbBaudrate.Items.AddRange(baudrate);

            string[] dataBits = {"8", "9"};
            cbBitLength.Items.AddRange(dataBits);

            string[] parity = { "None","Odd", "Even" };
            cbParity.Items.AddRange(parity);

            string[] stopBits = { "None","One", "Two" };
            cbStopBit.Items.AddRange(stopBits);

            
            //
        }

        private void btConnect_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort1.PortName = cbCOMPort.Text;
                serialPort1.BaudRate = Int32.Parse(cbBaudrate.Text);
                serialPort1.Parity = (Parity)Enum.Parse(typeof(Parity), cbParity.Text);
                serialPort1.StopBits = (StopBits)Enum.Parse(typeof(StopBits), cbStopBit.Text);
                serialPort1.DataBits = Int32.Parse(cbBitLength.Text);

                serialPort1.Open();
            }
            catch(Exception err)
            {
                MessageBox.Show(err.Message, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

            if (serialPort1.IsOpen)
            {
                lbConnectStatus.Text = "Opened";
                lbConnectStatus.BackColor = Color.PaleGreen;
            }
            else
            {
                lbConnectStatus.Text = "Closed";
                lbConnectStatus.BackColor = Color.Silver;
            }
        }

        private void btDisconnect_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort1.Close();
            }
            catch(Exception err)
            {
                MessageBox.Show(err.Message, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

            if (!serialPort1.IsOpen)
            {
                lbConnectStatus.Text = "Closed";
                lbConnectStatus.BackColor = Color.Silver;
            }
        }

        private void gbUART_Enter(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            int number = 0;
            if (tbDutyCycle.Text != string.Empty)
            {
                try
                {
                    number = Int32.Parse(tbDutyCycle.Text);
                }
                catch(Exception err)
                {
                    MessageBox.Show(err.Message, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                
            }
            byte[] buffer = new byte[] { Convert.ToByte(number) };

            try
            {
                serialPort1.Write(buffer, 0, 1);
                tbDutyCycle.Text = String.Empty;
            }
            catch(Exception err)
            {
                MessageBox.Show(err.Message, "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void Enter(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Enter)
            {
                
                int number = Int32.Parse(tbDutyCycle.Text);
                byte[] buffer = new byte[] { Convert.ToByte(number) };

                serialPort1.Write(buffer, 0, 1);
                tbDutyCycle.Text = String.Empty;
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        string dataIn;
        int bytesToRead;
        private void timer1_Tick(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                dataIn = serialPort1.ReadExisting();
                word += dataIn;
            }

        }

        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {

            if (serialPort1.IsOpen)
            {
                bytesToRead = serialPort1.BytesToRead;
                //dataIn = serialPort1.ReadExisting();
                this.Invoke(new EventHandler(ShowData));
            }

        }
        string dataToDisplay;
        string word;
        int fanRpm, temperature;
        string[] dataSegments;

        private void ShowData(object sender, EventArgs e)
        {
           
            if(String.IsNullOrEmpty(word) == false)
            {
                dataSegments = word.Split(new string[] { "\0" }, StringSplitOptions.RemoveEmptyEntries);
                if (dataSegments.Length >= 2) {
                    string[] parts = dataSegments[1].Split(' ');
                    // Convert the string values to integers
                    if (int.TryParse(parts[0], out fanRpm) && int.TryParse(parts[1], out temperature))
                    {
                        Console.WriteLine("Fan RPM: " + fanRpm);
                        Console.WriteLine("Temperature: " + temperature);
                    }
                    else
                    {
                        Console.WriteLine("Invalid format: Unable to parse fan RPM or temperature.");
                    }
                }
                tbFanRPM.Text = fanRpm.ToString();
                tbTemperature.Text = temperature.ToString();
                word = string.Empty;
            }

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void rtbFanRPM_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
