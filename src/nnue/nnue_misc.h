/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2024 The Stockfish developers (see AUTHORS file)

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NNUE_MISC_H_INCLUDED
#define NNUE_MISC_H_INCLUDED

#include <cstddef>
#include <string>

#include "../types.h"
#include "nnue_architecture.h"

namespace Stockfish {

class Position;

namespace Eval::NNUE {

struct EvalFile {
    // Default net name, will use one of the EvalFileDefaultName* macros defined
    // in evaluate.h
    std::string defaultName;
    // Selected net name, either via uci option or default
    std::string current;
    // Net description extracted from the net file
    std::string netDescription;
};


struct NnueEvalTrace {
    static_assert(LayerStacks == PSQTBuckets);

    Value       psqt[LayerStacks];
    Value       positional[LayerStacks];
    std::size_t correctBucket;
};


struct Networks;


std::string trace(Position& pos, const Networks& networks);
void        hint_common_parent_position(const Position& pos, const Networks& networks, bool forceBig);

}  // namespace Stockfish::Eval::NNUE
}  // namespace Stockfish

#endif  // #ifndef NNUE_MISC_H_INCLUDED
