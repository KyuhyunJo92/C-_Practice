using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MaxTemp
{
    class TempManager
    {
        List<Temp> temps = new List<Temp>();

        public void Add(string sensor, string time, string temp)
        {
            sensor = sensor.Replace(",", " ");
            time = time.Replace(",", " ");
            temp = temp.Replace(",", " ");
            temps.Add(new Temp(sensor, time, temp));
        }

    }
}
