/****************************************************************************
 * KONOHA COPYRIGHT, LICENSE NOTICE, AND DISCRIMER
 *
 * Copyright (c)  2010-      Konoha Team konohaken@googlegroups.com
 * All rights reserved.
 *
 * You may choose one of the following two licenses when you use konoha.
 * See www.konohaware.org/license.html for further information.
 *
 * (1) GNU Lesser General Public License 3.0 (with KONOHA_UNDER_LGPL3)
 * (2) Konoha Software Foundation License 1.0
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

// **************************************************************************
// LIST OF CONTRIBUTERS
//  kimio - Kimio Kuramitsu, Yokohama National University, Japan
//  goccy54
// **************************************************************************

#include <QHBoxLayout>
#include <konoha1.h>
#include "qt4commons.hpp"

#ifdef __cplusplus
extern "C" {
#endif

class KQHBoxLayout : public QHBoxLayout, public KObject {
public:
	KQHBoxLayout(QWidget * w) : QHBoxLayout(w), KObject() {
	}
};

//## QHBoxLayout QHBoxLayout.new(QWidget parent);
KMETHOD QHBoxLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_QObject(new KQHBoxLayout(QWidget_parent(sfp[1])));
}

// must move to KQVBoxLayout.cpp

class KQVBoxLayout : public QVBoxLayout, public KObject {
public:
	KQVBoxLayout(QWidget * w) : QVBoxLayout(w), KObject() {
	}
};

//## QVBoxLayout QVBoxLayout.new(QWidget parent);
KMETHOD QVBoxLayout_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	RETURN_QObject(new KQVBoxLayout(QWidget_parent(sfp[1])));
}



#ifdef __cplusplus
}
#endif