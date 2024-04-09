package com.suyyyus;

import com.suyyyus.Dao.UserDao;
import com.suyyyus.Dao.impl.UserDaoImpl;
import com.suyyyus.utils.CardidUtil;
import com.suyyyus.utils.TimeUtil;

public class test {
    public static void main(String[] args) throws Exception {
        CardidUtil cardidUtil = new CardidUtil();
        String id = cardidUtil.idNumber();
        System.out.println(id);

        TimeUtil timeUtil = new TimeUtil();
        System.out.println(timeUtil.createTime());

        UserDao userDao = new UserDaoImpl();
        boolean tom = userDao.checkUsername("tom");
        System.out.println(tom);
    }
}
