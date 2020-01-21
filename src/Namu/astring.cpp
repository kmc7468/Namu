#include <Namu/astring.hpp>

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