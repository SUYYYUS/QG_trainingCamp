package com.suyyyus.web.servlet;

import com.alibaba.fastjson.JSON;
import com.suyyyus.Dao.UserDao;
import com.suyyyus.Dao.impl.UserDaoImpl;
import com.suyyyus.pojo.PageBean;
import com.suyyyus.pojo.User;
import com.suyyyus.service.UserService;
import com.suyyyus.service.impl.UserServiceImpl;
import com.suyyyus.utils.CRUDUtilsUser;
import com.suyyyus.utils.MD5Util;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.BufferedReader;
import java.io.IOException;

@WebServlet("/User/*")
public class UserServlet extends BaseServlet{

    private UserDao userDao = new UserDaoImpl();

    private UserService userService = new UserServiceImpl();

    /**
     * 用户登录
     * @param req
     * @param resp
     * @throws Exception
     */
    public void userLogin(HttpServletRequest req, HttpServletResponse resp) throws Exception {

        BufferedReader reader = req.getReader();
        String s = reader.readLine();
        // 获取session对象，存储user
        HttpSession session = req.getSession();

        User user = JSON.parseObject(s,User.class);
        if(user.getUsername().isEmpty() || user.getPassword().isEmpty()){
            resp.getWriter().write("null");
            return;
        }else {
            //设置编码格式
            resp.setContentType("text/html;charset=utf-8");
            //判断管理员名
            boolean b = userService.userLogin(user.getUsername(),user.getPassword());
            //boolean b = adminService.checkByAdminname(adminName);
            //判断密码
            //boolean b1 = adminService.checkByPassword(admin.getPassword());
            //boolean b1 = adminService.checkByPassword(password);
            //都正确才能成功登录
            if(b){

                User user1 = userService.queryByUsername(user.getUsername());
                session.setAttribute("user", user1);

                resp.getWriter().write("success");

                System.out.println("success");
            }else {
                resp.getWriter().write("failed");
                System.out.println("failed");
            }
            resp.setStatus(HttpServletResponse.SC_OK);
            System.out.println("Response status code: " + resp.getStatus());
        }
    }


    /**
     * 添加数据
     * @param req
     * @param resp
     * @throws ServletException
     * @throws IOException
     */
    public void add(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //post方法获取数据
        BufferedReader reader = req.getReader();
        String s = reader.readLine();

        User user = JSON.parseObject(s, User.class);

        userService.insertUser(user);

        resp.getWriter().write("success");
        //System.out.println("User add---------------");
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

    /**
     * 用于注册
     * @param req
     * @param resp
     * @throws Exception
     */
    public void usersignup(HttpServletRequest req, HttpServletResponse resp) throws Exception {
        //post方法获取数据
        BufferedReader reader = req.getReader();
        String s = reader.readLine(); //???? s = null ????
        System.out.println(1);
        User user = JSON.parseObject(s, User.class);
        System.out.println(2);
        System.out.println(user);
        boolean b = userService.checkUsername(user.getUsername());
        System.out.println(3);
        if(!b){
            userService.insertUser(user);
            System.out.println(4);
            resp.getWriter().write("success");
            System.out.println(5);
        }
        //boolean b = userService.checkUsername(user.getUsername());


//        if(!b){
//            resp.getWriter().write("success");
//        }
        else if(b){
            System.out.println(6);
            resp.getWriter().write("failed");
        }
        //System.out.println("User add---------------");
    }


    /**
     * 确认密码
     * @param req
     * @param resp
     * @throws Exception
     */
    public void confirmBycardid(HttpServletRequest req, HttpServletResponse resp) throws Exception{
        //post方法获取数据
        BufferedReader reader = req.getReader();
        String s = reader.readLine();

        User b = userService.confirmByCardid(s);
        // 获取session对象，存储user
        HttpSession session = req.getSession();

        if(b != null){
            //重置密码
            userService.resetPassword(s);

            session.setAttribute("user",b);

            resp.getWriter().write("success");
        }else if (b == null){
            resp.getWriter().write("failed");
        }

    }

    /**
     * 用户登录成功后把个人信息展示出来
     * @param req
     * @param resp
     * @throws ServletException
     * @throws IOException
     */
    public void getSelfInformation(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException{
        // 从seession中拿出登录成功的用户信息
        HttpSession session = req.getSession();
        Object user = session.getAttribute("user");
//        System.out.println(user);
        //  JSON数据化
        String jsonString = JSON.toJSONString(user);
//        System.out.println(jsonString);
        // 写数据
        resp.setContentType("text/json;charset=utf-8");
        resp.getWriter().write(jsonString);
    }

}
