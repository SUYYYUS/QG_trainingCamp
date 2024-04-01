package com.suyyyus.web.servlet;

import com.alibaba.fastjson.JSON;
import com.suyyyus.Dao.UserDao;
import com.suyyyus.Dao.impl.UserDaoImpl;
import com.suyyyus.Service.UserService;
import com.suyyyus.Service.impl.UserServiceImpl;
import com.suyyyus.pojo.PageBean;
import com.suyyyus.pojo.User;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.List;

/**
 * User类的Servlet
 */
@WebServlet("/User/*")
public class UserServlet extends BaseServlet{

    private UserDao userDao = new UserDaoImpl();

    private UserService userService = new UserServiceImpl();
    /**
     * 查询所有信息
     * @param req
     * @param resp
     * @throws ServletException
     * @throws IOException
     */
    public void selectAll(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //1.调用查询

        List<User> userList = userService.queryAll();

        //2.转为JSON
        String jsonString = JSON.toJSONString(userList);

        //3.写数据
        resp.setContentType("text/json;charset=utf-8");
        resp.getWriter().write(jsonString);
        //System.out.println("User selectAll----------");
    }

    /**
     * 添加数据
     * @param req
     * @param resp
     * @throws ServletException
     * @throws IOException
     */
    public void add(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException{
        //post方法获取数据
        BufferedReader reader = req.getReader();
        String s = reader.readLine();

        User user = JSON.parseObject(s, User.class);

        userService.insertUser(user);

        resp.getWriter().write("success");
        //System.out.println("User add---------------");
    }

    /**
     * 单个删除
     * @param req
     * @param resp
     * @throws ServletException
     * @throws IOException
     */
    public void deleteById(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException{
        //post方法
        BufferedReader reader = req.getReader();

        String id = reader.readLine();

        userService.deleteUser(Integer.parseInt(id));

        resp.getWriter().write("success");
    }

    /**
     * 批量删除
     * @param req
     * @param resp
     * @throws ServletException
     * @throws IOException
     */
    public void deleteByIds(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException{
        //post方法
        BufferedReader reader = req.getReader();

        String params = reader.readLine();

        int[] ids = JSON.parseObject(params, int[].class);
        userService.deleteUsers(ids);

        resp.getWriter().write("success");
    }


    /**
     * 分页查询
     * @param req
     * @param resp
     * @throws ServletException
     * @throws IOException
     */
    public void selectByPage(HttpServletRequest req, HttpServletResponse resp) throws Exception {
        //1.调用查询
        String _currentPage = req.getParameter("currentPage");
        String _pageSize = req.getParameter("pageSize");

        int currentPage = Integer.parseInt(_currentPage);
        int pageSize = Integer.parseInt(_pageSize);



        PageBean<User> pageBean = userService.selectByPage(currentPage, pageSize);


        //2.转为JSON
        String jsonString = JSON.toJSONString(pageBean);
        //3.写数据

        resp.setContentType("text/json;charset=utf-8");
        resp.getWriter().write(jsonString);
        //System.out.println("User selectAll----------");
    }


    public void updateUser(HttpServletRequest req, HttpServletResponse resp) throws Exception{
        //post方法获取数据
        BufferedReader reader = req.getReader();
        String s = reader.readLine();

        User user = JSON.parseObject(s, User.class);

        userService.updateinfo(user);

        resp.getWriter().write("success");
    }


    public void queryById(HttpServletRequest req, HttpServletResponse resp) throws Exception {
        //1.调用查询
        //String _id = req.getParameter("id");

        BufferedReader reader = req.getReader();
        String _id = reader.readLine();
        int id = Integer.parseInt(_id);

        //PageBean<User> pageBean = userService.selectByPage(currentPage, pageSize);

        List<User> list = userService.queryById(id);

        //2.转为JSON
        String jsonString = JSON.toJSONString(list);
        //3.写数据

        resp.setContentType("text/json;charset=utf-8");
        resp.getWriter().write(jsonString);
        //System.out.println("User selectAll----------");
    }


}
