﻿#include "OmokManager.h"

void OmokManager::Play() {
	Turn turn_ = Turn::White;
	// 이전 턴의 플레이어가 게임을 끝냈는지 확인
	while (!omok_.IsGameOver()) {
		omok_.Print();
		// 다음 플레이어로 턴을 넘김
		turn_ = (turn_ == Turn::Black) ? Turn::White : Turn::Black;
		Move next_move = GetPlayer(turn_)->GetNextMove(omok_);
		std::cout << omok_.GetTurnName(next_move.turn) << ' ' << next_move.x << ' ' << next_move.y << std::endl;
		omok_.PutNextMove(next_move);
	}
	PrintResult();
}

Turn OmokManager::GetResult() const
{
	return omok_.GetResult();
}

void OmokManager::PrintResult() const {
	omok_.Print();

	Turn result = omok_.GetResult();
	if (result == Turn::None) {
		std::cout << "Draw - Game board is full" << std::endl;
	}
	else {
		std::cout << omok_.GetTurnName(result) << " " << "win!" << std::endl;
	}
}