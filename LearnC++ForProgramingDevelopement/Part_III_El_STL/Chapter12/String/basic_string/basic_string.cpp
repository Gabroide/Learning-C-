using string = basic_string <char>;
using u16string = basic_string <char16_t>;
using u32string = basic_string <char32_t>;
using wstring = basic_string <wchar_t>;

string copiedString{ literalString };

string literalString{ "This is a literal string!" };

string copiedString{ literalString };

string lsterStartPosition{ "This is aliteral string!", 5 };
string listerStartPositionAndNumber{ "This is a literal string!", 5, 4 };