    string getAlarmTime() {
        ostringstream oss;
        oss << setfill('0') << setw(2) << alarm_hour << ":" 
            << setw(2) << alarm_minute << ":" << setw(2) << alarm_second;
        return oss.str();
    }