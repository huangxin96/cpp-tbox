#ifndef TBOX_UTIL_STRING_H_20220103
#define TBOX_UTIL_STRING_H_20220103

#include <stdint.h>
#include <string>
#include <vector>

namespace tbox {
namespace util {
namespace string {

/**
 * \brief       分隔字符串
 * \param src_str   被分隔的字串
 * \param sep       分隔字串
 * \param str_vec   分隔后输出的字串数组
 * \return      分隔得到了子字串个数
 */
size_t Split(const std::string &src_str, const std::string sep, std::vector<std::string> &str_vec);

/**
 * \brief       以空格分隔字串
 */
size_t SplitBySpace(const std::string &src_str, std::vector<std::string> &str_vec);

/**
 * \brief       消除字串左边的空格符
 * \param orig_str  原始字串
 * \return      处理后的字串
 */
std::string StripLeft(const std::string &orig_str);

/**
 * \brief       消除字串右边的空格符
 * \param orig_str  原始字串
 * \return      处理后的字串
 */
std::string StripRight(const std::string &orig_str);

/**
 * \brief       消除字串两右的空格符
 * \param orig_str  原始字串
 * \return      处理后的字串
 */
std::string Strip(const std::string &orig_str);

/**
 * \brief       将原始数据转换成HEX字串
 *
 * \param data_ptr  原始数据内存地址
 * \param data_len  原始数据长度
 * \param uppercase HEX中a~f
 * \param delimiter 分隔字串
 *
 * \return      转换后的HEX字串
 */
std::string RawDataToHexStr(const void *data_ptr, uint16_t data_len,
                            bool uppercase = false,
                            const std::string &delimiter = std::string(" "));

//! 字符不是A-Z a-z 0-9
class NotAZaz09Exception : public std::exception {
    virtual const char* what() const throw() override {
        return "character not a-z A-Z 0-9";
    }
};

//! 字串个体超过2个
class MoreThan2CharException : public std::exception {
    virtual const char* what() const throw() override {
        return "more than 2 characters";
    }
};

/**
 * \brief       将HEX字串转换成原始数据
 *
 * \param hex_str   HEX字串
 * \param out_ptr   输出到数据地址
 * \param out_len   输出到数据长度
 *
 * \return      实际转换的数据长度
 */
size_t HexStrToRawData(const std::string &hex_str, void *out_ptr, uint16_t out_len);

/**
 * \brief       将HEX字串转换成原始数据
 *
 * \param hex_str   HEX字串
 * \param out       输出到数据vector
 * \param delimiter 分隔符，常用的分隔符有 " \t", ": ", ", "
 *
 * \return      实际转换的数据长度
 */
size_t HexStrToRawData(const std::string &hex_str, std::vector<uint8_t> &out, const std::string &delimiter = "");

/**
 * \brief       替换字串中指定个数的字串
 *
 * \param target_str    被修改的字串
 * \param pattern_str   匹配字串
 * \param replace_str   用于替换的字串
 * \param count         替换次数
 */
void Replace(std::string &target_str, const std::string &pattern_str, const std::string &replace_str,
             std::string::size_type start = 0, std::string::size_type count = 0);

}
}
}

#endif //TBOX_UTIL_STRING_H_20220103
