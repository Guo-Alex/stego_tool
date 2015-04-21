function bigModel = construct_rich_model(path_f12753, path_eraseLSB, path_parity, save_path)
% Constructs parity aware rich model from *.fea files 
% and saves it in [save_path]
% merge fea files from path_f12753, path_eraseLSB, path_parity

if ~isdir(path_f12753) || ~isdir(path_eraseLSB) || ~isdir(path_parity) 
  errorMessage = sprintf('Error: The folder does not exist %s [%s ]%s', path_f12753, path_eraseLSB, path_parity);
  uiwait(warndlg(errorMessage));
  return;
end 

dir_f12753  = dir([path_f12753,'/','*.fea']);
%dir_eraseLSB  = dir([path_eraseLSB,'/','*.fea']);
%dir_parity  = dir([path_parity,'/','*.fea']);

filesCount = length(dir_f12753); 
 
bigModel.F = [];
bigModel.names = {};
bigModel.dimension = 0;

for fileNameIdx=1:filesCount
    fileName = dir_f12753(fileNameIdx).name;
    
    f12753_submodel_file = [path_f12753, '\', fileName];
    eraseLSB_submodel_file = [path_eraseLSB, '\', fileName];
    parity_submodel_file = [path_parity, '\', fileName];
    
    disp(['Begin process submodel [', fileName, ']']);
    
    fea_f12753 = read_fea(f12753_submodel_file);
    fea_eraseLSB = read_fea(eraseLSB_submodel_file);
    fea_parity = read_fea(parity_submodel_file);
     
    if (isempty(bigModel.names))
        bigModel.names = fea_parity.names;
    end
    currentF = [fea_f12753.F, fea_eraseLSB.F, fea_parity.F];
   
    submodel_dim = size(currentF, 2); 
    disp(['Submodel dimension [', num2str(submodel_dim), ']']);    
    bigModel.F = [bigModel.F, currentF];
    
    disp(['Current big model dimension [', num2str(size(bigModel.F,2)), ']']); 
    bigModel.dimension = bigModel.dimension + submodel_dim; 
end
 
disp('##############################################');
disp(['Full dimension:', num2str(bigModel.dimension)]);
  
F = bigModel.F;
names = bigModel.names;
  
save(save_path, 'F', 'names');
disp(['SaveFile to:', save_path]);


end

