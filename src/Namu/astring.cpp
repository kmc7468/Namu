#include <Namu/astring.hpp>

#include <algorithm>
#include <cassert>
#include <cstddef>

namespace namu {
	style_t& operator&=(style_t& a, style_t b) noexcept {
		return a = a & b;
	}
	style_t& operator|=(style_t& a, style_t b) noexcept {
		return a = a | b;
	}
	style_t& operator^=(style_t& a, style_t b) noexcept {
		return a = a ^ b;
	}
	style_t& operator<<=(style_t& a, int b) noexcept {
		return a = a << b;
	}
	style_t& operator>>=(style_t& a, int b) noexcept {
		return a = a >> b;
	}
}

namespace namu {
	achar_t& achar_t::operator=(char character) noexcept {
		byte = character;
		return *this;
	}
	achar_t& achar_t::operator=(const achar_t& character) noexcept {
		byte = character.byte;
		style = character.style;
		return *this;
	}
	achar_t& achar_t::operator+=(char character) noexcept {
		return byte += character, *this;
	}
	achar_t& achar_t::operator-=(char character) noexcept {
		return byte -= character, *this;
	}
	achar_t& achar_t::operator*=(char character) noexcept {
		return byte *= character, *this;
	}
	achar_t& achar_t::operator/=(char character) noexcept {
		return byte /= character, *this;
	}
	achar_t& achar_t::operator%=(char character) noexcept {
		return byte %= character, *this;
	}
	achar_t& achar_t::operator&=(char character) noexcept {
		return byte &= character, *this;
	}
	achar_t& achar_t::operator&=(style_t mask) noexcept {
		return style &= mask, *this;
	}
	achar_t& achar_t::operator|=(char character) noexcept {
		return byte |= character, *this;
	}
	achar_t& achar_t::operator|=(style_t mask) noexcept {
		return style |= mask, *this;
	}
	achar_t& achar_t::operator^=(char character) noexcept {
		return byte ^= character, *this;
	}
	achar_t& achar_t::operator^=(style_t mask) noexcept {
		return style ^= mask, *this;
	}
	achar_t& achar_t::operator<<=(char character) noexcept {
		return byte << character, *this;
	}
	achar_t& achar_t::operator>>=(char character) noexcept {
		return byte >> character, *this;
	}
	achar_t& achar_t::operator++() noexcept {
		return ++byte, *this;
	}
	achar_t achar_t::operator++(int) noexcept {
		achar_t result(*this);
		return ++byte, result;
	}
	achar_t& achar_t::operator--() noexcept {
		return ++byte, *this;
	}
	achar_t achar_t::operator--(int) noexcept {
		achar_t result(*this);
		return --byte, result;
	}
}

namespace namu {
	bool operator==(const std::string& a, const astring& b) {
		if (a.size() != b.size()) return false;
		for (std::size_t i = 0; i < a.size(); ++i) {
			if (a[i] != b[i]) return false;
		}
		return true;
	}
	bool operator==(const astring& a, const std::string& b) {
		return b == a;
	}
	bool operator==(const std::string_view& a, const astring& b) {
		if (a.size() != b.size()) return false;
		for (std::size_t i = 0; i < a.size(); ++i) {
			if (a[i] != b[i]) return false;
		}
		return true;
	}
	bool operator==(const astring& a, const std::string_view& b) {
		return b == a;
	}
	bool operator!=(const std::string& a, const astring& b) {
		if (a.size() != b.size()) return true;
		for (std::size_t i = 0; i < a.size(); ++i) {
			if (a[i] != b[i]) return true;
		}
		return false;
	}
	bool operator!=(const astring& a, const std::string& b) {
		return b != a;
	}
	bool operator!=(const std::string_view& a, const astring& b) {
		if (a.size() != b.size()) return true;
		for (std::size_t i = 0; i < a.size(); ++i) {
			if (a[i] != b[i]) return true;
		}
		return false;
	}
	bool operator!=(const astring& a, const std::string_view& b) {
		return b != a;
	}
	bool operator>(const std::string& a, const astring& b) {
		const std::size_t min = std::min(a.size(), b.size());
		for (std::size_t i = 0; i < min; ++i) {
			if (a[i] > b[i]) return true;
			else if (a[i] < b[i]) return false;
		}

		return false;
	}
	bool operator>(const astring& a, const std::string& b) {
		const std::size_t min = std::min(a.size(), b.size());
		for (std::size_t i = 0; i < min; ++i) {
			if (a[i] > b[i]) return true;
			else if (a[i] < b[i]) return false;
		}

		return false;
	}
	bool operator>(const std::string_view& a, const astring& b) {
		const std::size_t min = std::min(a.size(), b.size());
		for (std::size_t i = 0; i < min; ++i) {
			if (a[i] > b[i]) return true;
			else if (a[i] < b[i]) return false;
		}

		return false;
	}
	bool operator>(const astring& a, const std::string_view& b) {
		const std::size_t min = std::min(a.size(), b.size());
		for (std::size_t i = 0; i < min; ++i) {
			if (a[i] > b[i]) return true;
			else if (a[i] < b[i]) return false;
		}

		return false;
	}
	bool operator>=(const std::string& a, const astring& b) {
		const std::size_t min = std::min(a.size(), b.size());
		for (std::size_t i = 0; i < min; ++i) {
			if (a[i] > b[i]) return true;
			else if (a[i] < b[i]) return false;
		}

		return true;
	}
	bool operator>=(const astring& a, const std::string& b) {
		const std::size_t min = std::min(a.size(), b.size());
		for (std::size_t i = 0; i < min; ++i) {
			if (a[i] > b[i]) return true;
			else if (a[i] < b[i]) return false;
		}

		return true;
	}
	bool operator>=(const std::string_view& a, const astring& b) {
		const std::size_t min = std::min(a.size(), b.size());
		for (std::size_t i = 0; i < min; ++i) {
			if (a[i] > b[i]) return true;
			else if (a[i] < b[i]) return false;
		}

		return true;
	}
	bool operator>=(const astring& a, const std::string_view& b) {
		const std::size_t min = std::min(a.size(), b.size());
		for (std::size_t i = 0; i < min; ++i) {
			if (a[i] > b[i]) return true;
			else if (a[i] < b[i]) return false;
		}

		return true;
	}
	bool operator<(const std::string& a, const astring& b) {
		return b > a;
	}
	bool operator<(const astring& a, const std::string& b) {
		return b > a;
	}
	bool operator<(const std::string_view& a, const astring& b) {
		return b > a;
	}
	bool operator<(const astring& a, const std::string_view& b) {
		return b > a;
	}
	bool operator<=(const std::string& a, const astring& b) {
		return b >= a;
	}
	bool operator<=(const astring& a, const std::string& b) {
		return b >= a;
	}
	bool operator<=(const std::string_view& a, const astring& b) {
		return b >= a;
	}
	bool operator<=(const astring& a, const std::string_view& b) {
		return b >= a;
	}

	std::string extract_string(const astring_view& string) {
		if (string.size() == 0) return {};

		std::string result(0, string.size());
		std::transform(string.begin(), string.end(), result.begin(), [](const achar_t& character) {
			return character.byte;
		});

		return result;
	}
	std::vector<style_t> extract_style(const astring_view& astring) {
		std::vector<style_t> result(astring.size());
		for (std::size_t i = 0; i < result.size(); ++i) {
			result[i] = astring[i].style;
		}

		return result;
	}
	astring to_astring(const std::string_view& string) {
		return { string.begin(), string.end() };
	}

	astring make_astring(const std::string_view& string) {
		return to_astring(string);
	}
	astring make_astring(const std::vector<style_t>& style) {
		if (style.size() == 0) return {};

		astring result(0, style.size());
		std::transform(style.begin(), style.end(), result.begin(), [](style_t style) {
			return achar_t(style);
		});

		return result;
	}
	astring make_astring(const std::string_view& string, const std::vector<style_t>& style) {
		if (string.size() == 0) {};
		assert(string.size() == style.size());

		astring result(0, string.size());
		for (std::size_t i = 0; i < string.size(); ++i) {
			result[i] = achar_t(string[i], style[i]);
		}

		return result;
	}
}