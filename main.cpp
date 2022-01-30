#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class bank
{
private:
  float balance = 0;
  string xisob_raqam = "Elyor04";

public:
  void pul_k(float h)
  {
    balance += h;
  }
  void pul_y(float h)
  {
    balance -= h;
  }
  float pul(string k)
  {
    if (k == xisob_raqam)
      return balance;
    else
      return 'e';
  }
};

typedef struct
{
  float x, y, z, x2, y2, z2;
  float x3, y3, z3, x4, y4, z4;
}kordi;

float bur(kordi a)
{
  float const pi = 3.1416;

  float aa = a.x2 - a.x;
  float aa2 = a.x4 - a.x3;
  float bb = a.y2 - a.y;
  float bb2 = a.y4 - a.y3;
  float cc = a.z2 - a.z;
  float cc2 = a.z4 - a.z3;

  float v_k = aa * aa2 + bb * bb2 + cc * cc2;
  float m_k = sqrt(pow(aa, 2) + pow(bb, 2) + pow(cc, 2)) * sqrt(pow(aa2, 2) + pow(bb2, 2) + pow(cc2, 2));
  float cos_x = v_k / m_k;

  return acos(cos_x) * (180 / pi);
}

void v_burchak()
{
  kordi tip; back:

  cout << " birinchi vektor boshi koordinatalarini kiriting\n";
  cout << " x1 = "; cin >> tip.x;
  cout << " y1 = "; cin >> tip.y;
  cout << " z1 = "; cin >> tip.z;
  cout << " shu vektor oxiri koordinatalarini kiriting\n";
  cout << " x2 = "; cin >> tip.x2;
  cout << " y2 = "; cin >> tip.y2;
  cout << " z2 = "; cin >> tip.z2;
  if (tip.x == tip.x2 && tip.y == tip.y2 && tip.z == tip.z2)
  {
	cout << "iltimos no`l vektor kiritmang\n"; goto back;
  }
  cout << endl; back2:
  cout << " ikkinchi vektor boshi koordinatalarini kiriting\n";
  cout << " x1 = "; cin >> tip.x3;
  cout << " y1 = "; cin >> tip.y3;
  cout << " z1 = "; cin >> tip.z3;
  cout << " shu vektor oxiri koordinatalarini kiriting\n";
  cout << " x2 = "; cin >> tip.x4;
  cout << " y2 = "; cin >> tip.y4;
  cout << " z2 = "; cin >> tip.z4;
  if (tip.x3 == tip.x4 && tip.y3 == tip.y4 && tip.z3 == tip.z4)
  {
	cout << "iltimos no`l vektor kiritmang\n"; goto back2;
  }
  cout << endl;
  cout << " birinchi va ikkinchi vektorlar orasidagi burchak ";
  cout << setprecision(2) << fixed << bur(tip) << " gradusga teng\n";
}

void e_bank()
{
  string a;
  short int x;
  float b;

  bank xisob; nish:
  cout << "xisob raqamingizni kiriting: "; cin >> a;

  if (xisob.pul(a) != 'e')
  {
    cout << "\n(kiritilayotgan va yechilayotgan pullar musbat(+) bolsin)\n";
    do
    {
      cout << "1: pul kiritish\n2: pul yechish\n3: mablagni tekshirish\n4: chiqish\n"; cin >> x;
      switch (x)
      {
      case 1: cout << "qancha pul kiritilsin: "; cin >> b;
        if (b >= 0)
        {
          xisob.pul_k(b); cout << b << " som pul kiritildi\n";
        }
        else
          cout << "kiritilayotgan va yechilayotgan pullar musbat(+) bolsin\n"; break;
      case 2: cout << "qancha pul yechilsin: "; cin >> b;
        if (b >= 0)
        {
          xisob.pul_y(b);

          if (xisob.pul(a) >= 0)
            cout << b << " som pul yechildi\n";
          else
          {
            cout << "mablag yetarli emas\n";
            xisob.pul_k(b);
          }
        }
        else
          cout << "kiritilayotgan va yechilayotgan pullar musbat(+) bolsin\n"; break;
      case 3: cout << xisob.pul(a) << " som pul bor" << endl; break;
      case 4: break;
      default: cout << "notogri raqam\n";
      }
      cout << endl;
    } while (x != 4);
  }
  else
  {
    cout << "xisob raqami notogri\n";
    goto nish;
  }
}

void k_teng()
{
  float a, b, c;
  float D, x, x2;
  short int n;

  short int m = 0; back:
  cout << "a*x^2 + b*x + c = 0\n";
  cout << "a = "; cin >> a;
  cout << "b = "; cin >> b;
  cout << "c = "; cin >> c;
  if (a != 0)
  {
    D = (b * b) - (4 * a * c);
    if (D > 0)
    {
      x = (-b - sqrt(D)) / (2 * a);
      x2 = (-b + sqrt(D)) / (2 * a);
      if (x == -0)
        x = 0;
      if (x2 == -0)
        x2 = 0;
      cout << setprecision(4) << fixed << "x1 = " << x << endl;
      cout << setprecision(4) << fixed << "x2 = " << x2 << endl;
    }
    else if (D == 0)
    {
      x = -b / (2 * a);
      if (x == -0)
        x = 0;
      cout << setprecision(4) << fixed << "x = " << x << endl;
	}
    else
      cout << "yechimga ega emas\n";
  }
  else
  {
    if (b != 0)
    {
      x = -c / b;
      if (x == -0)
        x = 0;
      cout << setprecision(4) << fixed << "x = " << x << endl;
    }
    else if ((b == 0) && (c == 0))
      cout << "cheksiz kop yechim\n";
    else
      cout << "yechimga ega emas\n";
  }

  m++; back2:
  cout << "\n1: davom ettirish \n2: chiqish \n";
  if (m == 3)
    cout << "3: bizni baholash \n"; cin >> n;
  switch (n)
  {
  case 1:
    if (m == 3)
      m = 0;
    cout << endl; goto back;
  case 2: break;
  case 3:
    if (m == 3)
    {
    back4:
      cout << "\n5 baho \n4 baho \n3 baho \n"; cin >> n;
      switch (n)
      {
      case 5: cout << "sizdan minnaddormiz :)\n"; break;
      case 4: cout << "yanayam yaxshiroq bolishga harakat qilamiz\n"; break;
      case 3: cout << "avfsuz, sizni fikringizni inobatga olamiz\n"; break;
      default: cout << "iltimos bunday baholamang"; goto back4;
      }
      m = 0; goto back2;
    }
    else
      goto back3;
  default: back3: cout << "notogri buyruq"; goto back2;
  }
}

void r_uyin()
{
  short int a, b, x;
  srand(time(0));
  x = rand() % 100 + 1;

  cout << "1 dan 100 gacha oylangan sonni toping(sizda 8 ta imkoniyat bor)\n";
  b = 1; a = 0;
  while ((b <= 8) && (a != x))
  {
    cin >> a;
    if (a > x)
      cout << "kiritigan son oylangan sondan katta\n";
    else if (a < x)
      cout << "kiritigan son oylangan sondan kichkina\n";
    else
      cout << "URAAA! siz sonni topdingiz :)\n";
    b++;
  }
  if (a != x)
    cout << "siz oylangan sonni topolmadiz :(\n";
  cout << "oylangan son " << x << " edi\n";
}

void bulinish()
{
  int a;
  cout << "birdan yigirmagacha bolinadigan sonni kiriting\n"; cin >> a;
  for (int b = 1; b <= 20; b++)
  {
    if (a % b == 0)
      cout << b << " ga bolinadi\n";
    else
      cout << b << " ga bolinmaydi\n";
  }
}

void son_yoz()
{
  long long int a, x;
  const string b[9] = { "bir " , "ikki " , "uch " , "to`rt " , "besh " , "olti " , "yetti " , "sakkiz " , "toqqiz " };
  const string c[9] = { "on " , "yigirma " , "ottiz " , "qirq " , "ellik " , "oltmish " , "yetmish " , "sakson " , "to`qson " };
  const string d[5] = { "yuz " , "ming " , "million " , "milliard " , "trillion " };
  string f[19]; int n, y;
  long double z;

  short int m = 0; back:
  cout << "butun son kiriting: "; cin >> z; a = z;
  if (!(-1000000000000000 < a && a < 1000000000000000))
  {
    cout << "imkoniyatimiz cheklangan\n\n";
    goto back;
  }
  x = 1; n = 0;
  for (int i = 0; i <= 18; i++)
    f[i] = "";
  if (a != 0)
    do
    {
      y = (abs(a) / x) % 10;
      if (y != 0)
        switch (n)
        {
        case 0: f[n] = b[y - 1]; n++; break;
        case 1:
        case 5:
        case 9:
        case 13:
        case 17: f[n] = c[y - 1]; n++; break;
        case 2:
        case 6:
        case 10:
        case 14:
        case 18: f[n] = b[y - 1] + d[0]; n++; break;
        case 3:
          f[n] = d[1]; n++; f[n] = b[y - 1]; n++; break;
        case 7:
          if (f[n - 1] == "" && f[n - 2] == "" && f[n - 3] == "")
            f[n - 4] = "";
          f[n] = d[2]; n++; f[n] = b[y - 1]; n++; break;
        case 11:
          if (f[n - 1] == "" && f[n - 2] == "" && f[n - 3] == "")
            f[n - 4] = "";
          f[n] = d[3]; n++; f[n] = b[y - 1]; n++; break;
        case 15:
          if (f[n - 1] == "" && f[n - 2] == "" && f[n - 3] == "")
            f[n - 4] = "";
          f[n] = d[4]; n++; f[n] = b[y - 1]; n++; break;
        }
      else
        switch (n)
        {
        case 0:
        case 1:
        case 5:
        case 9:
        case 13:
        case 17:
        case 2:
        case 6:
        case 10:
        case 14:
        case 18: n++; break;
        case 3:
          f[n] = d[1]; n += 2; break;
		case 7:
          if (f[n - 1] == "" && f[n - 2] == "" && f[n - 3] == "")
            f[n - 4] = "";
          f[n] = d[2]; n += 2; break;
        case 11:
          if (f[n - 1] == "" && f[n - 2] == "" && f[n - 3] == "")
            f[n - 4] = "";
          f[n] = d[3]; n += 2; break;
        case 15:
          if (f[n - 1] == "" && f[n - 2] == "" && f[n - 3] == "")
            f[n - 4] = "";
          f[n] = d[4]; n += 2; break;
        }
      x *= 10;
    } while (abs(a) / x != 0);
  else
    f[0] = "nol";

  if (a < 0)
    cout << "minus ";
  for (int i = 17; i >= 0; i--)
    f[18] += f[i];
  cout << f[18] << endl;

  m++; back2:
  cout << "\n1: davom ettirish \n2: chiqish \n";
  if (m == 3)
    cout << "3: bizni baholash \n"; cin >> n;
  switch (n)
  {
  case 1:
    if (m == 3)
      m = 0;
    cout << endl; goto back;
  case 2: break;
  case 3:
    if (m == 3)
    {
    back4:
      cout << "\n5 baho \n4 baho \n3 baho \n"; cin >> n;
      switch (n)
      {
      case 5: cout << "sizdan minnaddormiz :)\n"; break;
      case 4: cout << "yanayam yaxshiroq bolishga harakat qilamiz\n"; break;
      case 3: cout << "avfsuz, sizni fikringizni inobatga olamiz\n"; break;
      default: cout << "iltimos bunday baholamang"; goto back4;
      }
      m = 0; goto back2;
    }
    else
      goto back3;
  default: back3: cout << "notogri buyruq"; goto back2;
  }
}

void t_bur_k()
{
  int x[4], y[4];
  bool a[7]; short int n;

  short int m = 0; back:
  cout << "togri tortburchak 3 ta uchi koordinatalarini kiriting\n";
  cout << "x1 = "; cin >> x[0];
  cout << "y1 = "; cin >> y[0];
  cout << endl;
  cout << "x2 = "; cin >> x[1];
  cout << "y2 = "; cin >> y[1];
  cout << endl;
  cout << "x3 = "; cin >> x[2];
  cout << "y3 = "; cin >> y[2];
  cout << endl;

  a[0] = x[0] == x[1] && y[1] == y[2];
  a[1] = x[0] == x[2] && y[2] == y[1];
  a[2] = x[1] == x[2] && y[2] == y[0];
  a[3] = x[1] == x[0] && y[0] == y[2];
  a[4] = x[2] == x[1] && y[1] == y[0];
  a[5] = x[2] == x[0] && y[0] == y[1];
  a[6] = x[0] == x[1] && x[1] == x[2] && y[0] == y[1] && y[1] == y[2];

  if (!(a[0] || a[1] || a[2] || a[3] || a[4] || a[5]) || a[6])
  {
    cout << "koordinatalar notogri\n\n";
    goto back;
  }
  else if (a[0])
  {
    x[3] = x[2]; y[3] = y[0];
  }
  else if (a[1])
  {
    x[3] = x[1]; y[3] = y[0];
  }
  else if (a[2])
  {
    x[3] = x[0]; y[3] = y[1];
  }
  else if (a[3])
  {
    x[3] = x[2]; y[3] = y[1];
  }
  else if (a[4])
  {
    x[3] = x[0]; y[3] = y[2];
  }
  else if (a[5])
  {
    x[3] = x[1]; y[3] = y[2];
  }
  cout << "4-uchi koordinatalari\n";
  cout << "x4 = " << x[3] << endl;
  cout << "y4 = " << y[3] << endl;
  m++; back2:
  cout << "\n1: davom ettirish \n2: chiqish \n";
  if (m == 3)
    cout << "3: bizni baholash \n"; cin >> n;
  switch (n)
  {
  case 1:
    if (m == 3)
      m = 0;
    cout << endl; goto back;
  case 2: break;
  case 3:
    if (m == 3)
    {
    back4:
      cout << "\n5 baho \n4 baho \n3 baho \n"; cin >> n;
      switch (n)
      {
      case 5: cout << "sizdan minnaddormiz :)\n"; break;
      case 4: cout << "yanayam yaxshiroq bolishga harakat qilamiz\n"; break;
      case 3: cout << "avfsuz, sizni fikringizni inobatga olamiz\n"; break;
      default: cout << "iltimos bunday baholamang"; goto back4;
      }
      m = 0; goto back2;
    }
    else
      goto back3;
  default: back3: cout << "notogri buyruq"; goto back2;
  }
}

void shaxmat()
{
  bool c, f[4];
  short int x, y, x2, y2;
  short int n;

  short int m = 0; back:
  cout << "figura joylashgan koordinatalarni kiriting\n";
  cout << "x1 = "; cin >> x;
  cout << "y1 = "; cin >> y;
  if (!(1 <= x && x <= 8) || !(1 <= y && y <= 8))
  {
    cout << "notogri koordinatalar\n";
    goto back;
  }
bak2:
  cout << "figura boradigan koordinatalarni kiriting\n";
  cout << "x2 = "; cin >> x2;
  cout << "y2 = "; cin >> y2;
  if (!(1 <= x2 && x2 <= 8) || !(1 <= y2 && y2 <= 8))
  {
    cout << "notogri koordinatalar\n";
    goto bak2;
  }
  cout << "\nfigurani tanlang\n";
fig:
  cout << "1: ruh \n2: shoh \n3: fil \n4: farzin \n5: ot \n"; cin >> n;
  switch (n)
  {
  case 1:
    c = x == x2 || y == y2; break;
  case 2:
    f[0] = x == x2 && (y == y2 - 1 || y == y2 + 1);
    f[1] = y == y2 && (x == x2 - 1 || x == x2 + 1);
    f[2] = (x == x2 - 1 || x == x2 + 1) && y == y2 - 1;
    f[3] = (x == x2 - 1 || x == x2 + 1) && y == y2 + 1;
    c = f[0] || f[1] || f[2] || f[3]; break;
  case 3:
    c = x2 - y2 == x - y || x2 + y2 == x + y; break;
  case 4:
    c = (x == x2 || y == y2) || (x2 - y2 == x - y || x2 + y2 == x + y); break;
  case 5:
    f[0] = (x == x2 - 1 && y == y2 - 2) || (y == y2 - 1 && x == x2 - 2);
    f[1] = (x == x2 + 1 && y == y2 - 2) || (y == y2 - 1 && x == x2 + 2);
    f[2] = (x == x2 - 2 && y == y2 + 1) || (y == y2 + 2 && x == x2 - 1);
    f[3] = (x == x2 + 2 && y == y2 + 1) || (y == y2 + 2 && x == x2 + 1);
    c = f[0] || f[1] || f[2] || f[3]; break;
  default: cout << "notogri figura\n"; goto fig;
  }
  if (c)
    cout << "figura boroladi\n";
  else
    cout << "figura borolmaydi\n";
  
  m++; back2:
  cout << "\n1: davom ettirish \n2: chiqish \n";
  if (m == 3)
    cout << "3: bizni baholash \n"; cin >> n;
  switch (n)
  {
  case 1:
    if (m == 3)
      m = 0;
    cout << endl; goto back;
  case 2: break;
  case 3:
    if (m == 3)
    {
    back4:
      cout << "\n5 baho \n4 baho \n3 baho \n"; cin >> n;
      switch (n)
      {
      case 5: cout << "sizdan minnaddormiz :)\n"; break;
      case 4: cout << "yanayam yaxshiroq bolishga harakat qilamiz\n"; break;
      case 3: cout << "avfsuz, sizni fikringizni inobatga olamiz\n"; break;
      default: cout << "iltimos bunday baholamang"; goto back4;
      }
      m = 0; goto back2;
    }
    else
      goto back3;
  default: back3: cout << "notogri buyruq"; goto back2;
  }
}

void vaqt()
{
  int a[4];
  long long int q, n;
  short int m = 0; back:
  cout << "vaqt turini tanlang\n";
  cout << "1: sekundda \n2: minutda \n3: soatda \n4: kunda \n"; cin >> n;
  switch (n)
  {
  case 1:
    cout << "vaqtni kiriting(sekund): "; cin >> n;
    a[0] = n / (24 * 3600); q = n % (24 * 3600);
    a[1] = q / 3600; q = q % 3600;
    a[2] = q / 60; a[3] = q % 60;
    cout << n << " sekund = " << a[0] << " kun " << a[1] << " soat " << a[2] << " minut " << a[3] << " sekund\n";
    break;
  case 2:
    cout << "vaqtni kiriting(minut): "; cin >> n;
    a[0] = n / (7 * 24 * 60); q = n % (7 * 24 * 60);
    a[1] = q / (24 * 60); q = q % (24 * 60);
    a[2] = q / 60; a[3] = q % 60;
    cout << n << " minut = " << a[0] << " hafta " << a[1] << " kun " << a[2] << " soat " << a[3] << " minut\n";
    break;
  case 3:
    cout << "vaqtni kiriting(soat): "; cin >> n;
    a[0] = n / (30 * 24); q = n % (30 * 24);
    a[1] = q / (7 * 24); q = q % (7 * 24);
    a[2] = q / 24; a[3] = q % 24;
    cout << n << " soat = " << a[0] << " oy " << a[1] << " hafta " << a[2] << " kun " << a[3] << " soat\n";
    break;
  case 4:
    cout << "vaqtni kiriting(kun): "; cin >> n;
    a[0] = n / 365; q = n % 365;
    a[1] = q / 30; q = q % 30;
    a[2] = q / 7; a[3] = q % 7;
    cout << n << " kun = " << a[0] << " yil " << a[1] << " oy " << a[2] << " hafta " << a[3] << " kun\n";
    break;
  default: cout << "notogri tanlash\n"; goto back;
  }

  m++; back2:
  cout << "\n1: davom ettirish \n2: chiqish \n";
  if (m == 3)
    cout << "3: bizni baholash \n"; cin >> n;
  switch (n)
  {
  case 1:
    if (m == 3)
      m = 0;
    cout << endl; goto back;
  case 2: break;
  case 3:
    if (m == 3)
    {
    back4:
      cout << "\n5 baho \n4 baho \n3 baho \n"; cin >> n;
      switch (n)
      {
      case 5: cout << "sizdan minnaddormiz :)\n"; break;
      case 4: cout << "yanayam yaxshiroq bolishga harakat qilamiz\n"; break;
      case 3: cout << "avfsuz, sizni fikringizni inobatga olamiz\n"; break;
      default: cout << "iltimos bunday baholamang"; goto back4;
      }
      m = 0; goto back2;
    }
    else
      goto back3;
  default: back3: cout << "notogri buyruq"; goto back2;
  }
}

void t_son()
{
  int a[50];
  int n, m, d, x, y;
  short int c, f;

  short int k = 0; back:
  cout << "1: oraliqdagi tub sonlarni aniqlash \n2: sonlar kiritib tubligini aniqlash \n"; cin >> f;
  switch (f)
  {
  case 1:
    cout << "\ntub sonlarni topish nechchidan boshlansin: "; cin >> n;
    cout << "nechchigacha davom etsin: "; cin >> m;
    int bb; d = 0; f = 0; x = min(n, m); y = max(n, m);
    for (int a = x; a <= y; a++)
    {
      c = 0; bb = a / 2;
      for (int b = 1; b <= bb; b++)
      {
        if (a % b == 0)
          c++;
        if (c > 1)
          break;
      }
      if (c == 1)
      {
        cout << a << " "; d++; f++;
      }
      if (f == 15)
      {
        cout << endl; f = 0;
      }
    }
    if (f != 0)
      cout << endl;
    cout << d << " ta tub son bor\n"; break;
  case 2: cas:
    cout << "\nnechta son kiritmoqchisiz: "; cin >> n;
    if (n <= 0)
    {
      cout << "sonlar miqdori musbat(+) bolsin\n";
      goto cas;
    }
    int tt; d = 0; f = 0;
    cout << "sonlarni kiriting\n";
    for (int b = 0; b < n; b++)
      cin >> a[b];

    cout << "tub sonlar:\n";
    for (int b = 0; b < n; b++)
    {
      c = 0; tt = a[b] / 2;
      for (int t = 1; t <= tt; t++)
      {
        if (a[b] % t == 0)
          c++;
        if (c > 1)
          break;
      }
      if (c == 1)
      {
        cout << a[b] << " "; d++; f++;
      }
	  if (f == 15)
      {
        cout << endl; f = 0;
      }
    }
    if (f != 0)
      cout << endl;
    cout << d << " ta tub son bor\n"; break;
  default: cout << "notogri tanlov\n\n"; goto back;
  }
  k++; back2:
  cout << "\n1: davom ettirish \n2: chiqish \n";
  if (k == 3)
    cout << "3: bizni baholash \n"; cin >> f;
  switch (f)
  {
  case 1:
    if (k == 3)
      k = 0;
    cout << endl; goto back;
  case 2: break;
  case 3:
    if (k == 3)
    {
    back4:
      cout << "\n5 baho \n4 baho \n3 baho \n"; cin >> f;
      switch (f)
      {
      case 5: cout << "sizdan minnaddormiz :)\n"; break;
      case 4: cout << "yanayam yaxshiroq bolishga harakat qilamiz\n"; break;
      case 3: cout << "avfsuz, sizni fikringizni inobatga olamiz\n"; break;
      default: cout << "iltimos bunday baholamang"; goto back4;
      }
      k = 0; goto back2;
    }
    else
      goto back3;
  default: back3: cout << "notogri buyruq"; goto back2;
  }
}

void raqam_ch()
{
  int a, b, x;
  short int y, n;
  float z;

  cout << "son kiritish orqali raqamlarini chiqarish\n\n";
back:
  cout << "butun son kiriting\n"; cin >> z; a = z;
  a = abs(a); b = 1;
  do
  {
    b *= 10;
  } while ((a / b) != 0); b /= 10;

  x = 0; n = 0;
  cout << "shu sonning\n";
  do
  {
    y = (a / b) % 10;
    x += y; n++;
    cout << n << "-raqami = " << y << endl;
    b /= 10;
  } while (b != 0);
  cout << "raqamlari yigindisi = " << x << endl;

back2:
  cout << "\n1: davom ettirish \n2: chiqish\n"; cin >> z; n = z;
  switch (n)
  {
  case 1: cout << endl; goto back;
  case 2: break;
  default: cout << "notogri buyruq"; goto back2;
  }
}

int main()
{
  short int b;
  back:
  cout << "asosiy menyudan bolimni tanlang\n\n";
  cout << "1: ikki vektor orasidagi burchak \n2: bank \n3: kvadrat tenglama \n";
  cout << "4: random o`yin \n5: bolinish yoki bolinmaslik \n6: sonning oqilishi \n";
  cout << "7: togri tortburchak koordinatalari \n8: shaxmat figuralari \n9: vaqt \n";
  cout << "10: tub sonlar \n11: sonning raqamlari \n12: /chiqish/ \n";
  cin >> b; cout << endl;
  switch(b)
  {
    case 1: v_burchak(); break;
    case 2: e_bank(); break;
    case 3: k_teng(); break;
    case 4: r_uyin(); break;
    case 5: bulinish(); break;
    case 6: son_yoz(); break;
    case 7: t_bur_k(); break;
    case 8: shaxmat(); break;
    case 9: vaqt(); break;
    case 10: t_son(); break;
    case 11: raqam_ch(); break;
    case 12: goto exit;
    default: cout << "notogri bolim\n"; goto back;
  }
  back2:
  cout << "\n1: asosiy menyuga qaytish \n2: /chiqish/ \n"; cin >> b;
  switch (b)
  {
  case 1: cout << endl; goto back;
  case 2: exit: cout << "dastur tugatildi\n"; break;
  default: cout << "notog`ri buyruq"; goto back2;
  }

  return 0;
}