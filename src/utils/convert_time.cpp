bool is_minute(int seconds)
{
    return seconds > 60 ;
}

bool is_hour(int seconds)
{
    return seconds > 3600 ;
}

int seconds_to_minute(int seconds)
{
    return seconds / 60 ;
}

int seconds_to_hour(int seconds)
{
    return seconds / 3600 ;
}