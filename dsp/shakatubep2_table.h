
// shakatubep2_table generated by DK/tube_table_gen.py -- do not modify manually

struct table1d { // 1-dimensional function table
    float low;
    float high;
    float istep;
    int size;
    float data[];
};

template <int tab_size>
struct table1d_imp {
    float low;
    float high;
    float istep;
    int size;
    float data[tab_size];
    operator table1d&() const { return *(table1d*)this; }
};

static table1d_imp<200> tube_table __rt_data = {
	0,0.810586,49.1003,200, {
	0.000000000000,0.002344463258,0.004723968681,0.007138070971,0.009586377875,
	0.012068552491,0.014584315933,0.017133450428,0.019715802926,0.022331289299,
	0.024979899243,0.027661702031,0.030376853255,0.033125602797,0.035908304261,
	0.038725426222,0.041577565698,0.044465464420,0.047390028612,0.050352353271,
	0.053353752254,0.056395796000,0.059480359437,0.062609683721,0.065786457186,
	0.069013923606,0.072296030376,0.075637637025,0.079044818584,0.082525325428,
	0.086089317392,0.089750617757,0.093529062921,0.097455545808,0.101585581482,
	0.106060388354,0.111330256192,0.116733165977,0.122170206121,0.127639730181,
	0.133140111872,0.138669744917,0.144227042915,0.149810439232,0.155418386929,
	0.161049358703,0.166701846865,0.172374363327,0.178065439615,0.183773626895,
	0.189497496022,0.195235637588,0.200986661997,0.206749199539,0.212521900475,
	0.218303435126,0.224092493974,0.229887787754,0.235688047556,0.241492024923,
	0.247298491952,0.253106241385,0.258914086703,0.264720862210,0.270525423116,
	0.276326645607,0.282123426915,0.287914685368,0.293699360448,0.299476412817,
	0.305244824355,0.311003598171,0.316751758611,0.322488351248,0.328212442872,
	0.333923121454,0.339619496105,0.345300697026,0.350965875439,0.356614203509,
	0.362244874257,0.367857101455,0.373450119517,0.379023183370,0.384575568320,
	0.390106569907,0.395615503748,0.401101705365,0.406564530015,0.412003352515,
	0.417417566984,0.422806586737,0.428169844005,0.433506789737,0.438816893365,
	0.444099642578,0.449354543079,0.454581118336,0.459778909336,0.464947474325,
	0.470086388548,0.475195243985,0.480273649078,0.485321228467,0.490337622705,
	0.495322487989,0.500275495878,0.505196333010,0.510084700820,0.514940315261,
	0.519762906514,0.524552218706,0.529308009629,0.534030050450,0.538718125434,
	0.543372031656,0.547991578722,0.552576588492,0.557126894794,0.561642343157,
	0.566122790528,0.570568105005,0.574978165567,0.579352861802,0.583692093647,
	0.587995771125,0.592263814087,0.596496151953,0.600692723465,0.604853476432,
	0.608978367488,0.613067361852,0.617120433083,0.621137562849,0.625118740698,
	0.629063963825,0.632973236851,0.636846571605,0.640683986905,0.644485508346,
	0.648251168093,0.651981004677,0.655675062792,0.659333393099,0.662956052035,
	0.666543101622,0.670094609284,0.673610647662,0.677091294442,0.680536632176,
	0.683946748114,0.687321734041,0.690661686109,0.693966704682,0.697236894179,
	0.700472362924,0.703673222996,0.706839590086,0.709971583355,0.713069325297,
	0.716132941602,0.719162561031,0.722158315279,0.725120338860,0.728048768979,
	0.730943745416,0.733805410410,0.736633908549,0.739429386656,0.742191993687,
	0.744921880627,0.747619200384,0.750284107699,0.752916759043,0.755517312530,
	0.758085927823,0.760622766049,0.763127989710,0.765601762605,0.768044249748,
	0.770455617286,0.772836032430,0.775185663376,0.777504679236,0.779793249969,
	0.782051546311,0.784279739714,0.786478002281,0.788646506703,0.790785426201,
	0.792894934471,0.794975205625,0.797026414138,0.799048734796,0.801042342647,
	0.803007412948,0.804944121123,0.806852642715,0.808733153341,0.810585828649
	}
};

double always_inline tubeclip(double x) {
    double f = fabs(x);
    f = f * tube_table.istep;
    int i = static_cast<int>(f);
    if (i < 0) {
        f = tube_table.data[0];
    } else if (i >= tube_table.size-1) {
        f = tube_table.data[tube_table.size-1];
    } else {
    f -= i;
    f = tube_table.data[i]*(1-f) + tube_table.data[i+1]*f;
    }
    return copysign(f, x);
}
