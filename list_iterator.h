//  $Id$
// 
//  SuperTux
//  Copyright (C) 2005 Matthias Braun <matze@braunis.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
// 
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
//  02111-1307, USA.

#ifndef __LISP_ITERATOR_H__
#define __LISP_ITERATOR_H__

#include "lisp/lisp.h"

namespace lisp
{

/**
 * Small and a bit hacky helper class that helps parsing lisp lists where all
 * entries are lists again themselves
 */
class ListIterator
{
public:
  ListIterator(const lisp::Lisp* cur);
  
  const std::string& item() const
  { return current_item; }
  lisp::Lisp* lisp() const
  { return current_lisp; }
  lisp::Lisp* value() const
  { return current_lisp->get_car(); }
  bool next();

private:
  std::string current_item;
  lisp::Lisp* current_lisp;
  const lisp::Lisp* cur;
};

}

#endif

