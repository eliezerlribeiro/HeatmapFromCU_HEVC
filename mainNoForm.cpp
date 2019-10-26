#include "CreateHeatMap.cpp"

int main(int argc, char* argv[]) {

	if (argc < 13) {
		//printf("Qtd parametro invalidos\n");
		//printf("Parametros : Altura Largura Delimitador ColunaQuadro ColunaX ColunaY ColunaDepth ColunaCalor ValorMinimo ValorMaximo ArqEntrada DirSaida\n");

		return -1;
	}

	CreateHeatMap chmMap;
	chmMap.Height = atoi(argv[1]);
	chmMap.Width = atoi(argv[2]);
	chmMap.Delim = argv[3];
	chmMap.ColFrame = atoi(argv[4]);
	chmMap.ColPosX = atoi(argv[5]);
	chmMap.ColPosY = atoi(argv[6]);
	chmMap.ColDepth = atoi(argv[7]);
	chmMap.DirOut = argv[12];

	chmMap.FileOut = 'Out_' + argv[1] + 'x'+ argv[2] '.yuv';
	chmMap.FileOut = strFileName;
	chmMap.DirOut = msclr::interop::marshal_as<std::string>(pathFolderVideo->Text);

	memoLogger->AppendText("Create HeatMap\n");

	chmMap.LoadHeatMap(argv[11], atoi(argv[8]), atoi(argv[9]), atoi(argv[10]), 1);

	return 0;
}