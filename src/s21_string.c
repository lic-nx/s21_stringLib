#include "s21_string.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
// байтах строки, на которую указывает аргумент str

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *t = s21_NULL;
  unsigned char *byte = (unsigned char *)str;
  while (n > 0) {
    if (*byte == c) {
      t = byte;
      break;
    }
    byte++;
    n--;
  }
  return t;
}

// Сравнивает первые n байтов строк str1 и str2.

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *arr1;
  unsigned char *arr2;
  s21_size_t i;
  i = 0;
  arr1 = (unsigned char *)str1;
  arr2 = (unsigned char *)str2;
  while (i < n) {
    if (arr1[i] != arr2[i]) {
      return (arr1[i] - arr2[i]);
    }
    i++;
  }
  return (0);
}

// Копирует n символов из src в dest.

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *s_dest = (char *)dest;
  char *s_src = (char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    s_dest[i] = s_src[i];
  }
  return dest;
}

// Еще одна функция для копирования n символов из src в dest.

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *csrc = (char *)src;
  char *cdest = (char *)dest;
  char *tmp = (char *)malloc(n * sizeof(char));
  for (s21_size_t i = 0; i < n; i++) {
    tmp[i] = csrc[i];
  }
  for (s21_size_t i = 0; i < n; i++) {
    cdest[i] = tmp[i];
  }
  free(tmp);
  return dest;
}

// Копирует символ c (беззнаковый char) в первые n символов строки, на которую
// указывает аргумент str.

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *s_str = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    *((char *)s_str + i) = c;
  }
  return s_str;
}

// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest.

char *s21_strcat(char *dest, const char *src) {
  int i = 0;
  int leng = 0;
  while (dest[i] != '\0') {
    leng++;
    i++;
  }
  i = 0;
  while (src[i] != '\0') {
    dest[leng + i] = src[i];
    i++;
  }
  dest[leng + i] = '\0';
  return (dest);
}

// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest, длиной до n символов.

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  if (n != 0) {
    int i = 0;
    char *d = dest;
    const char *s = src;
    while (*d != '\0') {
      d++;
    }
    do {
      if ((*d = *(s + i)) == '\0') break;
      i++;
      d++;
    } while (--n);
    *d = 0;
  }
  return (dest);
}

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.

char *s21_strchr(const char *str, int c) {
  char *s = s21_NULL;
  for (s21_size_t i = 0; i <= s21_strlen(str); i++) {
    if (str[i] == c) {
      s = ((char *)str) + i;
      break;
    }
  }
  return s;
}

// Сравнивает строку, на которую указывает str1, со строкой, на которую
// указывает
//  str2.

int s21_strcmp(const char *str1, const char *str2) {
  while (*str1 && (*str1 == *str2)) {
    str1++;
    str2++;
  }
  return *str1 - *str2;
}

// Сравнивает не более первых n байтов str1 и str2.

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  if (str1 && str2 && n > 0) {
    for (s21_size_t i = 0; i < n; i++) {
      if (str1[i] == '\0' || str1[i] != str2[i]) {
        result = str1[i] - str2[i];
        break;
      }
    }
  }
  return result;
}

/// Копирует строку, на которую указывает src, в dest.

char *s21_strcpy(char *dest, const char *src) {
  int i;
  for (i = 0; src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  dest[i] = '\0';
  return dest;
}

// Копирует до n символов из строки, на которую указывает src, в dest.

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  while (i < n) {
    dest[i] = src[i];
    i++;
  }
  return dest;
}

// Вычисляет длину начального сегмента str1, который полностью состоит из
// символов, не входящих в str2.

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  if ((str1 != s21_NULL) && (str2 != s21_NULL)) {  // Валидация
    int fl = 0;
    for (; str1[len] != '\0'; len++) {
      for (int i = 0; str2[i] != '\0'; i++) {
        if (str1[len] == str2[i]) {
          fl = 1;
          break;
        }
      }
      if (fl) {
        break;
      }
    }
  }
  return len;
}

// Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает
// указатель на строку с сообщением об ошибке.

char *s21_strerror(int errnum) {
  char *ERRORS[] = ERROR;
  char *error = s21_NULL;
  static char buf[100];
  if (errnum >= 0 && errnum < N) {
    error = ERRORS[errnum];
  } else {
    if (std == 0) {
      char *undef = "Unknown error: ";
      s21_sprintf(buf, "%s%d", undef, errnum);
    } else if (std == 1) {
      char *undef = "Unknown error: ";
      s21_sprintf(buf, "%s%d", undef, errnum);
    }
  }
  return error == s21_NULL ? buf : error;
}

// Вычисляет длину строки str, не включая завершающий нулевой символ.

s21_size_t s21_strlen(const char *str) {
  int count = 0;
  if (str != s21_NULL) {
    while (*str++ != '\0') {
      count++;
    }
  }
  return (count);
}

// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.

char *s21_strpbrk(const char *str1, const char *str2) {
  int i, j, flag = 0;
  for (i = 0; str1[i] != '\0'; i++) {
    for (j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        flag = 1;
      }
      if (flag == 1) {
        break;
      }
    }
    if (flag == 1) {
      break;
    }
  }
  return flag == 1 ? ((char *)str1 + i) : 0;
}

// потом чтото дописать -------------------------------
// Выполняет поиск последнего вхождения символа
// c (беззнаковый тип) в строке, на которую указывает аргумент str.
char *s21_strrchr(const char *src, int c) {
  char *s = s21_NULL;
  int end = s21_strlen(src) + 1;
  while (0 < end--) {
    if (src[end] == c) {
      s = (char *)&src[end];
      break;
    }
  }
  return s;
}

// Вычисляет длину начального сегмента str1, который полностью состоит из
// символов str2.

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  int lenStr2 = s21_strlen(str2);
  if ((str1 != s21_NULL) && (str2 != s21_NULL)) {  // Валидация
    for (; str1[len] != '\0'; len++) {
      int f = 0;
      for (int j = 0; j < lenStr2; j++) {
        if (str1[len] != str2[j]) {
          f++;
        } else {
          break;
        }
      }
      if (f == lenStr2) {
        break;
      }
    }
  }
  return len;
}

// Находит первое вхождение всей строки needle (не включая завершающий нулевой
// символ), которая появляется в строке haystack.

char *s21_strstr(const char *str1, const char *str2) {
  char *str1_tmp = (char *)str1;
  char *str2_tmp = (char *)str2;
  char *res = s21_NULL;
  if (*str2_tmp == '\0') {
    res = str1_tmp;
  }
  for (s21_size_t i = 0; i < s21_strlen(str1_tmp); i++) {
    if (str1_tmp[i] == *str2_tmp) {
      char *tmp = &str1_tmp[i];
      int tmp_res = s21_strncmp(tmp, str2_tmp, s21_strlen(str2_tmp));
      if (tmp_res == 0) {
        res = &str1_tmp[i];
        break;
      }
    }
  }
  return res;
}

// Разбивает строку str на ряд токенов, разделенных delim.

char *s21_strtok(char *str, const char *delim) {
  static char *last = 0;
  char *st = s21_NULL;
  if (str) {
    last = str;
  }
  if (last != 0 && *last != 0) {
    char *c = last;
    while (s21_strchr(delim, *c)) {
      ++c;
    }
    if (*c != 0) {
      st = c;
      while (*c && (s21_strchr(delim, *c) == 0)) {
        ++c;
      }
      if (*c == 0) {
        last = c;
      } else {
        *c = 0;
        last = c + 1;
      }
    }
  }
  return st;
}
// Возвращает копию строки (str), преобразованной в верхний регистр.

void *s21_to_upper(const char *str) {
  char *chr = (char *)s21_NULL;
  if (str) {
    chr = (char *)malloc(s21_strlen(str) + 1);
    if (chr) {
      s21_strcpy(chr, str);
      char *temp = chr;
      do {
        if (*temp >= 97 && *temp <= 122) {
          *temp -= 32;
        }
      } while (*temp++);
    }
  }
  return (void *)chr;
}

// Возвращает копию строки (str), преобразованной в нижний регистр.

void *s21_to_lower(const char *str) {
  char *chr = (char *)s21_NULL;
  if (str) {
    chr = (char *)malloc(s21_strlen(str) + 1);
    if (chr) {
      s21_strcpy(chr, str);
      char *temp = chr;
      do {
        if (*temp >= 65 && *temp <= 90) {
          *temp += 32;
        }
      } while (*temp++);
    }
  }
  return (void *)chr;
}

// Возвращает новую строку, в которой указанная строка (str) вставлена в
// указанную позицию (start_index) в данной строке (src).

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *res = NULL;
  if (src && str && s21_strlen(src) >= start_index) {
    res = malloc((s21_strlen(src) + s21_strlen(str) + 1) * sizeof(char));
    if (res) {
      s21_strncpy(res, src, start_index);
      *(res + start_index) = '\0';
      s21_strcat(res, str);
      s21_strcat(res, src + start_index);
    }
  }
  return res;
}

// Возвращает новую строку, в которой удаляются все начальные и конечные
// вхождения набора заданных символов (trim_chars) из данной строки (src).

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_src = (char *)src;
  if (src && trim_chars) {
    char *cln_src = (char *)src;
    char *end_str = (char *)src + s21_strlen(src);
    while (*cln_src && s21_strchr(trim_chars, *cln_src)) {
      cln_src++;
    }
    while (end_str != cln_src && s21_strchr(trim_chars, *(end_str - 1))) {
      end_str--;
    }
    new_src = (char *)malloc((end_str - cln_src + 1) * sizeof(char));
    if (new_src) {
      s21_strncpy(new_src, cln_src, end_str - cln_src);
      *(new_src + (end_str - cln_src)) = '\0';
    }
  }
  return new_src;
}

//--------------------------------Sprintf---------------------------------//
int s21_sprintf(char *str, const char *format, ...) {
  va_list argList;
  va_start(argList, format);
  s21_size_t i = 0, flag = 0, error = 0;
  char *str_start = str;
  str = s21_strcpy(str, "");
  while (*format && error == 0) {
    FORMAT FFormat = {};
    FFormat.width = FFormat.tolerance = -1;
    FFormat.flag_error = FFormat.flag_sharp = FFormat.flag_zero =
        FFormat.flag_minus = FFormat.flag_space = FFormat.flag_plus = 0;
    if (*format == '%') {
      flag = 1;
      format++;
    } else {
      str[i++] = *(format++);
      str[i] = '\0';
    }

    if (flag == 1 && is_flag(*format)) {
      while (is_flag(*format)) {
        s21_set_flag(&FFormat, format++);
      }
    }

    if (flag == 1 && (is_digit(*format) || *format == '*'))
      format = s21_str_to_int(format, &FFormat.width, &argList);

    if (flag == 1 && *format == '.') {
      FFormat.tolerance = 0;
      format = s21_str_to_int(++format, &FFormat.tolerance, &argList);
    }

    if (flag == 1 && is_len(*format)) {
      FFormat.len = *(format++);
    }

    if (flag == 1 && is_spec(*format)) {
      FFormat.spec = *(format++);
    }

    if (flag == 1) {
      str = s21_format_param_to_str(str, &i, &FFormat, &argList);
      error = FFormat.flag_error;
    }
    flag = 0;
  }
  va_end(argList);
  if (error != 0) *str_start = '\0';
  return error == 0 ? (int)s21_strlen(str) : -1;
}

void s21_set_flag(FORMAT *FFormat, const char *format) {
  switch (*format) {
    case '-':
      FFormat->flag_minus = 1;
      break;
    case '+':
      FFormat->flag_plus = 1;
      break;
    case ' ':
      FFormat->flag_space = 1;
      break;
    case '#':
      FFormat->flag_sharp = 1;
      break;
    case '0':
      FFormat->flag_zero = 1;
      break;
  }
}

char *s21_format_param_to_str(char *str, s21_size_t *str_len, FORMAT *FFormat,
                              va_list *argList) {
  char *temp_str = s21_NULL;
  temp_str = calloc(1000 + FFormat->width + 2, sizeof(char));
  if (temp_str != s21_NULL) {
    switch (FFormat->spec) {
      case 'd':
      case 'i':
        s21_string_of_d(temp_str, argList, FFormat);
        break;
      case 'o':
        s21_string_of_o(temp_str, argList, FFormat);
        break;
      case 'u':
        s21_string_of_u(temp_str, argList, FFormat);
        break;
      case 'x':
      case 'X':
        s21_string_of_xX(temp_str, argList, FFormat);
        break;
      case 'e':
      case 'E':
        s21_string_of_eE(temp_str, argList, FFormat);
        break;
      case 'f':
        s21_string_of_f(temp_str, argList, FFormat);
        break;
      case 'g':
      case 'G':
        s21_string_of_gG(temp_str, argList, FFormat);
        break;
      case 'c':
        s21_string_of_c(temp_str, argList, FFormat);
        break;
      case 's':
        s21_string_of_s(temp_str, argList, FFormat);
        break;
      case 'p':
        s21_string_of_p(temp_str, argList, FFormat);
        break;
      case 'n':
        s21_string_of_n(str_len, argList);
        break;
      case '%':
        s21_string_of_perc(temp_str, FFormat);
        break;
    }
    s21_strcat(str, temp_str);
    free(temp_str);
    *str_len = s21_strlen(str);
  }
  return str;
}

void s21_string_of_n(s21_size_t const *str_len, va_list *argList) {
  int *p = va_arg(*argList, int *);
  *p = (int)*str_len;
}

char *s21_string_of_perc(char *str, FORMAT *FFormat) {
  FFormat->tolerance = 0;
  s21_strcat(str, "%");
  s21_ll_tolerance(str, FFormat);
  s21_ll_width_flag(str, FFormat);
  return str;
}

char *s21_string_of_p(char *str, va_list *argList, FORMAT *FFormat) {
  int width = FFormat->width < 15 ? 15 : FFormat->width;
  char *str_start = s21_NULL;
  str_start = str;
  int *p = va_arg(*argList, int *);
  char buf[4] = "x0";
  if (p == s21_NULL) {
    s21_strcpy(buf, "0x0");
  }

  for (int *j = p, k = 0; j && k < width;
       j = (void *)(((s21_size_t)j) >> 4), k++) {
    unsigned int dig = ((s21_size_t)j) % 0x10;
    if (dig < 10 && FFormat->spec == 'p')
      *(str_start++) = (char)('0' + dig);
    else
      *(str_start++) = (char)('a' + (dig - 10));
  }
  *str_start = '\0';
  s21_strcat(str, buf);
  s21_reverse_str(str);
  s21_ll_width_flag(str, FFormat);
  return str;
}

char *s21_string_of_f(char *str, va_list *argList, FORMAT *FFormat) {
  long double ld_number;
  double d_number;
  double f_number;

  switch (FFormat->len) {
    case 'l':
      d_number = (double)va_arg(*argList, double);
      s21_lf_to_str(str, d_number, FFormat);
      break;
    case 'L':
      ld_number = va_arg(*argList, long double);
      s21_lf_to_str(str, ld_number, FFormat);
      break;
    default:
      d_number = va_arg(*argList, double);
      f_number = d_number;
      s21_lf_to_str(str, f_number, FFormat);
  }
  s21_sign_flag(str, FFormat);
  s21_lf_width_flag(str, FFormat);
  return str;
}

char *s21_string_of_eE(char *str, va_list *argList, FORMAT *FFormat) {
  long double ld_number;
  double d_number;
  double f_number;

  switch (FFormat->len) {
    case 'l':
      d_number = (double)va_arg(*argList, double);
      s21_leE_to_str(str, d_number, FFormat);
      break;
    case 'L':
      ld_number = va_arg(*argList, long double);
      s21_leE_to_str(str, ld_number, FFormat);
      break;
    default:
      d_number = va_arg(*argList, double);
      f_number = d_number;
      s21_leE_to_str(str, f_number, FFormat);
  }
  s21_sign_flag(str, FFormat);
  s21_lf_width_flag(str, FFormat);
  return str;
}

char *s21_string_of_gG(char *str, va_list *argList, FORMAT *FFormat) {
  long double ld_number;
  double d_number;
  double f_number;

  switch (FFormat->len) {
    case 'l':
      d_number = (double)va_arg(*argList, double);
      s21_lgG_to_str(str, d_number, FFormat);
      break;
    case 'L':
      ld_number = va_arg(*argList, long double);
      s21_lgG_to_str(str, ld_number, FFormat);
      break;
    default:
      d_number = va_arg(*argList, double);
      f_number = d_number;
      s21_lgG_to_str(str, f_number, FFormat);
  }
  s21_sign_flag(str, FFormat);
  s21_lf_width_flag(str, FFormat);
  return str;
}

char *s21_leE_to_str(char *str, long double number, FORMAT *FFormat) {
  if (FFormat->tolerance < 0) FFormat->tolerance = 6;
  long double right = 0.0, mantis;
  int pow = 0;

  mantis = modfl(fabsl(number), &right);
  if (fpclassify(number) > 3) {
    while (right >= 10) {
      pow++;
      modfl(right / 10, &right);
    }
    if (pow == 0 && right < 1) {
      while (truncl(mantis * powl(10, pow * -1)) < 1) {
        pow--;
      }
    }
  }

  if (fpclassify(number) > 2) {
    number = number / powl(10, pow);
    s21_sprintf(str, FFormat->flag_sharp == 1 ? "%#.*Lfe%+.2d" : "%.*Lfe%+.2d",
                FFormat->tolerance, number, pow);
  } else {
    s21_sprintf(str, "%.*Lf", FFormat->tolerance);
    FFormat->flag_zero = 0;
  }
  if (FFormat->spec == 'E') {
    char *p = s21_NULL;
    p = s21_strchr(str, 'e');
    if (p) {
      *p = 'E';
    }
  }
  return str;
}

char *s21_lgG_to_str(char *str, long double number, FORMAT *FFormat) {
  if (FFormat->tolerance < 0) FFormat->tolerance = 6;
  long double right = 0.0;
  int pow = 0, pow_m = 0;

  long double mantis = modfl(fabsl(number), &right);
  if (fpclassify(mantis) > 3 && fpclassify(right) == 3) {
    while (truncl(mantis * powl(10, pow * -1)) < 1) {
      pow--;
    }
  }
  mantis = modfl(fabsl(number), &right);
  if (fpclassify(number) > 3) {
    while (right >= 1 && pow >= 0) {
      pow++;
      modfl(right / 10, &right);
    }
    if (fpclassify(mantis) > 3) {
      for (int i = 0; i < FFormat->tolerance - pow; i++) {
        mantis = modfl(right / 10, &right);
        if (fpclassify(mantis) > 3) {
          pow_m++;
        }
      }
    }
  }

  int flag;
  int tolerance;
  if (pow - 1 < -4 || pow - 1 > FFormat->tolerance - 1) {
    flag = 1;
    tolerance = FFormat->tolerance > 0 ? FFormat->tolerance - 1 : 0;
  } else {
    flag = 0;
    if (pow < 0)
      tolerance = FFormat->tolerance > 0 ? FFormat->tolerance : 0;
    else
      tolerance = FFormat->tolerance > 0 ? FFormat->tolerance - pow : 0;
  }

  if (flag == 1) {
    if (FFormat->spec == 'G')
      s21_sprintf(str, FFormat->flag_sharp == 1 ? "%#.*LE" : "%.*LE", tolerance,
                  number);
    else
      s21_sprintf(str, FFormat->flag_sharp == 1 ? "%#.*Le" : "%.*Le", tolerance,
                  number);
  } else {
    s21_sprintf(str, FFormat->flag_sharp == 1 ? "%#.*Lf" : "%.*Lf", tolerance,
                number);
  }

  char *p = s21_NULL;
  if (pow < 0 && flag == 1) {
    p = str;
    s21_size_t str_len = s21_strpbrk(str, FFormat->spec == 'G' ? "E" : "e") - p;
    if (str_len > 2 && (int)str_len - 1 >= FFormat->tolerance &&
        *(p + str_len - 1) == '0' && FFormat->flag_sharp == 0) {
      p = p + str_len - 1;
      while (*p == '0') {
        *(p--) = '\0';
      }
      p = str + str_len;
      s21_strcat(str, p);
    }
  }

  p = str;
  p = p + s21_strlen(str) - 1;

  while (*p == '0' && FFormat->flag_sharp != 1) {
    *p-- = '\0';
  }
  if (*p == '.' && FFormat->flag_sharp != 1) {
    *p = '\0';
  }

  return str;
}

char *s21_lf_to_str(char *str, long double number, FORMAT *FFormat) {
  if (FFormat->tolerance < 0) FFormat->tolerance = 6;
  s21_ld_to_a(str, number, FFormat);
  return str;
}

char *s21_string_of_s(char *str, va_list *argList, FORMAT *FFormat) {
  wchar_t *pw = s21_NULL;
  char *p = s21_NULL;

  switch (FFormat->len) {
    case 'l':
      pw = va_arg(*argList, wchar_t *);
      if (!pw) {
        if (FFormat->tolerance < 6) {
          s21_strncat(str, "(null)", FFormat->tolerance);
        } else {
          s21_strcat(str, "(null)");
        }
      } else {
        wch_to_str(str, pw, FFormat->tolerance > -1 ? FFormat->tolerance : 0);
      }
      break;
    default:
      p = va_arg(*argList, char *);
      if (!p) {
        if (FFormat->tolerance < 6) {
          s21_strncat(str, "(null)", FFormat->tolerance);
        } else {
          s21_strcat(str, "(null)");
        }
      } else {
        if (FFormat->tolerance > -1) {
          s21_strncat(str, p, FFormat->tolerance);
        } else {
          s21_strcat(str, p);
        }
      }
  }
  s21_ll_width_flag(str, FFormat);
  return str;
}

char *s21_string_of_c(char *str, va_list *argList, FORMAT *FFormat) {
  wchar_t wchar;
  wchar_t wchar_s[10] = {0};
  switch (FFormat->len) {
    case 'l':
      wchar = va_arg(*argList, wchar_t);
      wchar_s[0] = wchar;
      wch_to_str(str, wchar_s, 0);
      break;
    default:
      str[0] = va_arg(*argList, int);
      str[1] = '\0';
  }
  s21_ll_width_flag(str, FFormat);
  return str;
}

char *s21_string_of_u(char *str, va_list *argList, FORMAT *FFormat) {
  unsigned short us_number;
  unsigned long ul_number;
  unsigned int u_number;

  switch (FFormat->len) {
    case 'h':
      us_number = (unsigned short)va_arg(*argList, unsigned int);
      s21_ll_to_str(str, us_number);
      break;
    case 'l':
      ul_number = (unsigned long)va_arg(*argList, unsigned long);
      s21_ul_to_str(str, ul_number);
      break;
    default:
      u_number = (unsigned int)va_arg(*argList, unsigned int);
      s21_ll_to_str(str, u_number);
  }

  s21_ll_tolerance(str, FFormat);
  s21_sign_flag(str, FFormat);
  s21_ll_width_flag(str, FFormat);
  return str;
}

char *s21_string_of_d(char *str, va_list *argList, FORMAT *FFormat) {
  long int ld_number;
  short int sd_number;
  int number;

  switch (FFormat->len) {
    case 'h':
      sd_number = (short int)va_arg(*argList, int);
      s21_ll_to_str(str, sd_number);
      break;
    case 'l':
      ld_number = (long int)va_arg(*argList, long int);
      s21_ll_to_str(str, ld_number);
      break;
    default:
      number = va_arg(*argList, int);
      s21_ll_to_str(str, number);
  }
  s21_ll_tolerance(str, FFormat);
  s21_sign_flag(str, FFormat);
  s21_ll_width_flag(str, FFormat);
  return str;
}

char *s21_string_of_o(char *str, va_list *argList, FORMAT *FFormat) {
  unsigned long int ld_number;
  unsigned short int sd_number;
  unsigned int number;

  switch (FFormat->len) {
    case 'h':
      sd_number = (unsigned short int)va_arg(*argList, unsigned int);
      s21_ol_to_str(str, sd_number, FFormat->flag_sharp);
      break;
    case 'l':
      ld_number = (unsigned long int)va_arg(*argList, unsigned long int);
      s21_ol_to_str(str, ld_number, FFormat->flag_sharp);
      break;
    default:
      number = va_arg(*argList, unsigned int);
      s21_ol_to_str(str, number, FFormat->flag_sharp);
  }
  s21_ll_tolerance(str, FFormat);
  s21_sign_flag(str, FFormat);
  s21_ll_width_flag(str, FFormat);
  return str;
}

char *s21_string_of_xX(char *str, va_list *argList, FORMAT *FFormat) {
  unsigned long int ld_number;
  unsigned short int sd_number;
  unsigned int number;

  switch (FFormat->len) {
    case 'h':
      sd_number = (short unsigned int)va_arg(*argList, unsigned int);
      s21_hl_to_str(str, sd_number, FFormat);
      break;
    case 'l':
      ld_number = (long unsigned int)va_arg(*argList, unsigned long int);
      s21_hl_to_str(str, ld_number, FFormat);
      break;
    default:
      number = (unsigned int)va_arg(*argList, unsigned int);
      s21_hl_to_str(str, number, FFormat);
  }
  s21_ll_tolerance(str, FFormat);
  s21_sign_flag(str, FFormat);
  s21_ll_width_flag(str, FFormat);

  return str;
}

char *s21_lf_width_flag(char *str, FORMAT *FFormat) {
  int str_len = (int)s21_strlen(str);
  char *p = s21_NULL, *p2 = s21_NULL;
  p2 = str;
  if (FFormat->width > (int)str_len) {
    char *num_str = calloc(1000 + FFormat->width + 2, sizeof(char));
    if (num_str) {
      p = num_str;
      if (!is_digit(*p2) && FFormat->flag_zero) {
        *(p++) = *(p2++);
      }
      for (int i = 0; i < FFormat->width; i++) {
        if (FFormat->flag_minus == 1) {
          if (i < str_len) {
            *(p++) = *(p2++);
          } else {
            if (FFormat->flag_zero == 1)
              *(p++) = '0';
            else
              *(p++) = ' ';
          }
        } else {
          if (i < FFormat->width - str_len) {
            if (FFormat->flag_zero == 1)
              *(p++) = '0';
            else
              *(p++) = ' ';
          } else {
            *(p++) = *(p2++);
          }
        }
      }
      num_str[FFormat->width] = '\0';
      str = s21_strcpy(str, num_str);
      free(num_str);
    }
  }
  return str;
}

char *s21_ll_width_flag(char *str, FORMAT *FFormat) {
  int str_len = (int)s21_strlen(str);
  if (FFormat->width > (int)str_len) {
    char *num_str = calloc(1000 + FFormat->width + 2, sizeof(char));
    if (num_str) {
      for (int i = 0; i < FFormat->width; i++) {
        if (FFormat->flag_minus == 1) {
          if (i < str_len) {
            num_str[i] = str[i];
          } else {
            num_str[i] = ' ';
          }
        } else {
          if (i < FFormat->width - str_len) {
            num_str[i] = ' ';
          } else {
            num_str[i] = str[i - (FFormat->width - str_len)];
          }
        }
      }
      num_str[FFormat->width] = '\0';
      str = s21_strcpy(str, num_str);
      free(num_str);
    }
  }
  return str;
}

char *wch_to_str(char *str, wchar_t *wstr, s21_size_t len) {
  s21_size_t str_len = s21_strlen(str);
  int cnt = len;
  char *p = str + str_len;

  while (*wstr != '\0' && (cnt-- > 0 || len == 0)) {
    *(p++) = (char)*(wstr++);
  }
  *p = '\0';
  return str;
}

char *s21_sign_flag(char *str, FORMAT *FFormat) {
  if (is_digit(*str) || *str == 'i') {
    char num_str[2] = "";
    char *p = s21_NULL;
    p = num_str;
    if (FFormat->flag_plus)
      *(p++) = '+';
    else if (FFormat->flag_space)
      *(p++) = ' ';
    *p = '\0';
    s21_reverse_str(str);
    s21_strcat(str, num_str);
    s21_reverse_str(str);
  }
  return str;
}

char *s21_ll_tolerance(char *str, FORMAT *FFormat) {
  char *num_str = calloc(1000 + FFormat->width + 2, sizeof(char));
  if (num_str) {
    s21_size_t str_len = s21_strlen(str);
    int shift;
    char *p = s21_NULL;
    char *s = s21_NULL;
    p = num_str;
    s = str;

    int sign = *s == '-' ? -1 : 0;
    if (FFormat->flag_zero == 1)
      FFormat->tolerance = (FFormat->tolerance > FFormat->width)
                               ? FFormat->tolerance
                               : FFormat->width;

    FFormat->tolerance = FFormat->tolerance > (int)str_len + sign
                             ? FFormat->tolerance
                             : (int)str_len + sign;
    shift = FFormat->spec == 'x' && FFormat->flag_sharp == 1 ? 32 : 0;

    s21_reverse_str(str);
    for (int i = 0; i < FFormat->tolerance; i++) {
      if (i < (int)str_len + sign)
        *(p++) = *(s++);
      else
        *(p++) = '0';
    }

    if (FFormat->flag_sharp == 1 && FFormat->spec == (char)('X' + shift)) {
      *(p++) = (char)('X' + shift);
      *(p++) = '0';
    }

    if (sign < 0) *(p++) = '-';
    *p = '\0';
    s21_reverse_str(num_str);
    s21_strcpy(str, num_str);
    free(num_str);
  }
  return str;
}

char *s21_ll_to_str(char *str, long long number) {
  char *p = s21_NULL;
  int flag = 1, sign;

  sign = number < 0 ? -1 : 1;
  number *= sign;
  p = str;

  while (flag) {
    int digit;
    if (number >= 10) {
      digit = (int)(number % 10);
      number = (number - digit) / 10;
    } else {
      digit = (int)number;
      flag = 0;
    }
    *(p++) = (char)(digit + '0');
  }

  if (sign < 0) {
    *(p++) = '-';
  }
  *p = '\0';
  s21_reverse_str(str);
  return str;
}

char *s21_ul_to_str(char *str, unsigned long long number) {
  char *p = s21_NULL;
  int flag = 1;

  p = str;

  while (flag) {
    int digit;
    if (number >= 10) {
      digit = (int)(number % 10);
      number = (number - digit) / 10;
    } else {
      digit = (int)number;
      flag = 0;
    }
    *(p++) = (char)(digit + '0');
  }
  *p = '\0';
  s21_reverse_str(str);
  return str;
}

char *s21_ol_to_str(char *str, unsigned long long number, int prefix) {
  char *p = s21_NULL;
  int flag = 1;

  p = str;

  while (flag) {
    unsigned int digit;
    if (number > 7) {
      digit = number % 8;
      number = (number - digit) / 8;
    } else {
      digit = number;
      flag = 0;
    }
    *(p++) = (char)(digit + '0');
  }

  if (prefix == 1) *(p++) = '0';
  *p = '\0';
  s21_reverse_str(str);
  return str;
}

char *s21_hl_to_str(char *str, unsigned long long number, FORMAT *FFormat) {
  char *p = s21_NULL;
  int flag = 1, shift;

  p = str;

  shift = FFormat->spec == 'x' ? 32 : 0;

  while (flag) {
    unsigned int digit;
    if (number > 15) {
      digit = number % 16;
      number = (number - digit) / 16;
    } else {
      digit = number;
      flag = 0;
    }
    if (digit < 10)
      *(p++) = (char)(digit + '0');
    else
      *(p++) = (char)(digit + 'A' + shift - 10);
  }
  *p = '\0';
  s21_reverse_str(str);
  return str;
}

char *s21_str_to_int(const char *format, int *number, va_list *argList) {
  *number = 0;
  while (is_digit(*format)) {
    *number = *format - '0' + *number * 10;
    format++;
  }
  if (*format == '*') {
    *number = va_arg(*argList, int);
    format++;
  }
  return (char *)format;
}

char *s21_reverse_str(char *str) {
  s21_size_t str_len = s21_strlen(str);
  char ch;
  for (s21_size_t i = 0; i < str_len / 2; i++) {
    ch = str[i];
    str[i] = str[str_len - 1 - i];
    str[str_len - 1 - i] = ch;
  }
  return str;
}

long double s21_round(long double x, int tolerance) {
  long double right = 0.0;
  long double x1 = modfl(fabsl(x), &right);
  int mul = 0;
  int sign = signbit(x) == 0 ? 1 : -1;
  for (int i = 0; i < tolerance; i++) {
    mul--;
  }

  if (roundl(x1 / powl(10, mul)) > truncl(x1 / powl(10, mul))) {
    x = x + (5 * powl(10, mul - 1)) * sign;
  }
  if (tolerance <= 6 && x1 > 0) {
    x = x / powl(10, mul);
    x = truncl(x) * powl(10, mul);
  }
  return x;
}

char *s21_ld_to_a(char *str, long double number, FORMAT *FFormat) {
  char num1_str[1000] = "", *p1 = s21_NULL;
  p1 = num1_str;
  char num2_str[1000] = "", *p2 = s21_NULL;
  p2 = num2_str;
  long double mantis, right = 0.0L, pow = 1.0L, pow_t = 1.0L;
  int sign;
  sign = signbit(number) == 0 ? 1 : -1;

  if (fpclassify(number) < 4) {
    d_class_to_str(num1_str, number, FFormat->tolerance);
    if (sign < 0 && fpclassify(number) != 1) s21_strcat(str, "-");
    s21_strcat(str, num1_str);
    FFormat->flag_zero = 0;
  } else {
    number = s21_round(number, FFormat->tolerance);
    mantis = modfl(fabsl(number), &right);

    while (truncl(right / pow) > 0) {
      int digit;
      digit = (int)truncl(fmodl(truncl(right), pow * (long double)10L) / (pow));
      *(p1++) = (char)(digit + '0');
      pow *= 10L;
    }

    if (sign < 0) *(p1++) = '-';
    *p1 = '\0';

    for (int i = 0; i < FFormat->tolerance; i++) {
      pow_t *= 10;
    }

    mantis = roundl(mantis * pow_t);
    pow = 1.0L;
    while (pow < pow_t) {
      int digit;
      digit =
          (int)truncl(fmodl(truncl(mantis), pow * (long double)10L) / (pow));
      *(p2++) = (char)(digit + '0');
      pow *= 10L;
    }
    *p2 = '\0';
    s21_reverse_str(num1_str);
    if (s21_strlen(num1_str) == 0) {
      s21_strcat(str, "0");
    }
    s21_strcat(str, num1_str);
    if (FFormat->tolerance > 0 || FFormat->flag_sharp == 1) {
      s21_strcat(str, ".");
    }
    if (FFormat->tolerance > 0) {
      s21_reverse_str(num2_str);
      s21_strcat(str, num2_str);
    }
  }
  return str;
}

char *d_class_to_str(char *str, long double x, int tolerance) {
  switch (fpclassify(x)) {
    case FP_NAN:
      s21_strcat(str, "nan");
      break;
    case FP_INFINITE:
      s21_strcat(str, "inf");
      break;
    case FP_ZERO:
      s21_strcat(str, "0");
      if (tolerance > 0) {
        s21_strcat(str, ".");
        while (tolerance--) {
          s21_strcat(str, "0");
        }
      }
      break;
  }
  return str;
}

//--------------------------------Sprintf---------------------------------//
