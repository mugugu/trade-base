#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/* ==================== 运行环境 ==================== */
#define RUN_TYPE_TEST 1
#define RUN_TYPE_SIMULAT 2
#define RUN_TYPE_PRODUCTION 3

/* ==================== 常量声明 ==================== */

#define HOUR_PER_DAY 24
#define SEC_PER_MIN 60
#define SEC_PER_HOUR (60 * SEC_PER_MIN)
#define SEC_PER_DAY (24 * SEC_PER_HOUR)

/* ==================== 常用数组长度声明 ==================== */
#define MONTH_DAYS 32

/* 日期字符串长度,YYYYMMDD  */
#define LEN_DAY 9

/* 时间字符串长度，HH:MM:SS  */
#define LEN_TIME 9

/* 日期时间字符串长度，YYYYMMDD HH:MM:SS  */
#define LEN_DAY_TIME 18

/* 文件路径字符串长度  */
#define LEN_PATH 256

/* ip地址字符串长度  */
#define LEN_HOST 16

/* 名称字符串的长度  */
#define LEN_FULLNAME 64

/* 应用程序的路径字符串长度  */
#define LEN_APP_PATH 32

/* 数据库连接数据库名称长度*/
#define LEN_DB_DATABASE 16

/* 数据库连接用户名长度*/
#define LEN_DB_USER 16

/* 数据库连接密码长度*/
#define LEN_DB_PASSWORD 32

/* sql语句字符串长度 */
#define LEN_DB_SQL 4049

/* 动态库名称的长度 */
#define LEN_LIB_NAME 32

/* 数据库表名字符串长度 */
#define LEN_TABLE_NAME 32

/* URL字符串长度 */
#define LEN_URL 256

/* 错误消息数组默认长度 */
#define LEN_ERR_MSG 512

/* =================== 常用类型声明 ==================== */
// 函数返回值
typedef uint8_t bool_t;

/* 函数返回值0表示执行成功，大于0都表示错误 */
typedef int8_t retval_t;

/* 定义有符号char的别名  */
typedef char str_t;

/* 声明有符号不可变长度char的别名  */
typedef const char cstr_t;

/* 声明有时间戳常量  */
typedef const time_t ctime_t;

/* 数据库ip地址 */
typedef str_t __db_host[LEN_HOST];

/* 需连接数据库的名称 */
typedef str_t __db_database[LEN_DB_DATABASE];

/* 数据库登录用户名 */
typedef str_t __db_user[LEN_DB_USER];

/* 数据库登录密码 */
typedef str_t __db_password[LEN_DB_PASSWORD];

/* 日期字符串长度,YYYYMMDD  */
typedef str_t __day[LEN_DAY];

/* 时间字符串长度，HH:MM:SS  */
typedef str_t __time[LEN_TIME];

/* 日期时间字符串长度，YYYYMMDD HH:MM:SS  */
typedef str_t __day_time[LEN_DAY_TIME];

/* ==================== 颜色控制码 ==================== */
/* 描述：重置所有属性 */
#define COLOR_RESET "\033[0m"

/* 无颜色 */
#define COLOR_NONE ""

/* 红色（错误） */
#define COLOR_RED "\033[31m"

/* 绿色（信息） */
#define COLOR_GREEN "\033[32m"

/* 黄色（警告） */
#define COLOR_YELLOW "\033[33m"

/* 蓝色（调试） */
#define COLOR_BLUE "\033[34m"

/* =================== 常用错误 ==================== */

/**
 * 双精度类型的无效数据，格式化输出到文件中内容为1.79769e+308
 * 用于判断tick结构体中双精度类型的变量是否与该值相同，如果相同变量值为0
 */
#define INVALID_DOUBLE *(__d64*)("\xff\xff\xff\xff\xff\xff\xef\x7f")

#define ERR_PTR_NULL "%s为空指针"
#define ERR_FILE_OPEN "%s文件打开失败：%s"
#define ERR_MUTEX_INIT "初始化互斥锁失败：%s"
#define ERR_MUTEX_DESTROY "销毁互斥锁失败：%s"
#define ERR_COND_INIT "初始化条件变量失败：%s"
#define ERR_COND_DESTROY "销毁条件变量失败：%s"
#define ERR_MALLOC "申请内存空间失败：%s"
#define ERR_REALLOC "扩容内存空间失败：%s"
#define ERR_BROADCAST "唤醒失败，无效的条件变量：%s"
#define ERR_THREAD_SYNC "线程同步失败：%s"
#define ERR_PARAMS "参数值不合法：%s"
#define ERR_LEN_OVERFLOW "字符串长度超过最大值：%d"
#define ERR_INVALID_VAL_INT "无效的变量值：%d"
#define ERR_INVALID_VAL_TIME "无效的time_t变量值：%ld"
#define ERR_INVALID_VAL_STR "无效的变量值：%s"
#define ERR_CONVERT_LOCALTIME_R "使用localtime_r转换为本地时间出错"

/* =================== 常用数值声明 ==================== */

// 一般用于函数返回值，表示函数执行成功
#define SUCCESS 0

// 一般用于函数返回值，表示函数执行失败
#define ERROR -1

#define TRUE 1

#define FALSE 0

/* 判断返回值是否为0，代表成功 */
#define IS_SUCCESS(ret) ((ret) == SUCCESS)

/* 判断返回值是否不为0，代表不成功 */
#define NOT_SUCCESS(ret) ((ret) != SUCCESS)

/* 判断返回值是否为-1，代表错误 */
#define IS_ERROR(ret) ((ret) == ERROR)

/* 判断返回值是否为NULL */
#define IS_NULL(ret) ((ret) == NULL)

/* 判断返回值是否不为NULL */
#define NOT_NULL(ret) ((ret) != NULL)

#define IS_TRUE(ret) ((ret) == 1)
#define IS_FALSE(ret) ((ret) == 0)

/* ==================== 常用字符串 ==================== */

#define STR_APP_PATH "/usr/local/trade"

/* ==================== 功能通用宏 ==================== */
/* 用于计算成员运行时间的宏 */
#define TIC                     \
   struct timeval time1, time2; \
   gettimeofday(&time1, nullptr);

#define TOC                                                                                              \
   gettimeofday(&time2, nullptr);                                                                        \
   __d64 elapsed_time = (time2.tv_sec - time1.tv_sec) * 1000. + (time2.tv_usec - time1.tv_usec) / 1000.; \
   fprintf(stdout, "Elapsed time: %lf(ms)\n", elapsed_time);

// 条件成立时，记录错误并返回指定值
#define CHECK_RET(cond, handler, ret_val, err_msg, ...) \
   do {                                                 \
      if (cond) {                                       \
         handler(err_msg, ##__VA_ARGS__);               \
         return ret_val;                                \
      }                                                 \
   } while (0)

// 指针为 NULL → 返回 NULL
#define IF_NUL_RET_NUL(handler, ptr, err_msg, ...) \
   CHECK_RET((ptr) == NULL, handler, NULL, err_msg, ##__VA_ARGS__)

// 指针为 NULL → 返回 ERROR
#define IF_NUL_RET_ERR(handler, ptr, err_msg, ...) \
   CHECK_RET((ptr) == NULL, handler, ERROR, err_msg, ##__VA_ARGS__)

// 返回值为 ERROR → 返回 NULL
#define IF_ERR_RET_NUL(handler, ret, err_msg, ...) \
   CHECK_RET((ret) == ERROR, handler, NULL, err_msg, ##__VA_ARGS__)

// 返回值为 ERROR → 返回 ERROR
#define IF_ERR_RET_ERR(handler, ret, err_msg, ...) \
   CHECK_RET((ret) == ERROR, handler, ERROR, err_msg, ##__VA_ARGS__)

// 值 == 0 → 返回 ERROR
#define IF_0_RET_ERR(handler, val, err_msg, ...) \
   CHECK_RET((val) == 0, handler, ERROR, err_msg, ##__VA_ARGS__)

// 值 <= 0 → 返回 ERROR
#define IF_LE0_RET_ERR(handler, val, err_msg, ...) \
   CHECK_RET((val) <= 0, handler, ERROR, err_msg, ##__VA_ARGS__)

// 值 <= 0 → 返回 NULL
#define IF_LE0_RET_NUL(handler, val, err_msg, ...) \
   CHECK_RET((val) <= 0, handler, NULL, err_msg, ##__VA_ARGS__)

#define CTP_CALLBACK_VALIDATE(params, err_set_func)                                   \
   do {                                                                               \
      IF_NUL_RET_ERR(err_set_func, params, ERR_PTR_NULL, "params");                   \
      IF_NUL_RET_ERR(err_set_func, params->context, ERR_PTR_NULL, "params->context"); \
   } while (0)

#define CTP_EVENT_VALIDATE(params, err_set_func)                                            \
   do {                                                                                     \
      IF_NUL_RET_ERR(err_set_func, params, ERR_PTR_NULL, "params");                         \
      IF_NUL_RET_ERR(err_set_func, params->event_data, ERR_PTR_NULL, "params->event_data"); \
      if (IS_ERROR(params->is_success)) {                                                   \
         LOG_ERROR(MODULE_NAME_MARKET, params->error_msg);                                  \
         return ERROR;                                                                      \
      }                                                                                     \
   } while (0)

/**
 * 描述：安全日志输出宏（完整格式，支持变参）
 * 场景：任何模块在核心路径、初始化阶段或不能使用正常日志系统的场景
 * 作用：直接输出到stderr，格式与正常日志完全一致
 * 参数：
 *    module_name - 模块名称
 *    file - 源文件名（使用__FILE__）
 *    line - 行号（使用__LINE__）
 *    func - 函数名（使用__FUNCTION__）
 *    color - 颜色控制码
 *    ... - 变参
 * 注意：此宏使用write系统调用，不依赖任何库初始化，线程安全
 */
#define LOG(module_name, file, line, func, color, ...)                             \
   do {                                                                            \
      /* 获取当前时间 */                                                     \
      time_t _now = time(NULL);                                                    \
      str_t _time_buf[20] = { 0 };                                                 \
                                                                                   \
      if (_now != (time_t)-1) {                                                    \
         struct tm* _tm_info = localtime(&_now);                                   \
         if (_tm_info) {                                                           \
            strftime(_time_buf, sizeof(_time_buf), "%Y-%m-%d %H:%M:%S", _tm_info); \
         }                                                                         \
      }                                                                            \
                                                                                   \
      if (_time_buf[0] == '\0') {                                                  \
         cstr_t* _default_time = "1970-01-01 00:00:00";                            \
         strncpy(_time_buf, _default_time, sizeof(_time_buf) - 1);                 \
      }                                                                            \
                                                                                   \
      /* 简化文件路径 */                                                     \
      cstr_t* _file_only = file;                                                   \
      cstr_t* _last_slash = strrchr(file, '/');                                    \
      if (_last_slash) {                                                           \
         _file_only = _last_slash + 1;                                             \
      }                                                                            \
                                                                                   \
      /* 构建最终消息 - 直接使用变参 */                                \
      str_t _final_msg[1024] = { 0 };                                              \
      snprintf(_final_msg, sizeof(_final_msg), __VA_ARGS__);                       \
                                                                                   \
      /* 构建完整日志消息 */                                               \
      str_t _log_buf[2048] = { 0 };                                                \
      int32_t _len = snprintf(_log_buf, sizeof(_log_buf),                          \
          "%s[%s][%s][%s:%d] %s" COLOR_RESET "\n",                                 \
          color, _time_buf, module_name, _file_only, line, _final_msg);            \
                                                                                   \
      if (_len > 0 && _len < (int32_t)sizeof(_log_buf)) {                          \
         write(2, _log_buf, _len);                                                 \
         fflush(stdout);                                                           \
      }                                                                            \
   } while (0)

/* 错误日志 红色 */
#define LOG_ERROR(module_name, ...) \
   LOG(module_name, __FILE__, __LINE__, __FUNCTION__, COLOR_RED, __VA_ARGS__)

/* 警告日志 黄色 */
#define LOG_WARN(module_name, ...) \
   LOG(module_name, __FILE__, __LINE__, __FUNCTION__, COLOR_YELLOW, __VA_ARGS__)

/* 信息日志 绿色 */
#define LOG_INFO(module_name, ...) \
   LOG(module_name, __FILE__, __LINE__, __FUNCTION__, COLOR_GREEN, __VA_ARGS__)

/* 调试日志 白色 */
#define LOG_DEBUG(module_name, ...) \
   LOG(module_name, __FILE__, __LINE__, __FUNCTION__, COLOR_NONE, __VA_ARGS__)

/* 提醒日志 蓝色 */
#define LOG_REMIND(module_name, ...) \
   LOG(module_name, __FILE__, __LINE__, __FUNCTION__, COLOR_BLUE, __VA_ARGS__)

#endif
