using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MaxTemp
{
    public class Temp 
    {
        public string sensorName 
        {
            get
            {
                return this.sensorName;
            }
            set
            {
                if (this.sensorName == value)
                {
                    return;
                }
                this.sensorName = value;
            }
        }
        public string time
        {
            get
            {
                return this.time;
            }
            set
            {
                if (this.time == value)
                {
                    return;
                }
                this.time = value;
            }
        }
        public string temp
        {
            get
            {
                return this.temp;
            }
            set
            {
                if (this.temp == value)
                {
                    return;
                }
                this.temp = value;
            }
        }
        public Temp(string _sensorName, string _time, string _temp) 
        {
            sensorName = _sensorName;
            time = _time;
            temp = _temp;
        }

        public Temp() { }
        
        
    }
}
