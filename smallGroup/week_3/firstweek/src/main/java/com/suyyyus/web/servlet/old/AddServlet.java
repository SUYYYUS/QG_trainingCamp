package com.suyyyus.web.servlet.old;

import com.alibaba.fastjson.JSON;
import com.suyyyus.Dao.UserDao;
import com.suyyyus.Dao.impl.UserDaoImpl;
import com.suyyyus.pojo.User;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;

/**
 * 添加用户数据
 */
@WebServlet("/addServlet")
public class AddServlet extends HttpServlet {

    private UserDao userDao = new UserDaoImpl();

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doPost(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        BufferedReader reader = req.getReader();
        String s = reader.readLine();

        User user = JSON.parseObject(s, User.class);

        userDao.insertUser(user);

        resp.getWriter().write("success");
    }
}
