package com.suyyyus.utils;

import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.util.Date;

public class TimeUtil {
    /**
     * 获取时间把时间格式化为字符串类型
     */
    public String createTime(){
        //2024-04-07 20:31:45
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        String s = simpleDateFormat.format(new Date());
        return s;
    }
}
