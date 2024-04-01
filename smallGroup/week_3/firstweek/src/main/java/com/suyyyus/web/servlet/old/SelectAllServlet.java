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
import java.io.IOException;
import java.util.List;

/**
 * 查询所有用户信息
 */
@WebServlet("/selectAllServlet")
public class SelectAllServlet extends HttpServlet {

    private UserDao userDao = new UserDaoImpl();

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
       //1.调用查询

        List<User> userList = userDao.queryAll();

        //2.转为JSON
        String jsonString = JSON.toJSONString(userList);

        //3.写数据
        resp.setContentType("text/json;charset=utf-8");
        resp.getWriter().write(jsonString);

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doGet(req, resp);
    }
}
