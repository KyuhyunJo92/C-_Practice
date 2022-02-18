using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization;
using System.Windows.Media;
using System.Runtime;


namespace MaxTemp
{
    /// <summary>
    /// Interaktionslogik für MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        System.Windows.Controls.ListView myListView_sensorName_1;
        System.Windows.Controls.ListView myListView_sensorName_2;
        System.Windows.Controls.ListView myListView_sensorName_3;
        System.Windows.Controls.ListView myListView_sensorName_4;
        System.Windows.Controls.ListView myListView_sensorName_B;
        System.Windows.Controls.ListView myListView_sensorName_D;

        System.Windows.Controls.ListView myListView_time_1;
        System.Windows.Controls.ListView myListView_time_2;
        System.Windows.Controls.ListView myListView_time_3;
        System.Windows.Controls.ListView myListView_time_4;
        System.Windows.Controls.ListView myListView_time_B;
        System.Windows.Controls.ListView myListView_time_D;

        System.Windows.Controls.ListView myListView_temp_1;
        System.Windows.Controls.ListView myListView_temp_2;
        System.Windows.Controls.ListView myListView_temp_3;
        System.Windows.Controls.ListView myListView_temp_4;
        System.Windows.Controls.ListView myListView_temp_B;
        System.Windows.Controls.ListView myListView_temp_D;

        System.Windows.Controls.ListView myListView_High_temp_1;
        System.Windows.Controls.ListView myListView_High_temp_2;
        System.Windows.Controls.ListView myListView_High_temp_3;
        System.Windows.Controls.ListView myListView_High_temp_4;
        System.Windows.Controls.ListView myListView_High_temp_B;
        System.Windows.Controls.ListView myListView_High_temp_D;

        List<string> data_sensorName_1 = new List<string>();
        List<string> data_sensorName_2 = new List<string>();
        List<string> data_sensorName_3 = new List<string>();
        List<string> data_sensorName_4 = new List<string>();
        List<string> data_sensorName_B = new List<string>();
        List<string> data_sensorName_D = new List<string>();

        List<string> data_time_1 = new List<string>();
        List<string> data_time_2 = new List<string>();
        List<string> data_time_3 = new List<string>();
        List<string> data_time_4 = new List<string>();
        List<string> data_time_B = new List<string>();
        List<string> data_time_D = new List<string>();

        List<string> data_temp_1 = new List<string>();
        List<string> data_temp_2 = new List<string>();
        List<string> data_temp_3 = new List<string>();
        List<string> data_temp_4 = new List<string>();
        List<string> data_temp_B = new List<string>();
        List<string> data_temp_D = new List<string>();

        List<Double> D_data_temp_1 = new List<double>();
        List<Double> D_data_temp_2 = new List<double>();
        List<Double> D_data_temp_3 = new List<double>();
        List<Double> D_data_temp_4 = new List<double>();
        List<Double> D_data_temp_B = new List<double>();
        List<Double> D_data_temp_D = new List<double>();

        List<string> H_data_temp_1 = new List<string>();
        List<string> H_data_temp_2 = new List<string>();
        List<string> H_data_temp_3 = new List<string>();
        List<string> H_data_temp_4 = new List<string>();
        List<string> H_data_temp_B = new List<string>();
        List<string> H_data_temp_D = new List<string>();


        double MaxTemp_S1 = 0.0;
        double MaxTemp_S2 = 0.0;
        double MaxTemp_S3 = 0.0;
        double MaxTemp_S4 = 0.0;
        double MaxTemp_SB = 0.0;
        double MaxTemp_SD = 0.0;

        string[] __sensorname = { "S1", "S2", "S3", "S4", "SB", "SD" };


        public MainWindow()
        {
            InitializeComponent();

            myListView_sensorName_1 = sensorName_1;
            data_sensorName_1.Clear();

            myListView_sensorName_2 = sensorName_2;
            data_sensorName_2.Clear();

            myListView_sensorName_3 = sensorName_3;
            data_sensorName_3.Clear();

            myListView_sensorName_4 = sensorName_4;
            data_sensorName_4.Clear();

            myListView_sensorName_B = sensorName_B;
            data_sensorName_B.Clear();

            myListView_sensorName_D = sensorName_D;
            data_sensorName_D.Clear();


            myListView_time_1 = time_1;
            data_time_1.Clear();

            myListView_time_2 = time_2;
            data_time_2.Clear();

            myListView_time_3 = time_3;
            data_time_3.Clear();

            myListView_time_4 = time_4;
            data_time_4.Clear();

            myListView_time_B = time_B;
            data_time_B.Clear();

            myListView_time_D = time_D;
            data_time_D.Clear();


            myListView_temp_1 = temp_1;
            data_temp_1.Clear();

            myListView_temp_2 = temp_2;
            data_temp_2.Clear();

            myListView_temp_3 = temp_3;
            data_temp_3.Clear();

            myListView_temp_4 = temp_4;
            data_temp_4.Clear();

            myListView_temp_B = temp_B;
            data_temp_B.Clear();

            myListView_temp_D = temp_D;
            data_temp_D.Clear();


            myListView_High_temp_1 = highTemp_1;
            H_data_temp_1.Clear();

            myListView_High_temp_2 = highTemp_2;
            H_data_temp_2.Clear();

            myListView_High_temp_3 = highTemp_3;
            H_data_temp_3.Clear();

            myListView_High_temp_4 = highTemp_4;
            H_data_temp_4.Clear();

            myListView_High_temp_B = highTemp_B;
            H_data_temp_B.Clear();

            myListView_High_temp_D = highTemp_D;
            H_data_temp_D.Clear();
        }
        //Temp[] class_S1;

       
        public void btnReadFile_Click(object sender, RoutedEventArgs e)
        {
            FileStream fs = new FileStream(@"temps.csv", FileMode.Open);
            StreamReader sr = new StreamReader(fs);
            
            string sitem;
            string[] split_sitem;
            //double[] D_split_sitem= {0.0,};

            sitem = sr.ReadLine();
            while (sr.EndOfStream == false)
            {
                //Eigentlich muss zeilenNummer in einen String konvertiert werden.
                //...geht in diesem Fall auch so. -> Warum????
                sitem +=","+ sr.ReadLine()  ;
            }
            split_sitem = sitem.Split(',');


            for (int i = 0; i < split_sitem.Length; i++)
            {
                if (split_sitem[i] == "S1")
                {
                    data_sensorName_1.Add(split_sitem[i]+ "         " + split_sitem[i + 1]);
                    D_data_temp_1.Add(Double.Parse(split_sitem[i + 2])/10);

                    if (MaxTemp_S1 < (Double.Parse(split_sitem[i + 2]) / 10))
                    {
                        MaxTemp_S1 = (Double.Parse(split_sitem[i + 2]) / 10);
                        H_data_temp_1.Clear();
                        H_data_temp_1.Add(split_sitem[i+2]);
                    }

                    

                    if (MaxTemp_S1 - 70.0 > 0) { Alarm_1.Background = Brushes.Black; }
                    else if (MaxTemp_S1 - 60.0 > 0) { Alarm_1.Background = Brushes.Red; }
                    else if (MaxTemp_S1 - 50.0 > 0) { Alarm_1.Background = Brushes.Orange; }
                    else if (MaxTemp_S1 - 40.0 > 0) { Alarm_1.Background = Brushes.Yellow; }
                    else if (MaxTemp_S1 - 30.0 > 0) { Alarm_1.Background = Brushes.Green; }
                    else { Alarm_1.Background = Brushes.Blue; }

                    //data_time_1.Add(split_sitem[i + 1]);
                    //data_temp_1.Add(split_sitem[i + 2]);
                    //data_sensorName_1.Add(split_sitem[i + 1]);
                    //data_sensorName_1.Add(split_sitem[i + 2]);

                    //if (ConvertToDouble(split_sitem[i + 2]) < 20) { Alarm_1.Background = Brushes.Blue; }
                    //else if (ConvertToDouble(split_sitem[i + 2]) < 25) { Alarm_1.Background = Brushes.Green; }
                    //else if (ConvertToDouble(split_sitem[i + 2]) < 30) { Alarm_1.Background = Brushes.Yellow; }
                    //else if (ConvertToDouble(split_sitem[i + 2]) < 35) { Alarm_1.Background = Brushes.Orange; }
                    //else { Alarm_1.Background = Brushes.Red; }
                }
                else if (split_sitem[i] == "S2")
                {
                    data_sensorName_2.Add(split_sitem[i] + "         " + split_sitem[i + 1]);
                    D_data_temp_2.Add(Double.Parse(split_sitem[i + 2]) / 10);

                    if (MaxTemp_S2 < (Double.Parse(split_sitem[i + 2]) / 10))
                    {
                        MaxTemp_S2 = (Double.Parse(split_sitem[i + 2]) / 10);
                        H_data_temp_2.Clear();
                        H_data_temp_2.Add(split_sitem[i + 2]);
                    }

                    if (MaxTemp_S2 - 60.0 > 0) { Alarm_2.Background = Brushes.Black; }
                    else if (MaxTemp_S2 - 50.0 > 0) { Alarm_2.Background = Brushes.Red; }
                    else if (MaxTemp_S2 - 40.0 > 0) { Alarm_2.Background = Brushes.Orange; }
                    else if (MaxTemp_S2 - 30.0 > 0) { Alarm_2.Background = Brushes.Yellow; }
                    else if (MaxTemp_S2 - 20.0 > 0) { Alarm_2.Background = Brushes.Green; }
                    else { Alarm_2.Background = Brushes.Blue; }
                    //data_sensorName_2.Add(split_sitem[i] + "         " + split_sitem[i + 1] + "         " + split_sitem[i + 2]);

                    //if (MaxTemp_S2 < ConvertToDouble(split_sitem[i + 2]))
                    //{
                    //    MaxTemp_S2 = ConvertToDouble(split_sitem[i + 2]);
                    //}
                    //if (MaxTemp_S2 < 30.0 && MaxTemp_S2 >= 0.0) { Alarm_2.Background = Brushes.Blue; }
                    //else if (MaxTemp_S2 < 40.0 && MaxTemp_S2>= 30.0) { Alarm_2.Background = Brushes.Green; }
                    //else if (MaxTemp_S2 < 50.0 && MaxTemp_S2>= 40.0) { Alarm_2.Background = Brushes.Yellow; }
                    //else if (MaxTemp_S2 < 60.0 && MaxTemp_S2>= 50.0) { Alarm_2.Background = Brushes.Orange; }
                    //else if (MaxTemp_S2 < 70.0 && MaxTemp_S2 >= 60.0) { Alarm_2.Background = Brushes.Red; }
                    //else { Alarm_2.Background = Brushes.Black; }



                    //data_sensorName_2.Add(split_sitem[i]);
                    //data_time_2.Add(split_sitem[i + 1]);
                    //data_temp_2.Add(split_sitem[i + 2]);
                    //if (ConvertToDouble(split_sitem[i + 2]) < 20) { Alarm_2.Background = Brushes.Blue; }
                    //else if (ConvertToDouble(split_sitem[i + 2]) < 25) { Alarm_2.Background = Brushes.Green; }
                    //else if (ConvertToDouble(split_sitem[i + 2]) < 30) { Alarm_2.Background = Brushes.Yellow; }
                    //else if (ConvertToDouble(split_sitem[i + 2]) < 35) { Alarm_2.Background = Brushes.Orange; }
                    //else { Alarm_2.Background = Brushes.Red; }
                }

                else if (split_sitem[i] == "S3")
                {
                    data_sensorName_3.Add(split_sitem[i] + "         " + split_sitem[i + 1]);

                    D_data_temp_3.Add(Double.Parse(split_sitem[i + 2]) / 10);

                    if (MaxTemp_S3 < (Double.Parse(split_sitem[i + 2]) / 10))
                    {
                        MaxTemp_S3 = (Double.Parse(split_sitem[i + 2]) / 10);
                        H_data_temp_3.Clear();
                        H_data_temp_3.Add(split_sitem[i + 2]);
                    }

                    if (MaxTemp_S3 - 60.0 > 0) { Alarm_3.Background = Brushes.Black; }
                    else if (MaxTemp_S3 - 50.0 > 0) { Alarm_3.Background = Brushes.Red; }
                    else if (MaxTemp_S3 - 40.0 > 0) { Alarm_3.Background = Brushes.Orange; }
                    else if (MaxTemp_S3 - 30.0 > 0) { Alarm_3.Background = Brushes.Yellow; }
                    else if (MaxTemp_S3 - 20.0 > 0) { Alarm_3.Background = Brushes.Green; }
                    else { Alarm_3.Background = Brushes.Blue; }
                }

                else if (split_sitem[i] == "S4")
                {
                    data_sensorName_4.Add(split_sitem[i] + "         " + split_sitem[i + 1]);

                    D_data_temp_4.Add(Double.Parse(split_sitem[i + 2]) / 10);

                    if (MaxTemp_S4 < (Double.Parse(split_sitem[i + 2]) / 10))
                    {
                        MaxTemp_S4 = (Double.Parse(split_sitem[i + 2]) / 10);
                        H_data_temp_4.Clear();
                        H_data_temp_4.Add(split_sitem[i + 2]);
                    }

                    if (MaxTemp_S4 - 60.0 > 0) { Alarm_4.Background = Brushes.Black; }
                    else if (MaxTemp_S4 - 50.0 > 0) { Alarm_4.Background = Brushes.Red; }
                    else if (MaxTemp_S4 - 40.0 > 0) { Alarm_4.Background = Brushes.Orange; }
                    else if (MaxTemp_S4 - 30.0 > 0) { Alarm_4.Background = Brushes.Yellow; }
                    else if (MaxTemp_S4 - 20.0 > 0) { Alarm_4.Background = Brushes.Green; }
                    else { Alarm_4.Background = Brushes.Blue; }
                }

                else if (split_sitem[i] == "SB")
                {
                    data_sensorName_B.Add(split_sitem[i] + "         " + split_sitem[i + 1]);
                    D_data_temp_B.Add(Double.Parse(split_sitem[i + 2]) / 10);

                    if (MaxTemp_SB < (Double.Parse(split_sitem[i + 2]) / 10))
                    {
                        MaxTemp_SB = (Double.Parse(split_sitem[i + 2]) / 10);
                        H_data_temp_B.Clear();
                        H_data_temp_B.Add(split_sitem[i + 2]);
                    }

                    if (MaxTemp_SB - 60.0 > 0) { Alarm_B.Background = Brushes.Black; }
                    else if (MaxTemp_SB - 50.0 > 0) { Alarm_B.Background = Brushes.Red; }
                    else if (MaxTemp_SB - 40.0 > 0) { Alarm_B.Background = Brushes.Orange; }
                    else if (MaxTemp_SB - 30.0 > 0) { Alarm_B.Background = Brushes.Yellow; }
                    else if (MaxTemp_SB - 20.0 > 0) { Alarm_B.Background = Brushes.Green; }
                    else { Alarm_B.Background = Brushes.Blue; }
                }
                else if (split_sitem[i] == "SD")
                {
                    data_sensorName_D.Add(split_sitem[i] + "         " + split_sitem[i + 1]);
                    D_data_temp_D.Add(Double.Parse(split_sitem[i + 2]) / 10);

                    if (MaxTemp_SD < (Double.Parse(split_sitem[i + 2]) / 10))
                    {
                        MaxTemp_SD = (Double.Parse(split_sitem[i + 2]) / 10);
                        H_data_temp_D.Clear();
                        H_data_temp_D.Add(split_sitem[i + 2]);
                    }

                    if (MaxTemp_SD - 60.0 > 0) { Alarm_D.Background = Brushes.Black; }
                    else if (MaxTemp_SD - 50.0 > 0) { Alarm_D.Background = Brushes.Red; }
                    else if (MaxTemp_SD - 40.0 > 0) { Alarm_D.Background = Brushes.Orange; }
                    else if (MaxTemp_SD - 30.0 > 0) { Alarm_D.Background = Brushes.Yellow; }
                    else if (MaxTemp_SD - 20.0 > 0) { Alarm_D.Background = Brushes.Green; }
                    else { Alarm_D.Background = Brushes.Blue; }
                }
            }

            myListView_sensorName_1.ItemsSource = data_sensorName_1;
            //myListView_time_1.ItemsSource = data_time_1;
            myListView_temp_1.ItemsSource = D_data_temp_1;
            myListView_High_temp_1.ItemsSource = H_data_temp_1;

            myListView_sensorName_2.ItemsSource = data_sensorName_2;
            //myListView_time_2.ItemsSource = data_time_2;
            myListView_temp_2.ItemsSource = D_data_temp_2;
            myListView_High_temp_2.ItemsSource = H_data_temp_2;

            myListView_sensorName_3.ItemsSource = data_sensorName_3;
            //myListView_time_3.ItemsSource = data_time_3;
            myListView_temp_3.ItemsSource = D_data_temp_3;
            myListView_High_temp_3.ItemsSource = H_data_temp_3;

            myListView_sensorName_4.ItemsSource = data_sensorName_4;
            //myListView_time_4.ItemsSource = data_time_4;
            myListView_temp_4.ItemsSource = D_data_temp_4;
            myListView_High_temp_4.ItemsSource = H_data_temp_4;

            myListView_sensorName_B.ItemsSource = data_sensorName_B;
            //myListView_time_B.ItemsSource = data_time_B;
            myListView_temp_B.ItemsSource = D_data_temp_B;
            myListView_High_temp_B.ItemsSource = H_data_temp_B;

            myListView_sensorName_D.ItemsSource = data_sensorName_D;
            //myListView_time_D.ItemsSource = data_time_D;
            myListView_temp_D.ItemsSource = D_data_temp_D;
            myListView_High_temp_D.ItemsSource = H_data_temp_D;

            sr.Close();
            fs.Close();
        }
    }
}

//myListView_sensorName_1.ItemsSource = data_sensorName_1;
//            myListView_time_1.ItemsSource = data_time_1;
//            myListView_temp_1.ItemsSource = data_temp_1;

//            myListView_sensorName_2.ItemsSource = data_sensorName_2;
//            myListView_time_2.ItemsSource = data_time_2;
//            myListView_temp_2.ItemsSource = data_temp_2;

//            myListView_sensorName_3.ItemsSource = data_sensorName_3;
//            myListView_time_3.ItemsSource = data_time_3;
//            myListView_temp_3.ItemsSource = data_temp_3;

//            myListView_sensorName_4.ItemsSource = data_sensorName_4;
//            myListView_time_4.ItemsSource = data_time_4;
//            myListView_temp_4.ItemsSource = data_temp_4;

//            myListView_sensorName_B.ItemsSource = data_sensorName_B;
//            myListView_time_B.ItemsSource = data_time_B;
//            myListView_temp_B.ItemsSource = data_temp_B;

//            myListView_sensorName_D.ItemsSource = data_sensorName_D;
//            myListView_time_D.ItemsSource = data_time_D;
//            myListView_temp_D.ItemsSource = data_temp_D;

